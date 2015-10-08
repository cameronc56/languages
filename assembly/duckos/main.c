//#include <stdio.h>

//forward declare functions... this normally goes in the header file
void print(char text[]);
void println(char text[]);
void shiftTextUpOneLine();
void delay();

#define DISPLAY_SIZE 2000

extern unsigned int Page_Table[1024 * 1024];
extern unsigned int Page_Directory[1024 * 1];

void delay() {
	unsigned int i = 99999999;
	while(i-- > 0 ){}
}



void main() {
	// at this point no functions can be called, because they are assigned to virtual memory
	// by the linker. You can call them after setting up paging and after the pageing
	// enabled bit is set in CR0








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
	// delay loop
	i = 0x0F000000;
	while (i--) {
		;
	}
}

void print(char text[]) {
	unsigned short* displayMemoryPointer = (unsigned short*) 0xB8000;
	static unsigned int currentLocation = 0;
	int i;
	for(i = 0; text[i] != 0; i++) {

		if(currentLocation == DISPLAY_SIZE) {
			shiftTextUpOneLine();
			currentLocation -= 80;
		}

		if(text[i] == '\n') {
			currentLocation += (80 - (currentLocation % 80));
		} else {
			displayMemoryPointer[currentLocation++] = (unsigned short)(0x0200 | text[i]);
		}
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



	
