#ifndef BLOWFISHP_H_
#define BLOWFISHP_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct blowfishp_context_t_ {
	unsigned int pbox[256];
	unsigned int sbox[4][256];
} blowfishp_context_t;

int blowfishp_initiate(blowfishp_context_t *ctx, unsigned char *key, int keybytes);
void blowfishp_encryptblock(blowfishp_context_t *ctx, unsigned int *hi, unsigned int *lo);
void blowfishp_decryptblock(blowfishp_context_t *ctx, unsigned int *hi, unsigned int *lo);
#endif
