#!/usr/bin/env python3

def get_english_score(input):
    result = 0
    etaoin_shrdlu = {
        'a': 0.0651738, 'b': 0.0124248, 'c': 0.0217339, 'd': 0.0349835, 'e': 0.1041442, 'f': 0.0197881, 'g': 0.0158610,
        'h': 0.0492888, 'i': 0.0558094, 'j': 0.0009033, 'k': 0.0050529, 'l': 0.0331490, 'm': 0.0202124, 'n': 0.0564513,
        'o': 0.0596302, 'p': 0.0137645, 'q': 0.0008606, 'r': 0.0497563, 's': 0.0515760, 't': 0.0729357, 'u': 0.0225134,
        'v': 0.0082903, 'w': 0.0171272, 'x': 0.0013692, 'y': 0.0145984, 'z': 0.0007836, ' ': 0.1918182
    }
    for i in input:
        result += etaoin_shrdlu.get(chr(i).lower(), 0)
    return (result)

def xor_english_score(encoded, key):
    output = b''
    for i in encoded:
        output += bytes([i ^ key])
    return (get_english_score(output))

def xor_score(encoded, key):
    print(encoded)
    output = b''
    for i in encoded:
        output += bytes([i ^ key])
    return (get_english_score(output), output)

def uncrypt(encoded):
    key = 0
    score = 0
    res = 0
    while (key < 255):
        tmp = xor_score(bytes.fromhex(encoded), key)
        if (tmp[0] > score):
            score = tmp[0]
            res = key
        key += 1
    return (res, score)

def search_xor(f):
    result = 0
    score = 0
    i = 0
    while (i < 255):
        tmp = xor_english_score(f, i)
        if (tmp > score):
            score = tmp
            result = i
        i += 1
    return (result)