	.file	"main.c"
	.intel_syntax noprefix
	.text
	.globl	delay
	.type	delay, @function
delay:
.LFB0:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	mov	DWORD PTR [rbp-4], 99999999
	nop
.L2:
	mov	eax, DWORD PTR [rbp-4]
	lea	edx, [rax-1]
	mov	DWORD PTR [rbp-4], edx
	test	eax, eax
	jne	.L2
	pop	rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	delay, .-delay
	.section	.rodata
.LC0:
	.string	"Hello World!"
.LC1:
	.string	"Hello, again!"
.LC2:
	.string	"Goodbye!"
	.text
	.globl	main
	.type	main, @function
main:
.LFB1:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	sub	rsp, 64
	mov	DWORD PTR [rbp-4], 7
	mov	DWORD PTR [rbp-16], 4
	mov	DWORD PTR [rbp-20], 1024
	mov	DWORD PTR [rbp-24], 0
	mov	eax, DWORD PTR [rbp-16]
	imul	eax, DWORD PTR [rbp-20]
	mov	DWORD PTR [rbp-28], eax
	mov	eax, OFFSET FLAT:Page_Table1
	add	eax, 1073741824
	mov	eax, eax
	mov	QWORD PTR [rbp-40], rax
	mov	eax, OFFSET FLAT:Page_Directory
	add	eax, 1073741824
	mov	eax, eax
	mov	QWORD PTR [rbp-48], rax
	mov	DWORD PTR [rbp-8], 0
	jmp	.L4
.L5:
	mov	eax, DWORD PTR [rbp-8]
	lea	rdx, [0+rax*4]
	mov	rax, QWORD PTR [rbp-40]
	add	rdx, rax
	mov	eax, DWORD PTR [rbp-4]
	mov	DWORD PTR [rdx], eax
	add	DWORD PTR [rbp-8], 1
	add	DWORD PTR [rbp-4], 4096
.L4:
	mov	edx, DWORD PTR [rbp-28]
	mov	eax, DWORD PTR [rbp-24]
	add	eax, edx
	cmp	eax, DWORD PTR [rbp-8]
	ja	.L5
	mov	DWORD PTR [rbp-4], 7
	mov	DWORD PTR [rbp-8], 786432
	mov	DWORD PTR [rbp-24], 786432
	jmp	.L6
.L7:
	mov	eax, DWORD PTR [rbp-8]
	lea	rdx, [0+rax*4]
	mov	rax, QWORD PTR [rbp-40]
	add	rdx, rax
	mov	eax, DWORD PTR [rbp-4]
	mov	DWORD PTR [rdx], eax
	add	DWORD PTR [rbp-8], 1
	add	DWORD PTR [rbp-4], 4096
.L6:
	mov	edx, DWORD PTR [rbp-28]
	mov	eax, DWORD PTR [rbp-24]
	add	eax, edx
	cmp	eax, DWORD PTR [rbp-8]
	ja	.L7
	mov	rax, QWORD PTR [rbp-40]
	mov	DWORD PTR [rbp-4], eax
	or	DWORD PTR [rbp-4], 7
	mov	DWORD PTR [rbp-52], 1024
	mov	DWORD PTR [rbp-8], 0
	jmp	.L8
.L9:
	mov	eax, DWORD PTR [rbp-8]
	lea	rdx, [0+rax*4]
	mov	rax, QWORD PTR [rbp-48]
	add	rdx, rax
	mov	eax, DWORD PTR [rbp-4]
	mov	DWORD PTR [rdx], eax
	add	DWORD PTR [rbp-8], 1
	add	DWORD PTR [rbp-4], 4096
.L8:
	mov	eax, DWORD PTR [rbp-8]
	cmp	eax, DWORD PTR [rbp-52]
	jb	.L9
#APP
# 66 "main.c" 1
	lea ECX, [Page_Directory - 0xC0000000]
mov CR3, ECX

# 0 "" 2
# 71 "main.c" 1
	mov ECX, CR0
or ECX, 0x80000000
mov CR0, ECX

# 0 "" 2
# 78 "main.c" 1
	lea ECX, [StartInHigherHalf]
jmp ECX
StartInHigherHalf:
nop

# 0 "" 2
#NO_APP
	mov	QWORD PTR [rbp-64], 753664
	mov	DWORD PTR [rbp-12], 0
	jmp	.L10
.L11:
	mov	eax, DWORD PTR [rbp-12]
	lea	edx, [rax+1]
	mov	DWORD PTR [rbp-12], edx
	mov	eax, eax
	lea	rdx, [rax+rax]
	mov	rax, QWORD PTR [rbp-64]
	add	rax, rdx
	mov	WORD PTR [rax], 544
.L10:
	cmp	DWORD PTR [rbp-12], 1999
	jbe	.L11
	mov	edi, OFFSET FLAT:.LC0
	call	print
	mov	edi, OFFSET FLAT:.LC1
	call	println
	mov	edi, OFFSET FLAT:.LC1
	call	println
	mov	edi, OFFSET FLAT:.LC1
	call	println
	mov	edi, OFFSET FLAT:.LC1
	call	println
	mov	edi, OFFSET FLAT:.LC1
	call	println
	mov	edi, OFFSET FLAT:.LC1
	call	println
	mov	edi, OFFSET FLAT:.LC1
	call	println
	mov	edi, OFFSET FLAT:.LC1
	call	println
	mov	edi, OFFSET FLAT:.LC1
	call	println
	mov	edi, OFFSET FLAT:.LC1
	call	println
	mov	edi, OFFSET FLAT:.LC1
	call	println
	mov	edi, OFFSET FLAT:.LC1
	call	println
	mov	edi, OFFSET FLAT:.LC1
	call	println
	mov	edi, OFFSET FLAT:.LC1
	call	println
	mov	edi, OFFSET FLAT:.LC1
	call	println
	mov	edi, OFFSET FLAT:.LC1
	call	println
	mov	edi, OFFSET FLAT:.LC1
	call	println
	mov	edi, OFFSET FLAT:.LC1
	call	println
	mov	edi, OFFSET FLAT:.LC1
	call	println
	mov	edi, OFFSET FLAT:.LC1
	call	println
	mov	edi, OFFSET FLAT:.LC1
	call	println
	mov	edi, OFFSET FLAT:.LC1
	call	println
	mov	edi, OFFSET FLAT:.LC1
	call	println
	mov	edi, OFFSET FLAT:.LC1
	call	println
	mov	edi, OFFSET FLAT:.LC1
	call	println
	mov	edi, OFFSET FLAT:.LC2
	call	println
	mov	DWORD PTR [rbp-12], 251658240
	nop
.L12:
	mov	eax, DWORD PTR [rbp-12]
	lea	edx, [rax-1]
	mov	DWORD PTR [rbp-12], edx
	test	eax, eax
	jne	.L12
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	main, .-main
	.globl	print
	.type	print, @function
print:
.LFB2:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	sub	rsp, 32
	mov	QWORD PTR [rbp-24], rdi
	mov	QWORD PTR [rbp-16], 753664
	mov	DWORD PTR [rbp-4], 0
	jmp	.L14
.L18:
	mov	eax, DWORD PTR currentLocation.1788[rip]
	cmp	eax, 2000
	jne	.L15
	mov	eax, 0
	call	shiftTextUpOneLine
	mov	eax, DWORD PTR currentLocation.1788[rip]
	sub	eax, 80
	mov	DWORD PTR currentLocation.1788[rip], eax
.L15:
	mov	eax, DWORD PTR [rbp-4]
	movsx	rdx, eax
	mov	rax, QWORD PTR [rbp-24]
	add	rax, rdx
	movzx	eax, BYTE PTR [rax]
	cmp	al, 10
	jne	.L16
	mov	esi, DWORD PTR currentLocation.1788[rip]
	mov	ecx, DWORD PTR currentLocation.1788[rip]
	mov	edx, -858993459
	mov	eax, ecx
	mul	edx
	shr	edx, 6
	mov	eax, edx
	sal	eax, 2
	add	eax, edx
	sal	eax, 4
	sub	ecx, eax
	mov	edx, ecx
	mov	eax, esi
	sub	eax, edx
	add	eax, 80
	mov	DWORD PTR currentLocation.1788[rip], eax
	jmp	.L17
.L16:
	mov	eax, DWORD PTR currentLocation.1788[rip]
	lea	edx, [rax+1]
	mov	DWORD PTR currentLocation.1788[rip], edx
	mov	eax, eax
	lea	rdx, [rax+rax]
	mov	rax, QWORD PTR [rbp-16]
	add	rax, rdx
	mov	edx, DWORD PTR [rbp-4]
	movsx	rcx, edx
	mov	rdx, QWORD PTR [rbp-24]
	add	rdx, rcx
	movzx	edx, BYTE PTR [rdx]
	movsx	dx, dl
	or	dh, 2
	mov	WORD PTR [rax], dx
.L17:
	add	DWORD PTR [rbp-4], 1
.L14:
	mov	eax, DWORD PTR [rbp-4]
	movsx	rdx, eax
	mov	rax, QWORD PTR [rbp-24]
	add	rax, rdx
	movzx	eax, BYTE PTR [rax]
	test	al, al
	jne	.L18
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	print, .-print
	.section	.rodata
.LC3:
	.string	"\n"
	.text
	.globl	println
	.type	println, @function
println:
.LFB3:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	sub	rsp, 16
	mov	QWORD PTR [rbp-8], rdi
	mov	rax, QWORD PTR [rbp-8]
	mov	rdi, rax
	call	print
	mov	edi, OFFSET FLAT:.LC3
	call	print
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3:
	.size	println, .-println
	.globl	shiftTextUpOneLine
	.type	shiftTextUpOneLine, @function
shiftTextUpOneLine:
.LFB4:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	mov	QWORD PTR [rbp-16], 753664
	mov	DWORD PTR [rbp-4], 0
	jmp	.L21
.L22:
	mov	eax, DWORD PTR [rbp-4]
	cdqe
	lea	rdx, [rax+rax]
	mov	rax, QWORD PTR [rbp-16]
	add	rdx, rax
	mov	eax, DWORD PTR [rbp-4]
	cdqe
	add	rax, 80
	lea	rcx, [rax+rax]
	mov	rax, QWORD PTR [rbp-16]
	add	rax, rcx
	movzx	eax, WORD PTR [rax]
	mov	WORD PTR [rdx], ax
	add	DWORD PTR [rbp-4], 1
.L21:
	cmp	DWORD PTR [rbp-4], 1919
	jle	.L22
	mov	DWORD PTR [rbp-4], 1999
	jmp	.L23
.L24:
	mov	eax, DWORD PTR [rbp-4]
	cdqe
	lea	rdx, [rax+rax]
	mov	rax, QWORD PTR [rbp-16]
	add	rax, rdx
	mov	WORD PTR [rax], 0
	sub	DWORD PTR [rbp-4], 1
.L23:
	cmp	DWORD PTR [rbp-4], 1920
	jg	.L24
	pop	rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE4:
	.size	shiftTextUpOneLine, .-shiftTextUpOneLine
	.local	currentLocation.1788
	.comm	currentLocation.1788,4,4
	.ident	"GCC: (Ubuntu 4.9.2-10ubuntu13) 4.9.2"
	.section	.note.GNU-stack,"",@progbits
