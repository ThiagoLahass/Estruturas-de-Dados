#ifndef FILA_H
#define FILA_H

#include "Pilha.h"

typedef struct fila Fila;

Fila* Fila_inicia ();

void Fila_insere ( Fila* f, Aluno* aluno );

Aluno* Fila_retira ( Fila* f );

void Fila_imprime( Fila* f );

void Fila_destroi( Fila *f );

#endif