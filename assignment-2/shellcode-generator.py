#!/usr/bin/python

import uuid
import sys
import os

#clear the console
os.system('clear')

if len(sys.argv) != 3:
   
    print "[x] usage: ./poc.py p ip"
    sys.exit(0)


with open('reverse-shell-template.nasm') as f:
    content = f.readlines()

# you may also want to remove whitespace characters like `\n` at the end of each line
content = [x.strip() for x in content] 

insertAt = content.index(";ip-address-before-here")

print insertAt

stuff = sys.argv[2].split('.')

print content

offset = 0

for x in stuff[::-1]:
    if x != '0':
        instruction = "mov byte [esp+" + str(offset) + "], 0x" + str(format(int(x), '02x'))
        content.insert(insertAt, instruction)
        insertAt += 1
    offset += 1

theUUID = uuid.uuid4()



print content
