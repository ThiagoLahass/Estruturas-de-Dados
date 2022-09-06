#include "aluno.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "ListaDeFila.h"
#include "Fila.h"

struct fila {
    Lista * lista;
};

Fila * iniciandoFila(){
    Fila * fila  = malloc(sizeof(Fila));
    fila->lista = iniciandoLista();
    return fila;
}

Fila * InsereNaFila(Fila * fila,Aluno* aluno){
    fila->lista = InsereNaLista(fila->lista,aluno);
    return fila;
}

Fila * RetiraDaFila(Fila * fila){
    fila->lista =  RetiraDalista(fila->lista);
    return fila;
}

void ImprimiFila(Fila * fila){
    ImprimirLista(fila->lista);
}