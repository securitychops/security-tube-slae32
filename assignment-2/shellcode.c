// Student ID   : SLAE-1250
// Student Name : Jonathan "Chops" Crosby
// Assignment 2 : Reverse Shell TCP (Linux/x86) C variant
// File Name    : shellcode.c

#include<stdio.h>
#include<string.h>

//compile with: gcc shellcode.c -o shellcode -fno-stack-protector -z execstack

unsigned char code[] = \
"REPLACE WITH GENERATED shellcode!!!!!!!!!!!!!!oneoneonetwo";

main()
{

	printf("Shellcode Length:  %d\n", strlen(code));

	int (*ret)() = (int(*)())code;

	ret();

}
