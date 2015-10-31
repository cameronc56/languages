#include "globals.h"



void outb(unsigned short port, unsigned char value) {
        __asm__ (
                "mov AL, [EBP+12]\n"
                "mov DX, [EBP+8]\n"
                "outb DX, AL\n"
       );
}

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

//        unsigned short* displayMemoryPointer = (unsigned short*) 0xB8000;
//        int i;
//        for(i = 0; i < DISPLAY_SIZE - 80; i++) {
//                displayMemoryPointer[i] = displayMemoryPointer[i + 80];
//        }
//        for(i = DISPLAY_SIZE - 1; i > DISPLAY_SIZE - 80; i--) {
//                displayMemoryPointer[i] = 0x0000;
//        }
//}



//void print(char text[]) {
//        static unsigned int currentLocation = 0;
//
//        unsigned short* displayMemoryPtr = (unsigned short*)0xB8000;
//
//        int i;
//        for(i = 0; text[i] != 0; i++) {
//                if(currentLocation == DISPLAY_SIZE) {
//                        shiftTextUpOneLine();
//                        currentLocation -= 80;
//                }
//
//                if(text[i] == '\n') {
//                        currentLocation += (80 - (currentLocation % 80));
//                } else if(text[i] == '\t') {
//                        int spaces;
//                        for(spaces = 0; spaces < 4; spaces++) {
//                                if(currentLocation == DISPLAY_SIZE) {
//                                        shiftTextUpOneLine();
//                                        currentLocation -= 80;
//                                }
//                                displayMemoryPtr[currentLocation++] = (unsigned short)(0x0200 | ' ');
//                        }
//                }
//                else if(text[i] == '\b') {
//                       if(currentLocation > 0) {
//                                displayMemoryPtr[--currentLocation] = (unsigned short)(0x0200 | ' ');
//                        }
//                } else {
//                        displayMemoryPtr[currentLocation++] = (unsigned short)(0x0200 | text[i]);
//                }
//
//                outb(0x3D4, 14);
//                outb(0x3D5, (unsigned char)(currentLocation >> 8));
//                outb(0x3D4, 15);
//                outb(0x3D5, (unsigned char)(currentLocation));
//        }
//}



//void println(char text[]) {
//        print(text);
//        print("\n");
//}
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
void Print(char text[])
{
        static unsigned int CurrentLocation = 0;

        unsigned short* DisplayMemoryPtr = (unsigned short*)0xB8000;

        int i;
        for(i = 0; text[i] != 0; i++)
        {
                if(CurrentLocation == DISPLAY_SIZE)
                {
                        ShiftDisplayUpOneLine();
                        CurrentLocation -= 80;
                }

                if(text[i] == '\n')
                {
                        CurrentLocation += (80 - (CurrentLocation % 80));
                }
    else if(text[i] == '\t')
                {
      int spaces;
      for(spaces = 0; spaces < 4; spaces++)
      {
        if(CurrentLocation == DISPLAY_SIZE)
        {
          ShiftDisplayUpOneLine();
          CurrentLocation -= 80;
        }

        DisplayMemoryPtr[CurrentLocation++] = (unsigned short)(0x0200 | ' ');
      }
                }
                else if(text[i] == '\b')
                {
      if(CurrentLocation > 0)
      {
                          DisplayMemoryPtr[--CurrentLocation] = (unsigned short)(0x0200 | ' ');
      }
                }
                else
                {
                        DisplayMemoryPtr[CurrentLocation++] = (unsigned short)(0x0200 | text[i]);
                }

                outb(0x3D4, 14);
                outb(0x3D5, (unsigned char)(CurrentLocation >> 8));
                outb(0x3D4, 15);
                outb(0x3D5, (unsigned char)(CurrentLocation));
        }
}
void PrintLine(char text[])
{
        Print(text);
        Print("\n");
}

