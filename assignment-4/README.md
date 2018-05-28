1. Run ./generate-shellcode.py
2. Paste encoded shellcode into custom-encoder.nasm
3. Assemble custom-encoder.nasm with ./compile custom-encoder
4. Objdump custom-encoder shellcode
5. Paste dumped shellcode into shellcode.c
6. Compile
7. Run ./shellcode
