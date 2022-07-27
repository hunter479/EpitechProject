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

def detect_encrypted_text(encrypted_strings):
    candidates = []

    for string, line in encrypted_strings:
        candidates.append([tl.singlechar_xor_brute_force(string), line])
    return sorted(candidates, key=lambda tup: tup[0]['score'], reverse=True)[0]

def challenge04():
    tl.check(2)
    arr = tl.read_file(tl.sys.argv[1]).split('\n')
    tbytes = []
    line = 0
    for i in arr:
        tbytes.append([bytes.fromhex(i), line + 1])
        line += 1
    res = detect_encrypted_text(tbytes)
    print(res[1], hex(res[0]['key'])[2:])

challenge04()