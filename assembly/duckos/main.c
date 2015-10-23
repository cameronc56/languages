//#include <stdio.h>
#include "globals.h"

//forward declare functions... this normally goes in the header file
void print(char text[]);
void println(char text[]);
void shiftTextUpOneLine();
void delay();

extern unsigned int Page_Table1[1024 * 1024];
extern unsigned int Page_Directory[1024 * 1];
extern unsigned int IDT_Contents;
extern unsigned int IDT_Pointer;

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

	println("Goodbye!");

	// delay loop
	i = 0x0F000000;
	while (i--) {
		;
	}
}
