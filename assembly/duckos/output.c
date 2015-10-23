#include "globals.h"



void outb(unsigned short port, unsigned char value) {
        __asm__ (
                "mov AL, [EBP+12]\n"
                "mov DX, [EBP+8]\n"
                "outb DX, AL\n"
        );
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
