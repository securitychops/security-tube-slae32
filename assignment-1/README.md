1. Run ./shellcode-generator.py PortNumber
    - (ie ./shellcode-generator.py 4444)
  
2. Paste shellcode into shellcode.c

3. compile with: gcc shellcode.c -o shellcode -fno-stack-protector -z execstack

4. ./shellcode

5. nc -nv ipaddress-of-host port-number

6. done
