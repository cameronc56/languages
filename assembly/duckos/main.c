//#include <stdio.h>

//forward declare functions... this normally goes in the header file
void print(char text[]);
void println(char text[]);
void shiftTextUpOneLine();
void delay();

extern unsigned int Page_Table1[1024 * 1024];
extern unsigned int Page_Directory[1024 * 1];
extern unsigned int IDT_Contents;
extern unsigned int IDT_Pointer;

#define DISPLAY_SIZE 2000
#define KERNEL_VIRTUAL_BASE 0xC0000000
#define KERNEL_PAGE_TABLE (KERNEL_VIRTUAL_BASE >> 22)

//for communicating between device (keyboard) and cpu.
void outb(unsigned short port, unsigned char value) {
	__asm__ (
		"mov AL, [EBP+12]\n"
		"mov DX, [EBP+8]\n"
		"outb DX, AL\n"
	);
}





//start interrupts
#define STI \
__asm__\
(\
	"sti\n"\
	"nop\n"\
);

//clear interrupts
#define CLI \
__asm__\
(\
	"cli\n"\
	"nop\n"\
);


typedef struct IDT_ENTRY_s {
	unsigned short handlePointerLow;
	unsigned short selector;
	unsigned char reserved;
	unsigned char gateType: 	4;
	unsigned char storageSegment: 	1;
	unsigned char DPL: 	2;
	unsigned char present: 	1;
	unsigned short handlePointerHigh;
} IDT_Entry_t;

typedef struct IDT_Pointer_s {
	unsigned short tableSize;
	IDT_Entry_t* IDT_Ptr;
} IDT_Pointer_t;


void delay() {
	unsigned int i = 0x400000;
	while(i-- > 0 ){}
}

//COMMON_INTERRUPT_HANDLER goes here

//method to print display color goes here...

//keyboard driver goes here...

//interrupt issuer goes here...

void print(char text[]) {
	static unsigned int currentLocation = 0;
	
	unsigned short* displayMemoryPtr = (unsigned short*)0xB8000;
	
	int i;
	for(i = 0; text[i] != 0; i++) {
		if(currentLocation == DISPLAY_SIZE) {
			shiftTextUpOneLine();
			currentLocation -= 80;
		}
		
		if(text[i] == '\n') {
			currentLocation += (80 - (currentLocation % 80));
		} else if(text[i] == '\t') {
      			int spaces;
      			for(spaces = 0; spaces < 4; spaces++) {
        			if(currentLocation == DISPLAY_SIZE) {
          				shiftTextUpOneLine();
          				currentLocation -= 80;
        			}
       				displayMemoryPtr[currentLocation++] = (unsigned short)(0x0200 | ' ');
    			}
		}
		else if(text[i] == '\b') {
      			if(currentLocation > 0) {
				displayMemoryPtr[--currentLocation] = (unsigned short)(0x0200 | ' ');
    			}
		} else {
			displayMemoryPtr[currentLocation++] = (unsigned short)(0x0200 | text[i]);
		}
		
		outb(0x3D4, 14);
		outb(0x3D5, (unsigned char)(currentLocation >> 8));
		outb(0x3D4, 15);
		outb(0x3D5, (unsigned char)(currentLocation));
	}
}



void println(char text[]) {
	print(text);
	print("\n");
}

void shiftTextUpOneLine() {

	unsigned short* displayMemoryPointer = (unsigned short*) 0xB8000;
	int i;
	for(i = 0; i < DISPLAY_SIZE - 80; i++) {
		displayMemoryPointer[i] = displayMemoryPointer[i + 80];
	}
	for(i = DISPLAY_SIZE - 1; i > DISPLAY_SIZE - 80; i--) {
		displayMemoryPointer[i] = 0x0000;
	}

}



	
void main() {
	// at this point no functions can be called, because they are assigned to virtual memory
	// by the linker. You can call them after setting up paging and after the pageing
	// enabled bit is set in CR0

	unsigned int physicalAddressAndFlags = 7; // 0b111 - Sets page table flags
						  // Present: ON, R/W: ON, User/Supervisor: ON
	unsigned int numberOfPageTables = 4;	  // 
	unsigned int entriesPerPageTable = 1024;  // always 1024 pages
	unsigned int startPageTableEntryIndex = 0;
	unsigned int sizeOfPageTables = numberOfPageTables * entriesPerPageTable;

	unsigned int* Page_Table1_Physical = (unsigned int*)((unsigned int)Page_Table1 - KERNEL_VIRTUAL_BASE);
	unsigned int* Page_Directory_Physical = (unsigned int*)((unsigned int)Page_Directory - KERNEL_VIRTUAL_BASE);

	// set up identity mapping
	unsigned int index = 0;
	while(index < (sizeOfPageTables + startPageTableEntryIndex)) {
		Page_Table1_Physical[index] = physicalAddressAndFlags;    // set physicalAddressAndFlags for page entry
		index += 1; // MAY NEED INDEX = INDEX + 1 ? ....	  // move to next page entry
		physicalAddressAndFlags += 4096; // increment physical address of flags
	}
	// do the same thing as ^ with different index and  startPageTableEntry... need to find out why
	physicalAddressAndFlags = 7;
	index = (KERNEL_PAGE_TABLE  * 1024);
	startPageTableEntryIndex = (KERNEL_PAGE_TABLE * 1024);
	while(index < (sizeOfPageTables + startPageTableEntryIndex)) {
		Page_Table1_Physical[index] = physicalAddressAndFlags;
		index += 1;
		physicalAddressAndFlags += 4096;
	}
	//
	physicalAddressAndFlags = (unsigned int) & Page_Table1_Physical[0];
	physicalAddressAndFlags = physicalAddressAndFlags | 7;
	unsigned int entriesOfPageDirectory = 1024;
	index = 0;
	while(index < entriesOfPageDirectory) {
		Page_Directory_Physical[index] = physicalAddressAndFlags;
		index += 1;
		physicalAddressAndFlags += 4096;
	}
	
	// set virtual addressing via CR3
	__asm__	(
		"lea ECX, [Page_Directory - 0xC0000000]\n"
		"mov CR3, ECX\n"
	);
	// set paging bit via bit 32 of CR0
	__asm__ (
		"mov ECX, CR0\n"
		"or ECX, 0x80000000\n"
		"mov CR0, ECX\n"
	);
	// here and only here we are at PHYSICAL higher half mode
	// now to switch to virtual higher half:
	__asm__ (
		"lea ECX, [StartInHigherHalf]\n"
		"jmp ECX\n"
		"StartInHigherHalf:\n"
		"nop\n"
	);
	// end of setting virtual memory




	unsigned short* displayMemoryPointer = (unsigned short*) 0xB8000;
	unsigned int i = 0;
	while (i < DISPLAY_SIZE) { 
		displayMemoryPointer[i++] = (0x0200 | ' ');
	}
	//printf("HELLO WORLD\n");
	// libc not working...

	print("Hello World!");
	println("Hello, again!");
	println("Hello, again!");
	println("Hello, again!");
	println("Hello, again!");
	println("Hello, again!");
	println("Hello, again!");
	println("Hello, again!");
	println("Hello, again!");
	println("Hello, again!");
	println("Hello, again!");
	println("Hello, again!");
	println("Hello, again!");
	println("Hello, again!");
	println("Hello, again!");
	println("Hello, again!");
	println("Hello, again!");
	println("Hello, again!");
	println("Hello, again!");
	println("Hello, again!");
	println("Hello, again!");
	println("Hello, again!");
	println("Hello, again!");
	println("Hello, again!");
	println("Hello, again!");
	println("Hello, again!");

	println("Goodbye!");

	outb(0x3D4, 14);
	outb(0x3D5, 0x00);
	outb(0x3D4, 15);
	outb(0x3D4, 0x50);


	// delay loop
	i = 0x0F000000;
	while (i--) {
		;
	}
}
