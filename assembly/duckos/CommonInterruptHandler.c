void outb(unsigned short port, unsigned char value);
void Print(char text[], int isCommand);
void itoa(int i, char *p);

void CommonInterruptHandler(int handlerNum) {
  static char shiftPressed = 0;
  static char ctrlPressed = 0;
  static char altPressed = 0;

  unsigned char scanCode;

	//DisplayColourArea(0xF, 0xF, handlerNum, 1);
	//Delay();
	//DisplayColourArea(0x0, 0xF, handlerNum, 1);

	if(handlerNum == 33) {
    /* Note: If you add or remove local variables to/from this method or change
             any function calls (including adding/removing arguments) you must
             update the EBP-9 value below.

             Uncomment the line of code following this paragraph. Recompile and
             then inspect the main.s assembly code file outputted by the compiler.
             Search for "CommonInterruptHandler:" then scroll down to
             "inb AL, 0x60" and look at the line of code above which sets the
             local variable. Update the asm following this comment appropriately.

      scanCode = -1;

    */

		__asm__
		(
			"inb AL, 0x60\n"
            "mov byte ptr [EBP-9], al\n"
		);

    unsigned int shiftedScanCode;
    unsigned char processChar = 1;
    unsigned char released = (scanCode & 0x80);
    if(released) {
      scanCode ^= 0x80;
    }

    shiftedScanCode = scanCode;
    switch (shiftedScanCode) {
      //Left and right shift keys
      case 0x36:
      case 0x2A: {
          shiftPressed = !released;
          processChar = 0;
          break;
      }
      //Ctrl key
      case 0x1D: {
          ctrlPressed = !released;
          processChar = 0;
          break;
      }
      //Alt key
      case 0x38: {
          altPressed = !released;
          processChar = 0;
          break;
      }
      //All other keys
      default:
        {
          //If the key was just pressed, enqueue it
          if (!released) {
            //If shift pressed, adjust the scancode appropriately.
            if (shiftPressed) {
                if(shiftedScanCode >= 0x47 && shiftedScanCode <= 0x53) {
                    //dont do anything with shift key on numpad;
                } else {
                     shiftedScanCode = shiftedScanCode << 16;
                }
            }
          }
          else {
            processChar = 0;
          }
        }
        break;
    }

    if(processChar) {
      char character[2];
      switch (shiftedScanCode) {
        case 0x10: character[0] = 'q'; break;
        case 0x100000: character[0] = 'Q'; break;
        case 0x11: character[0] = 'w'; break;
        case 0x110000: character[0] = 'W'; break;
        case 0x12: character[0] = 'e'; break;
        case 0x120000: character[0] = 'E'; break;
        case 0x13: character[0] = 'r'; break;
        case 0x130000: character[0] = 'R'; break;
        case 0x14: character[0] = 't'; break;
        case 0x140000: character[0] = 'T'; break;
        case 0x15: character[0] = 'y'; break;
        case 0x150000: character[0] = 'Y'; break;
        case 0x16: character[0] = 'u'; break;
        case 0x160000: character[0] = 'U'; break;
        case 0x17: character[0] = 'i'; break;
        case 0x170000: character[0] = 'I'; break;
        case 0x18: character[0] = 'o'; break;
        case 0x180000: character[0] = 'O'; break;
        case 0x19: character[0] = 'p'; break;
        case 0x190000: character[0] = 'P'; break;

        case 0x1E: character[0] = 'a'; break;
        case 0x1E0000: character[0] = 'A'; break;
        case 0x1F: character[0] = 's'; break;
        case 0x1F0000: character[0] = 'S'; break;
        case 0x20: character[0] = 'd'; break;
        case 0x200000: character[0] = 'D'; break;
        case 0x21: character[0] = 'f'; break;
        case 0x210000: character[0] = 'F'; break;
        case 0x22: character[0] = 'g'; break;
        case 0x220000: character[0] = 'G'; break;
        case 0x23: character[0] = 'h'; break;
        case 0x230000: character[0] = 'H'; break;
        case 0x24: character[0] = 'j'; break;
        case 0x240000: character[0] = 'J'; break;
        case 0x25: character[0] = 'k'; break;
        case 0x250000: character[0] = 'K'; break;
        case 0x26: character[0] = 'l'; break;
        case 0x260000: character[0] = 'L'; break;

        case 0x2C: character[0] = 'z'; break;
        case 0x2C0000: character[0] = 'Z'; break;
        case 0x2D: character[0] = 'x'; break;
        case 0x2D0000: character[0] = 'X'; break;
        case 0x2E: character[0] = 'c'; break;
        case 0x2E0000: character[0] = 'C'; break;
        case 0x2F: character[0] = 'v'; break;
        case 0x2F0000: character[0] = 'V'; break;
        case 0x30: character[0] = 'b'; break;
        case 0x300000: character[0] = 'B'; break;
        case 0x31: character[0] = 'n'; break;
        case 0x310000: character[0] = 'N'; break;
        case 0x32: character[0] = 'm'; break;
        case 0x320000: character[0] = 'M'; break;

        case 0x29: character[0] = '`'; break;
        case 0x290000: character[0] = '?'; break;
        case 0x2: character[0] = '1'; break;
        case 0x20000: character[0] = '!'; break;
        case 0x3: character[0] = '2'; break;
        case 0x30000: character[0] = '"'; break;
        case 0x4: character[0] = '3'; break;
        case 0x40000: character[0] = '?'; break;
        case 0x5: character[0] = '4'; break;
        case 0x50000: character[0] = '$'; break;
        case 0x6: character[0] = '5'; break;
        case 0x60000: character[0] = '%'; break;
        case 0x7: character[0] = '6'; break;
        case 0x70000: character[0] = '^'; break;
        case 0x8: character[0] = '7'; break;
        case 0x80000: character[0] = '&'; break;
        case 0x9: character[0] = '8'; break;
        case 0x90000: character[0] = '*'; break;
        case 0xA: character[0] = '9'; break;
        case 0xA0000: character[0] = '('; break;
        case 0xB: character[0] = '0'; break;
        case 0xB0000: character[0] = ')'; break;

        case 0x27: character[0] = ';'; break;
        case 0x270000: character[0] = ':'; break;
        case 0x28: character[0] = '\''; break;
        case 0x280000: character[0] = '@'; break;
        case 0x2B: character[0] = '#'; break;
        case 0x2B0000: character[0] = '~'; break;
        case 0x33: character[0] = ','; break;
        case 0x330000: character[0] = '<'; break;
        case 0x34: character[0] = '.'; break;
        case 0x340000: character[0] = '>'; break;
        case 0x35: character[0] = '/'; break;
        case 0x350000: character[0] = '?'; break;
        case 0x0C: character[0] = '-'; break;
        case 0x0C0000: character[0] = '_'; break;
        case 0x0D: character[0] = '='; break;
        case 0x0D0000: character[0] = '+'; break;
        case 0x1A: character[0] = '['; break;
        case 0x1A0000: character[0] = '{'; break;
        case 0x1B: character[0] = ']'; break;
        case 0x1B0000: character[0] = '}'; break;

        case 0x0E: character[0] = '\b'; break; //Backspace
        case 0x0F: character[0] = '\t'; break; //Tabulator
        case 0x1C: character[0] = '\n'; break; //Enter
        case 0x39: character[0] = ' '; break;  //Space

        case 0x0E0000: character[0] = '\b'; break; //Backspace (with shift)
        case 0x0F0000: character[0] = '\t'; break; //Tabulator (with shift)
        case 0x1C0000: character[0] = '\n'; break; //Enter (with shift)
        case 0x390000: character[0] = ' '; break;  //Space (with shift)

        //numpad (
        case 0x52: character[0] = '0'; break;
        case 0x4F: character[0] = '1'; break;
        case 0x50: character[0] = '2'; break;
        case 0x51: character[0] = '3'; break;
        case 0x4B: character[0] = '4'; break;
        case 0x4C: character[0] = '5'; break;
        case 0x4D: character[0] = '6'; break;
        case 0x47: character[0] = '7'; break;
        case 0x48: character[0] = '8'; break;
        case 0x49: character[0] = '9'; break;

        case 0x37: character[0] = '*'; break;
        case 0x4A: character[0] = '-'; break;
        case 0x4E: character[0] = '+'; break;
        case 0x53: character[0] = '.'; break;

        default: character[0] = '?';
          int keyboardCode = shiftedScanCode;
          char output[33];
          itoa(shiftedScanCode, output);
          Print(output, 1);
          Print(" ", 1);
		break;
      }

      character[1] = 0;

      Print(character, 1);

    }
  }

	if(handlerNum >= 32 && handlerNum < 48) {
		//DisplayColourArea(0x4, 0xF, handlerNum, 1);

		if(handlerNum >= 40) {
			outb(0xA0, 0x20);
		}
		outb(0x20, 0x20);

		//DisplayColourArea(0x5, 0xF, handlerNum, 1);
	}
}

