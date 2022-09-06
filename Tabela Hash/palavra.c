#include "palavra.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct palavra{
    char* string;
    int frequencia;
    struct palavra * prox;
};

Palavra* palavra_inicializa ( char* str ) {
    Palavra* palavra = (Palavra*) calloc(1, sizeof(Palavra));
    palavra->string = strdup( str );
    palavra->frequencia = 0;
    palavra->prox = NULL;

    return palavra;
}

char* palavra_retorna_string ( Palavra* palavra ) {
    return palavra->string;
}

int palavra_retorna_num_ocorrencias ( Palavra* palavra ) {
    return palavra->frequencia;
}

void palavra_incrementa_num_ocorrencia( Palavra* palavra ){
    palavra->frequencia++;
}

//busca a palavra na tabela de colisao
Palavra* palavra_busca ( Palavra* lista, char* str ) {
    Palavra* aux;

    for( aux = lista; aux != NULL; aux = aux->prox ) {
        if ( strcmp( aux->string, str ) == 0 ) {
            return aux;
        }
    }

    return NULL;
}

//insere a palavra na tabela de colisao
Palavra* palavra_insere ( Palavra* lista, Palavra* palavra ) {
    if( lista == NULL ) {
        lista = palavra;
    }
    else {
        Palavra* aux;
        aux = lista;
        palavra->prox = aux;
        lista = palavra;
    }

    return lista;
}

Palavra* palavra_retorna_prox ( Palavra* palavra ) {
    if( palavra->prox != NULL ){
        return palavra->prox;
    }

    return NULL;
}

int palavra_num_palavras ( Palavra* lista ){
    Palavra* aux;
    int i = 0;
    for( aux = lista; aux != NULL; aux = aux->prox ) {
        i++;
    }

    return i;
}

void palavra_imprime_lista ( Palavra* lista ){
    Palavra* aux;

    for( aux = lista; aux != NULL; aux = aux->prox ) {
        printf("String: %s\nOcorrencias: %d\n\n", aux->string, aux->frequencia );
    }
}

void palavra_libera_lista ( Palavra* lista ) {
    Palavra* aux1 = lista, *aux2;

    while( aux1 != NULL ) {
        aux2 = aux1->prox;
        free( aux1->string );
        free( aux1 );
        aux1 = aux2;
    }
}
