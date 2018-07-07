1. Compile crypter:
     - gcc crypter.c aes.c -o crypter
 
2. Take shellcode output and insert it into decrypter.c

3. Compile decrypter:
     - gcc decrypter.c aes.c -o decrypter -fno-stack-protector -z execstack
 
4. Run ./decrypter
 
5. Bask in the glory of the /bin/sh prompt!
