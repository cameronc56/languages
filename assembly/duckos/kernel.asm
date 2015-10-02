BITS 32 ; 32 bit kernel

GLOBAL _Kernel_Start:function

SECTION .text

; BEGIN - Multiboot Header
MultibootSignature dd 464367618
MultibootFlags dd 3
MultibootChecksum dd -464367621
MultibootGraphicsRuntime_VbeModeInfoAddr dd 2147483647
MultibootGraphicsRuntime_VbeControlInfoAddr dd 2147483647
MultibootGraphicsRuntime_VbeMode dd 2147483647
MultibootInfo_Memory_High dd 0
MultibootInfo_Memory_Low dd 0
; END - Multiboot Header

MultibootInfo_Structure dd 0

; TODO 
; 0. clear interrupts flag				DONE
; 1. allocate stack					DONE
; 2. start segmentation in GDT				
; 3. Tell CPU about multiboot				
; 4. switch to protected mode				
; 5. set the stack pointer				
; 6. Tell CPU about GDT					
; 7. Halt the CPU					
; 8. Jump to C, rewrite screen output code in C		



Kernel_Stack_End:    ; <- assembly 'label'. is initiated as an address in memory.
    TIMES 65535 db 0 ; repeats db 0 65535 times. 65535 is binary 1111111111111111 and hex 0xFFFF
                     ;db declares initialized data in the output file.
Kernel_Stack_Start:  ; inits to 0x0000

_Kernel_Start:
    
    cli ; CLear Interrupts. This sets the IF (Interrupt Flag) to 0 in x86 FLAGS register. When set to 0, 
        ; maskable hardware interrupts will be ignored.

    mov EAX, 0x023F  ; 16 bits saved in the 32 bit register. 0 = black bg, 2 = green fg, 3F = ? char. 
    mov EBX, 0xB8000 ; start of display
    mov ECX, 2000    ; size of standard vga display, 25x80, so loop output to screen 2000x

print:
    mov word [EBX], AX ; AX is the first 16 bits of EAX, [EBX] references memory location
    add EBX, 2         ; moves to the next location on the screen
    loop print         ; loops 2000x (value of ECX)

    jmp _Kernel_Start
