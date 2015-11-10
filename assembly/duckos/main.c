//includes
#include "helpers.c"
#include "IssueInterrupt.c"
#include "CommonInterruptHandler.c"		//keyboard map
#include "CommonInterruptHandlerExtern.c"
#include "IDTSetup.c"


//main.h
void itoa(int i, char *p);
void PrintLine(char text[]);


extern unsigned int Page_Table[1024 * 1024];	// # of entries/page table * total # of page tables
												//		actual size = 4194304 bytes = 4MiB, represents 4GiB in physical memory (size of unsigned int = 4 bytes)
												//		ie. each 4 byte entry represent 4 KiB in physical memory
extern unsigned int Page_Directory[1024 * 1];  	// # of pages tables * # of directory (4096 bytes = 4 KiB)


#define KERNEL_VIRTUAL_BASE 0xC0000000					// Constant declaring base of Higher-half kernel (from Kernel.asm)
#define KERNEL_PAGE_TABLE (KERNEL_VIRTUAL_BASE >> 22)	// Constant declaring Page Table index in virtual memory (from Kernel.asm)

#define DISPLAY_SIZE 2000 // 2000 = 80 x 25 Characters - VGA Text-mode Display size

void outb(unsigned short port, unsigned char value) 
{
	__asm__
	(
		"mov AL, [ebp+12]\n"
		"mov DX, [ebp+8]\n"
		"outb DX, AL\n"
	);
}

#define STI \
__asm__\
( \
	"sti\n"\
	"nop\n"\
);

#define CLI \
__asm__\
( \
	"cli\n"\
	"nop\n"\
);



void Delay()
{
	unsigned int i = 0x400000;
	while(i-- > 0) {}
}

void DisplayColourArea(unsigned char BackgroundColour, unsigned char ForegroundColour, unsigned int start, unsigned int length)
{
	unsigned char Colour;
	Colour = ((BackgroundColour << 4) & 0xF0) | (ForegroundColour & 0x0F);
	unsigned short* DisplayMemoryPtr = (unsigned short*)0xB8000; 
	unsigned int i = start;
	while(i < DISPLAY_SIZE && i < start + length)
	{
		DisplayMemoryPtr[i++] = (((unsigned short)Colour) << 8) | 0x00;
	}
}
void DisplayColour(unsigned char BackgroundColour, unsigned char ForegroundColour)
{
	DisplayColourArea(BackgroundColour, ForegroundColour, 0, DISPLAY_SIZE);
	Delay();
}

void ShiftDisplayUpOneLine()
{
	unsigned short* DisplayMemoryPtr = (unsigned short*)0xB8000;
	unsigned int i;
	for(i = 0; i < DISPLAY_SIZE - 80; i++) 
	{
		DisplayMemoryPtr[i] = DisplayMemoryPtr[i + 80];
	}
	for(i = DISPLAY_SIZE - 1; i > DISPLAY_SIZE - 80; i--)
	{
		DisplayMemoryPtr[i] = 0x0000;
	}
}
void Print(char text[], int isCommand) {
	isCommand = 1; //default value
	static unsigned int CurrentLocation = 0;
	
	unsigned short* DisplayMemoryPtr = (unsigned short*)0xB8000;
	
	int i;
	for(i = 0; text[i] != 0; i++) {
		if(CurrentLocation == DISPLAY_SIZE) {
			ShiftDisplayUpOneLine();
			CurrentLocation -= 80;
		}
		
		if(text[i] == '\n' && isCommand == 1) {

			char textEnteredOnLastLine[80];
			int i;
			for(i = 0; i < 80; i++) {
				textEnteredOnLastLine[i] = DisplayMemoryPtr[CurrentLocation - (CurrentLocation % 80) + i];
			}

			//TODO
			//create another file
			//with a function, that can parse the text entered on the last line
			//much better, and then pass it off to the appropriate commands function.

			if( textEnteredOnLastLine[0] == 'q' &&
				textEnteredOnLastLine[1] == 'u' &&
				textEnteredOnLastLine[2] == 'a' &&
				textEnteredOnLastLine[3] == 'c' &&
				textEnteredOnLastLine[4] == 'k' &&
				textEnteredOnLastLine[5] == ' '
			  ) {
			  		char textToQuack[74];
			  		int i;
					for(i = 0; i < 74; i++) {
						textToQuack[i] = textEnteredOnLastLine[i + 6];
					}
					CurrentLocation += (80 - (CurrentLocation % 80));
					Print(textToQuack, 0);
			}

			CurrentLocation += (80 - (CurrentLocation % 80));




		} else if(text[i] == '\t') {
      int spaces;
      for(spaces = 0; spaces < 4; spaces++) {
        if(CurrentLocation == DISPLAY_SIZE) {
          ShiftDisplayUpOneLine();
          CurrentLocation -= 80;
        }
        
        DisplayMemoryPtr[CurrentLocation++] = (unsigned short)(0x0200 | ' ');
      }
		}
		else if(text[i] == '\b') {
      		if((CurrentLocation % 80) > 0) {	//stops user from backspacing to line above current
				DisplayMemoryPtr[--CurrentLocation] = (unsigned short)(0x0200 | ' ');
    		}
		}
		else {
			DisplayMemoryPtr[CurrentLocation++] = (unsigned short)(0x0200 | text[i]);
		}
		
		outb(0x3D4, 14);
		outb(0x3D5, (unsigned char)(CurrentLocation >> 8));
		outb(0x3D4, 15);
		outb(0x3D5, (unsigned char)(CurrentLocation));
	}
}
void PrintLine(char text[]) {
	Print(text, 0);
	Print("\n", 0);
}

void main() {
	// DisplayColour and Delay methods cannot be used until virtual addressing is set up i.e. until PG bit of CR0 is on.
	// Use inline assembly colour method for debugging.
	// This is because until virtual addressing is set up, code is only accessible through physical addresses but method calls 
	// are based on virtual addresses (because of the link script).
	
	unsigned int PhysicalAddressAndFlags = 7; 	// ; 0b111 - Setting Page Table flags (Present: ON, Read/Write: ON, User/Supervisor: ON)
	unsigned int NoOfPageTables = 4; 			// 4 is arbitrary to cover 16MiB
	unsigned int EntriesPerPageTable = 1024;	// There is always 1024 pages (4KiB/Page)
	unsigned int StartPageTableEntryIndex = 0;
	unsigned int SizeOfPageTables = NoOfPageTables * EntriesPerPageTable;
	
	unsigned int index = 0;
	
	unsigned int* Page_Table_Physical = (unsigned int*)((unsigned int)Page_Table - KERNEL_VIRTUAL_BASE);
	unsigned int* Page_Directory_Physical = (unsigned int*)((unsigned int)Page_Directory - KERNEL_VIRTUAL_BASE);
	
	//Setting up identity mapping
	while(index < (SizeOfPageTables + StartPageTableEntryIndex)) {
		Page_Table_Physical[index] = PhysicalAddressAndFlags;
		index = index + 1;
		PhysicalAddressAndFlags = PhysicalAddressAndFlags + 4096;
	}
	
	PhysicalAddressAndFlags = 7;
	index = (KERNEL_PAGE_TABLE * 1024);
	StartPageTableEntryIndex = (KERNEL_PAGE_TABLE * 1024);
	
	while(index < (SizeOfPageTables + StartPageTableEntryIndex))
	{
		Page_Table_Physical[index] = PhysicalAddressAndFlags;
		index = index + 1;
		PhysicalAddressAndFlags = PhysicalAddressAndFlags + 4096;
	}
	
	PhysicalAddressAndFlags = (unsigned int)&Page_Table_Physical[0];
	PhysicalAddressAndFlags = PhysicalAddressAndFlags | 7;	//0b111 - Setting Page Table flags (Present: ON, Read/Write: ON, User/Supervisor: ON)
	
	unsigned int EntriesOfPageDirectory = 1024;
	index = 0; 	// Setting index to 0 to be used with Page Directory
	
	while(index < EntriesOfPageDirectory)
	{	
		Page_Directory_Physical[index] = PhysicalAddressAndFlags;
		index = index + 1;	// Move to next entry in Page Directory (4 bytes down)
		PhysicalAddressAndFlags = PhysicalAddressAndFlags + 4096; 	// Update physical address to which to set the next Page Directory entry to (4 KiB down)
	}
	   
	// Set virtual addressing via control register CR3 
	// high 20 bits is Page directory Base Register i.e physical address of first page directory entry
	__asm__ 
	(
		"lea ECX, [Page_Directory - 0xC0000000]\n" // 0xC0000000 = KERNEL_VIRTUAL_BASE
		"mov CR3, ECX\n"
	);	
	
	// Switch on paging via control register CR0
	__asm__ 
	(
		"mov ECX, CR0\n"
		"or ECX, 0x80000000\n"	// Set PG bit in CR0 to enable paging.
		"mov CR0, ECX\n"
	);

	// At only this point we are in physical higher-half mode

	// Jump to higher-half
	__asm__
	(
		"lea ECX, [StartInHigherHalf]\n"
		"jmp ECX\n"
		"StartInHigherHalf:\n"
		"nop\n"
	);
		
	//DisplayColour(0x3, 0xF);	// DisplayColour can also be used for debugging
	; // END - Set Virtual Memory
	


	IDTSetupWrapper();



	__asm__
	(
		"lea EAX, [IDT_Pointer]\n"  // Load address of (/pointer to) IDT pointer structure
		"lidt [EAX]\n"						// Load IDT register with pointer to IDT pointer structure
	);
	
	// END - Interrupt descriptor Table setup
	
	// BEGIN - PIC setup and remap
	
	// Remap IRQs 0-7    to    ISRs 32-39
	// and   IRQs 8-15   to    ISRs 40-47
	outb(0x20, 0x11);
	outb(0xA0, 0x11);
	
	outb(0x21, 0x20);
	outb(0xA1, 0x28);
	
	outb(0x21, 0x04);
	outb(0xA1, 0x02);
	
	outb(0x21, 0x01);
	outb(0xA1, 0x01);
	
	outb(0x21, 0xFF);
	outb(0xA1, 0xFF);

	STI
		
	// END - PIC setup and remap
	
	// BEGIN - Configure PIT (The Timer)
	CLI
	
	__asm__
	(
		"in AL, 0x21\n"
		"and AL, 0xFC\n" // Also enables keyboard interrupt (IRQ 1)
		"out 0x21, AL\n"
	);
	
	outb(0x43, 0x34);
	outb(0x40, 0xFF);
	outb(0x40, 0xFF);
	
	STI
	// END - Configure PIT (The Timer)

	while(1)
	{
    	;
	}
}
