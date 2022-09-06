#include "aluno.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "ListaDeFila.h"

typedef struct cell Cell;

struct cell {
    Aluno * aluno;
    Cell * prox;
};

struct lista{
    Cell * prim;
    Cell * ult;
};

Lista * iniciandoLista(){
    Lista * lista = malloc(sizeof(Lista));
    lista->prim = lista->ult = NULL;
    return lista;
}

Lista * InsereNaLista(Lista * lista,Aluno * aluno){
    Cell * aux = malloc(sizeof(Cell));
    aux->aluno = aluno;
    aux->prox = NULL;

    if (lista->prim == NULL){
        lista->prim = aux;
        lista->ult = aux;
    }else {
        lista->ult->prox = aux;
        lista->ult = aux;
    }

    return lista;
}

//Função que retira do começo da lista ja que representa uma fila
Lista * RetiraDalista(Lista * lista){
    if (lista == NULL){
        return NULL;
    }

    Cell * aux = lista->prim;
    lista->prim = lista->prim->prox;
    free(aux);
    
    return lista;
}

void ImprimirLista(Lista * lista){
    Cell * aux;
    for (aux = lista->prim;aux != NULL;aux = aux->prox){
        PrintarAluno(aux->aluno);
    }

}

