#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista_gen.h"


typedef struct celula Celula;

struct celula{
    void* item;
    struct celula *prox;
};

struct listagen{
    Celula* prim;
    Celula* ult;
};



ListaGen* ListaGen_Inicializa ( void ) {

    ListaGen* lista = (ListaGen*) calloc(1, sizeof(ListaGen));
    lista->prim = NULL;
    lista->ult = NULL;

    return lista;
}


void ListaGen_add_final (ListaGen* lista, void* elem ) {

    Celula* nova = (Celula*)calloc(1, sizeof(Celula));
    nova->item = elem;
    nova->prox = NULL;

    //se a lista estiver vazia
    if( lista->prim == NULL ){
        lista->prim = nova;
        lista->ult = nova;
    }
    else {
        lista->ult->prox = nova;
        lista->ult = lista->ult->prox;
    }
}


void ListaGen_remove ( ListaGen* lista, int(*cmp)( void*, void* ) , void* chave ) {

    //se a lista NAO estiver vazia
    if( lista->prim != NULL ){
        Celula* prev = NULL;
        Celula* pos = lista->prim;

        while( pos!= NULL && cmp(pos->item, chave) ) {
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


void ListaGen_destroi ( ListaGen** lista_ref ) {
    
    ListaGen* lista = *lista_ref;

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


void ListaGen_imprime ( const ListaGen* lista, void(*imp)( void* ) ) {
    Celula* p = lista->prim;

    while( p != NULL ){
        imp(p->item);
        p = p->prox;
    }
}

int  ListaGen_percorre( ListaGen* lista, int(*cb)( void*, void* ), void* dado ) {
    Celula* p;

    for( p = lista->prim; p != NULL; p = p->prox ) {
        int r = cb( p->item, dado );
        if( r == 0 ) {
            return r;
        }
    }

    return 1;
}