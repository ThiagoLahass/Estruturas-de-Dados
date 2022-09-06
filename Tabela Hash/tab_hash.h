#ifndef TABHASH_H
#define TABHASH_H

#include "palavra.h"

typedef struct tabHash TabHash;


TabHash* tabHash_inicializa ( int tamanho );

Palavra* tabHash_adiciona_palavra ( TabHash* h, char* str );

int tabHash_num_palavras ( TabHash* h );

void tabHash_imprime ( TabHash* h );

void tabHash_libera ( TabHash* h );

#endif