#!/usr/bin/env python3
##
## EPITECH PROJECT, 2019
## SEC_crypto_2019
## File description:
## challenge01
##

from base64 import b64encode, b64decode
from tools01 import read_file, check, sys

def challenge01():
    check(2)
    f = read_file(sys.argv[1])
    b16 = bytes.fromhex(f)
    b64 = b64encode(b16)
    print(b64.decode())
    return (0)

exit(challenge01())