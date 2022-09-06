#include "tab_hash.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tabHash
{
    Palavra** vetor;
    int tamanho;
};


//FUNCAO DE HASH
static int hash ( char* string, int tamanho ){
    int i, total = 0;

    for( i = 0; string[i] != '\0' ; i++ ){
        total += string[i];
    }

    return ( total % tamanho );
}

TabHash* tabHash_inicializa ( int tamanho ){
    TabHash* h = (TabHash*) calloc( 1, sizeof( TabHash ));

    // JA INICIALIZA TUDO COM NULL
    h->vetor = (Palavra**) calloc (tamanho, sizeof(Palavra*));
    h->tamanho = tamanho;

    return h;
}

Palavra* tabHash_adiciona_palavra ( TabHash* h, char* str ){
    int indice;
    Palavra* palavra;

    indice = hash( str, h->tamanho );

    palavra = palavra_busca( h->vetor[indice], str );

    if(palavra) {
        return palavra;
    }
    else{
        //SE NAO ENCONTRAR A PALAVRA NA TABELA HASH,
        //DEVE SE CRIAR A NOVA PALAVRA

        palavra = palavra_inicializa( str );
        
        h->vetor[indice] = palavra_insere( h->vetor[indice], palavra );

        return palavra;
    }
    
}

int tabHash_num_palavras ( TabHash* h ){
    int i, soma = 0;
    Palavra* aux;

    for( i = 0; i < h->tamanho; i++ ) {
        if( h->vetor[i] != NULL ){
            for( aux = h->vetor[i]; aux != NULL; aux = palavra_retorna_prox(aux) ){
                soma += palavra_num_palavras(aux);
            }
        }
    }

    return soma;
}

void tabHash_imprime ( TabHash* h ) {
    int i;

    for( i = 0; i < h->tamanho; i++ ){
        printf("TabHash[%d]:\n", i );
        palavra_imprime_lista(h->vetor[i]);
    }
}

void tabHash_libera ( TabHash* h ) {
    int i;

    for( i = 0; i < h->tamanho; i++ ){
        palavra_libera_lista(h->vetor[i]);
    }

    free(h->vetor);
    free(h);
}
