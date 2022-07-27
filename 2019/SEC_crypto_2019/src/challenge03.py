#!/usr/bin/env python3
##
## EPITECH PROJECT, 2019
## SEC_crypto_2019
## File description:
## challenge03
##

import tools01
import tools02
tl = tools01

def challenge03():
    tl.check(2)
    hexa = tl.read_file(tl.sys.argv[1])
    txt = bytes.fromhex(hexa)
    res = tools01.singlechar_xor_brute_force(txt)
    print(hex(res['key'])[2:])
    return (0)

challenge03()
