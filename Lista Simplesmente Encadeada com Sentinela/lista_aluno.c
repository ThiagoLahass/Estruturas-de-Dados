#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista_aluno.h"
#include "aluno.h"

struct celula{
    Aluno* aluno;
    struct celula *prox;
};

struct lista{
    Celula* prim;
    Celula* ult;
};

Celula* Celula_Inicializa ( Aluno* aluno ) {

    Celula* celula = (Celula*) calloc(1, sizeof( Celula ));
    celula->aluno = aluno;
    celula->prox = NULL;

    return celula;
}


Lista* Lista_Inicializa () {

    Lista* lista = (Lista*) calloc(1, sizeof(Lista));
    lista->prim = NULL;
    lista->ult = NULL;

    return lista;
}


void  Lista_add_final (Lista* lista, Aluno* aluno ) {

    Celula* aux = Celula_Inicializa( aluno );

    //se a lista estiver vazia
    if( lista->prim == NULL ){
        lista->prim = aux;
        lista->ult = aux;
    }
    else {
        lista->ult->prox = aux;
        lista->ult = lista->ult->prox;
    }
}


void Lista_remove_aluno ( Lista* lista, char* nome ) {

    //se a lista NAO estiver vazia
    if( lista->prim != NULL ){
        Celula* prev = NULL;
        Celula* pos = lista->prim;

        while( pos!= NULL && strcmp( Retorna_nome(pos->aluno), nome ) ) {
            prev = pos;
            pos = pos->prox;
        }

        // se achou um nó com nome dado
        if( pos != NULL ) {
            //se esta na ultima posicao
            if( lista->ult == pos ) {
                lista->ult = prev;
            }
            //se esta na primeira posicao
            if( lista->prim == pos ) {
                lista->prim = lista->prim->prox;
            }
            else {
                prev->prox = pos->prox;
            }

            free(pos);
        }
    }
}


void Lista_destroi ( Lista** lista_ref ) {
    
    Lista* lista = *lista_ref;

    Celula* p = lista->prim;
    Celula* aux = NULL;

    while( p != NULL ) {
        aux = p;
        p = p->prox;
        free(aux);
    }

    free(lista);

    *lista_ref = NULL;
}


void Lista_imprime ( const Lista* lista ) {
    Celula* p = lista->prim;

    printf("Lista_alunos -> \n");

    // enquanto p não chegou ao fim da lista, isto é,
    // enquanto p estiver apontando para um nó da lista
    while (p != NULL) {
        Imprime_aluno( p->aluno );
        p = p->prox;
    }

}