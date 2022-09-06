#include <stdio.h>
#include <stdlib.h>
#include "Fila.h"
#include "Pilha.h"

struct fila {
    Pilha* P1;
    Pilha* P2;
    int Max;
};

Fila* Fila_inicia ( int Max ) {
    Fila* f = (Fila*) calloc(1, sizeof(Fila));
    f->P1 = Pilha_inicia( );
    f->P2 = Pilha_inicia( );
    f->Max = Max;

    return f;
}

void Fila_insere ( Fila* f, Aluno* aluno ) {
    //verificar se tem espaco na fila
    if( Pilha_num_elementos( f->P1) >= f->Max || !f ){
        printf("Fila invalida ou cheia!\n");
    }

    while( !Pilha_esta_vazia( f->P1 )) {
        Pilha_push( f->P2, Pilha_pop( f->P1 ));
    }
    Pilha_push( f->P2, aluno );

    while ( !Pilha_esta_vazia( f->P2) ){
        Pilha_push( f->P1, Pilha_pop( f->P2 ));
    }
    
}

Aluno* Fila_retira ( Fila* f ) {
    if( Pilha_esta_vazia(f->P2) || !f ){
        printf("Fila invalida ou vazia!\n");
    }
    
    while( !Pilha_esta_vazia( f->P2 )) {
        Pilha_push( f->P1, Pilha_pop( f->P2 ));
    }
    
    Aluno* aluno = Pilha_pop( f->P1 );

    while ( !Pilha_esta_vazia( f->P1) ){
        Pilha_push( f->P2, Pilha_pop( f->P1 ));
    }

    return aluno;
}

void Fila_imprime( Fila* f ) {

    while( !Pilha_esta_vazia( f->P1 )) {
        Pilha_push( f->P2, Pilha_pop( f->P1 ));
    }

    Pilha_imprime( f->P2 );
}

void Fila_destroi( Fila *f ) {
    Pilha_destroi( f->P1 );
    Pilha_destroi( f->P2 );

    free( f );
}
