#!/usr/bin/env python3
##
## EPITECH PROJECT, 2019
## src
## File description:
## challenge04
##

import tools01
import tools02
tl = tools01

def decrypt(encoded_byte, key_byte):
    a = int(encoded_byte, 16)
    b = int(key_byte, 16)
    return (hex(a ^ b)[2:])

def challenge05():
    j = 0
    res = ""
    tl.check(2)
    file = tl.read_file(tl.sys.argv[1]).split("\n")
    key = file[0]
    encoded = file[1]
    tl.isHex(key)
    tl.isHex(encoded)
    for i in range(0, len(encoded)):
        res = res + decrypt(encoded[i], key[j])
        j += 1
        if (j >= len(key)):
            j = 0
    print(res.upper())

challenge05()
