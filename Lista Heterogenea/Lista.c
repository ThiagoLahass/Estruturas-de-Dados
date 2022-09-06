#include "aluno.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Professor.h"
#include "Lista.h"
#define prof 1
#define alu 0


typedef struct cell Cell;

struct cell {
    void * dado;
    int id;
    Cell * prox;
};

struct lista{
    Cell * prim;
    Cell * ult;
};

Lista * inicializaLista(){
    Lista * lista = malloc(sizeof(Lista));
    lista->prim = NULL;
    lista->ult = NULL;
    return lista;
}

Lista * InsereAlunoNaLista(Lista * lista, Aluno * aluno){
    
    
    Cell * listaAux = malloc(sizeof(Cell));
    listaAux->dado = aluno;
    listaAux->id = alu;
    listaAux->prox = NULL;
    
    if(lista->prim == NULL){
        lista->prim = listaAux;
        lista->ult = listaAux;
    }
    else {
        lista->ult->prox = listaAux;
        lista->ult = listaAux;
    }
    
    return lista;
}

Lista * InsereProfessorNaLista(Lista * lista , Professor * professor ){
    Cell * listaAux = malloc(sizeof(Cell));
    listaAux->dado = professor;
    listaAux->id = prof;
    listaAux->prox = NULL;

    if (lista->prim == NULL){
        lista->prim = listaAux;
        lista->ult = listaAux;
    }
    else {
        lista->ult->prox = listaAux;
        lista->ult = listaAux; 
    }

    return lista;

}

void ImprimiLista(Lista * lista){
    Cell * aux1 = lista->prim;
    while (aux1){
        if (aux1->id == prof){
            ImprimiTurma(aux1->dado);
        }
        else {
            PrintarAluno(aux1->dado);
        }
        aux1 = aux1->prox;
    }
    
}

void LiberaLista(Lista * lista){
    Cell * aux1 = lista->prim;
    Cell * aux2 = NULL;

    while (aux1){
        aux2 = aux1->prox;
        free(aux1);
        aux1 = aux2;
    }
    free(lista);
    
}

