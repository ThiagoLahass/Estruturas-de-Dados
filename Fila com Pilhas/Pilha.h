#ifndef PILHA_H
#define PILHA_H

#include "aluno.h"

typedef struct pilha Pilha;

Pilha* Pilha_inicia ();

//inclui no topo
void Pilha_push ( Pilha* p, Aluno* a );

//retira no topo
Aluno* Pilha_pop( Pilha* p );

int Pilha_esta_vazia( Pilha* p );

int Pilha_num_elementos( Pilha* p );

void Pilha_imprime( Pilha* p );

void Pilha_destroi( Pilha* p );


#endif