// Student ID   : SLAE-1250
// Student Name : Jonathan "Chops" Crosby
// Assignment 1 : Shell Bind TCP (Linux/x86) Assembly
// File Name    : shellcode.c

#include<stdio.h>
#include<string.h>

//compile with: gcc shellcode.c -o shellcode -fno-stack-protector -z execstack

unsigned char code[] = \
"REPLACE-ME-WITH-YOUR-SHELLCODE";


main()
{

	printf("Shellcode Length:  %d\n", strlen(code));

	int (*ret)() = (int(*)())code;

	ret();

}
