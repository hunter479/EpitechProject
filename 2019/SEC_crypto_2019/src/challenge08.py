#!/usr/bin/env python3
##
## EPITECH PROJECT, 2019
## SEC_crypto_2019
## File description:
## challenge07
##

from Crypto.Cipher.AES import block_size
import base64
import tools01
import tools02
tl = tools01

def get_n_b64_to_hex():
    k = tl.read_file(tl.sys.argv[1]).split('\n')
    arr = []
    for s in k:
        s = (base64.b64decode(s))
        arr += [s]
    return (arr)

def count_ecb_rep(ciphertext):
    chunks = [ciphertext[i:i + block_size] for i in range(0, len(ciphertext), block_size)]
    number_of_duplicates = len(chunks) - len(set(chunks))
    return (number_of_duplicates)

def detect_ecb_encrypted_ciphertext(k):
    best = (0, 0)
    for i in range(len(k)):
        repetitions = count_ecb_rep(k[i])
        best = max(best, (i, repetitions), key=lambda t: t[1])
    return (best)

def challenge08():
    tl.check(2)
    result = detect_ecb_encrypted_ciphertext(get_n_b64_to_hex())
    print(result[0] + 1)

challenge08()