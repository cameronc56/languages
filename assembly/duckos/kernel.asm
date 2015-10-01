BITS 32

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

_Kernel_Start:

    mov EAX, 0x023E
    mov EBX, 0xB8000 ;start of display
    mov ECX, 2000
print:
    mov word [EBX], AX
    add EBX, 2
    loop print

    jmp _Kernel_Start
