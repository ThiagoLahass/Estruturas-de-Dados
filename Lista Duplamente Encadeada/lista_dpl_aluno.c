#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista_dpl_aluno.h"
#include "aluno.h"

struct celula{
    Aluno* aluno;
    struct celula *prox;
    struct celula *ant;
};

struct lista_dpl{
    Celula* prim;
    Celula* ult;
};

Celula* Celula_Inicializa ( Aluno* aluno ) {

    Celula* celula = (Celula*) calloc(1, sizeof( Celula ));
    celula->aluno = aluno;
    celula->prox = NULL;
    celula->ant = NULL;

    return celula;
}


Lista_dpl* Lista_dpl_Inicializa () {

    Lista_dpl* lista = (Lista_dpl*) calloc(1, sizeof(Lista_dpl));
    lista->prim = NULL;
    lista->ult = NULL;

    return lista;
}


void  Lista_dpl_add_final (Lista_dpl* lista, Aluno* aluno ) {

    Celula* aux = Celula_Inicializa( aluno );

    aux->ant = lista->ult;

    //se a lista estiver vazia
    if( lista->prim == NULL ){
        lista->prim = aux;
    }
    else {
        lista->ult->prox = aux;
    }

    lista->ult = aux;
}


void Lista_dpl_remove_aluno ( Lista_dpl* lista, char* nome ) {

    //se a lista NAO estiver vazia
    if( lista->prim != NULL ){
        Celula* p = lista->prim;

        while( p!= NULL && strcmp( Retorna_nome(p->aluno), nome ) ) {
            p = p->prox;
        }

        // se achou um nó com nome dado
        if( p != NULL ) {
            
            //se esta na primeira posicao
            if( lista->prim == p ) {
                lista->prim = p->prox;
                
                //se ha apenas um elemento
                if( lista->ult == p ) {
                    lista->ult = NULL;
                }
                else {
                    lista->prim->ant = NULL;
                }
            }
            // se esta no final
            else if ( lista->ult == p ){
                p->ant->prox = NULL;
                lista->ult = p->ant;
            }
            else {
                p->ant->prox = p->prox;
                p->prox->ant = p->ant;
            }

            free(p);
        }
    }
}


void Lista_dpl_destroi ( Lista_dpl** lista_ref ) {
    
    Lista_dpl* lista = *lista_ref;

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


void Lista_dpl_imprime ( const Lista_dpl* lista ) {
    Celula* p = lista->prim;

    // enquanto p não chegou ao fim da lista, isto é,
    // enquanto p estiver apontando para um nó da lista
    while (p != NULL) {
        Imprime_aluno( p->aluno );
        p = p->prox;
    }
    puts("");

}

void Lista_dpl_imprime_reverse ( const Lista_dpl* lista ) {
    Celula* p = lista->ult;

    printf("Lista_alunos -> \n");

    // enquanto p não chegou ao fim da lista, isto é,
    // enquanto p estiver apontando para um nó da lista
    while (p != NULL) {
        Imprime_aluno( p->aluno );
        p = p->ant;
    }

}