/*
** EPITECH PROJECT, 2019
** NWP_mychap_2018
** File description:
** sha256
*/

#include <openssl/sha.h>
#include "myserver.h"

uint8_t *do_sha(const char *answer, const char *password)
{
    SHA256_CTX ctx;
    u_int8_t results[SHA256_DIGEST_LENGTH];
    char tmp[SHA256_DIGEST_LENGTH];
    uint8_t *ret = NULL;

    if (!answer || !password)
        return (NULL);
    SHA256_Init(&ctx);
    SHA256_Update(&ctx, answer, strlen(answer));
    SHA256_Update(&ctx, password, strlen(password));
    SHA256_Final(results, &ctx);
    ret = malloc(sizeof(char) * (SHA256_DIGEST_LENGTH * 2) + 1);
    memset(ret, 0, sizeof(char) * (SHA256_DIGEST_LENGTH * 2) + 1);
    for (int n = 0; n < SHA256_DIGEST_LENGTH; n++) {
        sprintf(tmp, "%02x", results[n]);
        ret = (u_int8_t *)strcat((char *)ret, tmp);
    }
    return (ret);
}
