To compile crypter:
 - gcc crypter.c aes.c -o crypter
 
Take shellcode output and insert it into decrypter.c

To compile decrypter:
 - gcc decrypter.c aes.c -o decrypter -fno-stack-protector -z execstack
 
 Run ./decrypter
 
 Bask in the glory of the /bin/sh prompt!
