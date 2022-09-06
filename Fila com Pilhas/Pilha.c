#include <stdio.h>
#include <stdlib.h>
#include "Pilha.h"

#define MaxTam 1000

struct pilha {
    Aluno* alunos[MaxTam];
    int Topo;
    int Max;
};


Pilha* Pilha_inicia () {
    
    Pilha* p = (Pilha*) calloc (1, sizeof(Pilha));
    p->Topo = 0;
    p->Max = MaxTam;

    return p;
}

//inclui no topo
void Pilha_push ( Pilha* p, Aluno* a ) {

    if( !p || !a || p->Topo >= MaxTam ) {
        printf("Pilha ou aluno invalido(s) ou Pilha cheia!\n");
    }

    p->alunos[p->Topo] = a;
    p->Topo++;
}

//retira no topo
Aluno* Pilha_pop( Pilha* p ) {

    if( !p || Pilha_esta_vazia( p ) ) {
        printf("Pilha vazia!\n");
        return NULL;
    }

    Aluno* aluno = p->alunos[p->Topo-1];
    p->Topo--;

    return aluno;
}

int Pilha_esta_vazia( Pilha* p ) {

    if( p->Topo == 0 )
        return 1;
    else
        return 0;
}

int Pilha_num_elementos( Pilha* p ) {
    return p->Topo;
}

void Pilha_imprime( Pilha* p ) {

    if( !p ) {
        printf("Pilha invalida!\n");
        return;
    }

    for( int i = (p->Topo-1); i >= 0; i-- ){
        Imprime_aluno(p->alunos[i]);
    }
}

void Pilha_destroi( Pilha* p ) {
    if( !p ) {
        printf("Pilha invalida!\n");
        return;
    }

    free( p );
}

