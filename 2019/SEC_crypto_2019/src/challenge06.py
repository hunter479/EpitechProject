#!/usr/bin/env python3
##
## EPITECH PROJECT, 2019
## SEC_crypto_2019
## File description:
## challenge06
##

import tools01
import tools02
tl = tools01

def doCalc(s1, s2, key):
    res = float(0)
    res = tl.hamming_distance(tl.single_xor_byte(s1, key), tl.single_xor_byte(s2, key))
    res /= key
    return res

def get_KeySize(coded):
    tmp = float(10000)
    lower = float(10000)
    key = 0
    cypher = bytes.fromhex(coded)
    for n in range(5, 40):
        tmpA = cypher[:n - len(cypher)]
        tmpB = cypher[n:(n * 2) - len(cypher)]
        if (len(tmpA) == len(tmpB) and len(tmpB) != 0):
            tmp = doCalc(tmpA, tmpB, n)
            if (tmp < lower):
                lower = tmp
                key = n
    return (key)

def cut_code(coded, key_size):
    ar = []
    i = 0
    x = 0
    while (i < key_size):
        ar.append(bytes.fromhex(coded[x:(key_size + x) - len(coded)]))
        x += key_size
        i += 1
    return (ar)

def get_xor(ar, key):
    finalKey = b''
    tmp = b''
    i = 0
    while (i < (key / 2)):
        for x in ar:
            tmp += bytes([x[i]])
        finalKey += bytes([tools02.search_xor(tmp)])
        tmp = b''
        i += 1
    return(finalKey.hex().upper())

def challenge06():
    tl.check(2)
    coded = tl.read_file(tl.sys.argv[1])
    key = get_KeySize(coded)
    ar = cut_code(coded, key)
    print(get_xor(ar, key))
    return (0)

challenge06()
