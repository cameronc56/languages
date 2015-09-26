.386
.model flat, stdcall
option casemap :none
include \masm32\include\windows.inc
include \masm32\include\kernel32.inc
include \masm32\include\user32.inc
include \masm32\include\masm32.inc
includelib \masm32\lib\kernel32.lib
includelib \masm32\lib\user32.lib
includelib \masm32\include\masm32.lib
.data
 HelloWorld db "Hello World!", 0
.code

;windowed version
start:
 invoke MessageBox, NULL, addr HelloWorld, addr HelloWorld, MB_OK
 invoke ExitProcess, 0
end start 

;console version
;start:
; invoke StdOut, addr HelloWorld
; invoke ExitProcess, 0
;end start

;to compile the console version
;1. download MASM (assembler)
;2. compile: "\masm32\bin\ml /c /Zd /coff HelloWorld.asm"
;3. and link: "\masm32\bin\Link /SUBSYSTEM:CONSOLE HelloWorld.obj"

;to compile the windowed version, replace CONSOLE with WINDOWS