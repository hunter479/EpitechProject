#!/usr/bin/env python3
##
## EPITECH PROJECT, 2019
## SEC_crypto_2019
## File description:
## challenge02
##

import tools01
tl = tools01

def strcmp(str1, str2):
    if (len(str1) == len(str2)):
        return (0)
    else:
        return (1)

def to_hex(str):
    return int(str, base = 16)

def fix_xor(str1, str2):
    tl.isHex(str1)
    tl.isHex(str2)
    a = to_hex(str1)
    b = to_hex(str2)
    result = hex(a ^ b)
    return (result[2:]) #[2:] skip les 2 premiers char

def challenge02():
    tl.check(2)
    content = tl.read_file(tl.sys.argv[1])
    array = content.split('\n')
    if (strcmp(array[0], array[1]) != 0):
        return (84)
    else:
        print(fix_xor(array[0], array[1]).upper())
        return (0)

exit(challenge02())