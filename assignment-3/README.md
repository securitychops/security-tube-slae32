1. Generate Linux/x86 shellcode
2. Paste shellcode into shellcode.c
3. Prepend \xFC\xFC\xFC\xFC\xFC\xFC\xFC\xFC to the shellcode
4. Compile with: gcc shellcode.c -o shellcode -fno-stack-protector -z execstack
5. Run  ./shellcode
