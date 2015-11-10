BITS 32 

GLOBAL _Kernel_Start:function
GLOBAL IDT_Contents:data
GLOBAL IDT_Pointer:data

KERNEL_VIRTUAL_BASE equ 0xC0000000
KERNEL_PAGE_TABLE equ (KERNEL_VIRTUAL_BASE >> 22)

EXTERN main	; link to main.c

SECTION .text


; BEGIN - Multiboot Header
MultibootSignature dd 464367618 ; Decimal for 0x1BADB002
MultibootFlags dd 3		; Specifies page-aligned (4KB) loading
MultibootChecksum dd -464367621 ; Checksum for config
MultibootGraphicsRuntime_VbeModeInfoAddr dd 2147483647
MultibootGraphicsRuntime_VbeControlInfoAddr dd 2147483647
MultibootGraphicsRuntime_VbeMode dd 2147483647
MultibootInfo_Memory_High dd 0	; allocate memory for multiboot vars
MultibootInfo_Memory_Low dd 0
MultibootInfo_Structure dd 0
; END - Multiboot Header

; TODO 
; 0. clear interrupts flag				DONE
; 1. allocate stack					DONE
; 2. alloc segmentation for GDT				DONE			
; 3. Tell CPU about multiboot				DONE	
; 4. switch to protected mode				DONE
; 5. set the stack pointer				DONE
; 6. Tell CPU about GDT					DONE
; 7. Halt the CPU					DONE				
; 8. Jump to C, rewrite screen output code in C		DONE
; 9. Create TSS Segment and initiate it			
; 10. set up paging					DONE
; 11. enable paging in CR0				DONE
; 12. set up virtual addressing				DONE
; 13. jump to a higher half kernel			DONE
; 14. create interrupt handlers

Kernel_Stack_End:    ; <- assembly 'label'. is initiated as an address in memory.
    TIMES 65535 db 0 ; repeats db 0 65535 times. 65535 is binary 1111111111111111 and hex 0x0000FFFF
                     ;db declares initialized data (byte) in the output file.
Kernel_Stack_Start:  ; inits to 0x00000000


; Create GDT (Global Descriptor Table)
GDT_Contents:
; x86 processors expect GDT to exist. The bootloader (isolinux) will contain
; a default GDT, but the OS will not know where it is, and may accidentally overwrite it, causing 
; a triple fault (Computer shuts down immediately).
;
; Fill GDT Table Entries (with GDT Descriptors)
; Code and data selectors first then TSS (Task State Segment)
; Format: Limit (size), Limit, Base (Address/Offset), Base, Base, Access (Permissions),
; Limit cont. + Flags (4 bits each), Base (continued).
; 0x9- = Kernel Mode, 0xF- = User Mode, 0x-A = Executable, Readable, Writable, 0x-2 = R/W
; 0xC- = flags =  32 bit mode, and 4KiB (all 32 bits) units for limit values.
db 0, 0, 0, 0, 0, 0, 0, 0		; NULL Descriptor (Required). It is a protection mechanism.
db 255, 255, 0, 0, 0, 0x9A, 0xCF, 0	; Offset: 8 - KM Code Selector
db 255, 255, 0, 0, 0, 0x92, 0xCF, 0	; Offset: 16 - KM Data Selector
db 255, 255, 0, 0, 0, 0xFA, 0xCF, 0	; Offset: 24 - UM Code Selector
db 255, 255, 0, 0, 0, 0xF2, 0xCF, 0	; Offset: 32 - UM Data Selector
; TODO: Make TSS Segment. Reminder: Then GDT_Pointer first byte will need to be increased by 8
; Create the GDT Pointer
GDT_Pointer db 39, 0, 0, 0, 0, 0	; first two bytes are length(in bytes) of GDT table - 1,
					; followed by 4 bytes specifying the address of the GDT table.


IDT_Contents: TIMES 2048 db 0	    ; allocate table memory
IDT_Pointer db 0xFF, 0x7, 0, 0, 0,0 ; 0x7FF = 2047 = 2048 - 1


_Kernel_Start:
    
    cli ; CLear Interrupts. This sets the IF (Interrupt Flag) to 0 in x86 FLAGS register. When set to 0
        ; maskable hardware interrupts will be ignored.


    ; A multiboot compliant loader puts info in cpu registers:
    ; EBX = Multiboot info structure pointer
    ; EAX = 0x2BADB002 
    ; Check for multiboot:
    mov dword ECX, 0x2BADB002	; multiboot magic number
    cmp ECX, EAX		; compare
    jne (HandleNoMultiboot - KERNEL_VIRTUAL_BASE)	; jump if not equals

    ; Fill vars with Multiboot structure info:
    mov dword [MultibootInfo_Structure - KERNEL_VIRTUAL_BASE], EBX	;
    add dword EBX, 0x4				; increment by 4 bits
    mov dword EAX, [EBX]			;
    mov dword [MultibootInfo_Memory_Low - KERNEL_VIRTUAL_BASE], EAX	;
    mov dword EBX, 0x4				; increment by 4 bits
    mov dword EAX, [EBX]			;
    mov dword [MultibootInfo_Memory_High - KERNEL_VIRTUAL_BASE], EAX	;

    ; Switch to protected mode
    mov dword EAX, CR0	; CR0 cannot be modified directly, it must be moved to a register
    or EAX, 1		; where the protected mode bit is set
    mov dword CR0, EAX	; and then moved back

    ; Set Stack Pointer
    mov dword ESP, (Kernel_Stack_Start - KERNEL_VIRTUAL_BASE)	; ESP = Stack Pointer

    ; tell cpu about GDT
    mov dword [GDT_Pointer - KERNEL_VIRTUAL_BASE + 2], (GDT_Contents - KERNEL_VIRTUAL_BASE)	; move the GDT table next to the GDT Pointer
    mov dword EAX, (GDT_Pointer	- KERNEL_VIRTUAL_BASE)		; move to register
    lgdt [EAX]					; load GDT

    ; set data segments
    mov dword EAX, 0x10
    mov word DS, EAX
    mov word ES, EAX
    mov word FS, EAX
    mov word GS, EAX
    mov word SS, EAX
    
    ; force reload of CS (code segment)
    jmp 8:(boot_flushCsGDT - KERNEL_VIRTUAL_BASE)
boot_flushCsGDT:

PrintToScreen:
    mov EAX, 0x0200  ; 16 bits saved in the 32 bit register. 0 = black bg, 2 = green fg, 3F = ? char. 
    mov EBX, 0xB8000 ; start of display
    mov ECX, 2000    ; VGA Text-Mode Display Size, 25x80, so loop output to screen 2000x

    print:
        mov word [EBX], AX ; AX is the first 16 bits of EAX, [EBX] references memory location
        add EBX, 2         ; moves to the next location on the screen
    loop print             ; loops 2000x (value of ECX)

; call main.c
CallMain:
	lea EAX, [main - KERNEL_VIRTUAL_BASE]
	call EAX	; call c function
	jmp Halt


; BEGIN - Interrupt Handler Macro       
EXTERN CommonInterruptHandler

%macro CommonInterruptHandlerMacro 1
GLOBAL CommonInterruptHandler%1:function
CommonInterruptHandler%1:
        pushad

        push dword %1
        call CommonInterruptHandler
        add esp, 4

        popad

    IRet
%endmacro
%assign HandlerNum 0
%rep 256
    CommonInterruptHandlerMacro HandlerNum
    %assign HandlerNum HandlerNum+1
%endrep
; END - Interrupt Handler Macro




HandleNoMultiboot:
    ; Output following text to first bit of vid mem
    ; N  o      M   u   l   t   i   b  o   o   t
    ; 78 111 32 109 117 108 116 105 98 111 111 116
    mov byte [0xB8000], 78
    mov byte [0xB8002], 111
    mov byte [0xB8004], 32
    mov byte [0xB8006], 109
    mov byte [0xB8008], 117
    mov byte [0xB800A], 108
    mov byte [0xB800C], 116
    mov byte [0xB800E], 105
    mov byte [0xB8010], 98
    mov byte [0xB8012], 111
    mov byte [0xB8014], 111
    mov byte [0xB8016], 116

    ; Set the colour of the outputted text to:
    ; Red background (0x4-), 
    ; White foreground (0x-F)
    mov dword eax, 0x4F
    mov byte [0xB8001], al
    mov byte [0xB8003], al
    mov byte [0xB8005], al
    mov byte [0xB8007], al
    mov byte [0xB8009], al
    mov byte [0xB800B], al
    mov byte [0xB800D], al
    mov byte [0xB800F], al
    mov byte [0xB8011], al
    mov byte [0xB8013], al
    mov byte [0xB8015], al
    mov byte [0xB8017], al
    jmp Halt

Halt:
    cli		; ignore maskable interrupts
    hlt		; halt the cpu (hlt is broken by interrupts)
    jmp Halt	; re-halt if a non-maskable interrupt occurs

SECTION .bss

GLOBAL Page_Table:data
GLOBAL Page_Directory:data

align 4096
Page_Table: resb(1024 * 4 * 1024)	; reserve space for page table
Page_Directory: resb (1024 * 4 * 1) ;	; reserve space for page directory
