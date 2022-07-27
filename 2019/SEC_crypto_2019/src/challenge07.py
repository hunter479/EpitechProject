#!/usr/bin/env python3
##
## EPITECH PROJECT, 2019
## SEC_crypto_2019
## File description:
## challenge07
##

import base64
import tools01
tl = tools01

def challenge07():
    tl.check(2)
    k = tl.read_file(tl.sys.argv[1]).split('\n')
    tl.isHex(k[0])
    text = tl.decrypt_aes_ecb(bytes.fromhex(k[0]), base64.b64decode(k[1]))
    text = tl.unpadding(text)
    print(base64.b64encode(text).decode())
    return (0)

challenge07()