#!/usr/bin/env python3
##
## EPITECH PROJECT, 2019
## SEC_crypto_2019
## File description:
## tools01
##

import sys
from tools02 import get_english_score
from Crypto.Cipher import AES

def read_file(path):
    try:
        f = open(path, "r")
        content = f.read()
        f.close()
        if (len(content) == 0):
            print("File is empty")
            exit(84)
        return (content)
    except FileNotFoundError:
        print("File not found")
        exit(84)
    except IOError:
        print("File not accessible")
        exit(84)

def check(nbFile):
    if (len(sys.argv) != nbFile):
        print("Error dans le nombre d'arguments")
        exit(84)
    else:
        return (0)

def isHex(c):
    if (len(c) % 2 != 0):
        print("Error: string is not hex")
        exit(84)
    try:
        int(c, 16)
    except ValueError:
        print("Error: string is not hex")
        exit(84)
    return (0)

def hamming_distance(s1, s2):
    dst = 0
    for b1, b2 in zip(s1, s2):
        difference = b1 ^ b2
        dst += sum([1 for bit in bin(difference) if bit == '1'])
    return dst

def padding(s, l):
    i = 0
    while (i < l - len(s)):
        s += chr(3)
    return (s)

def unpadding(message):
    last_char = bytes([message[-1]])
    if last_char.decode() < chr(32):
        return message.rstrip(last_char)
    else:
        return message

def decrypt_aes_ecb(key, cipher):
    decipher = AES.new(key, AES.MODE_ECB)
    text = decipher.decrypt(cipher)
    return (text)

def single_xor_byte(f, key):
    output = b''
    for i in f:
        output += bytes([i ^ key])
    return (output)

def singlechar_xor_brute_force(cipher):
    arr = []

    for key in range(256):
        txt = single_xor_byte(cipher, key)
        candidate_score = get_english_score(txt)
        result = {
            'key': key,
            'score': candidate_score,
            'text': txt
        }
        arr.append(result)
    return sorted(arr, key=lambda c: c['score'], reverse=True)[0]
