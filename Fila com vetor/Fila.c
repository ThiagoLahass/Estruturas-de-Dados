#include "aluno.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Fila.h"

#define tam 10

struct fila {
    Aluno * vetor[tam];
    int qtd; //Quantidade de itens dentro do vetor
    int inicio; //inicio da fila
};

Fila * inicializaFila(){
    Fila * fila = malloc(sizeof(Fila));
    fila->inicio = 0;
    fila->qtd = 0;
    return fila;
}
//Adicionando no final do vetor.
void InsereFila(Fila * fila, Aluno * aluno){
    if(aluno == NULL || fila == NULL || fila->qtd >= tam){
        printf("Erroo !!!!\n");
        return;
    }

    //posição final do vetor
    int pos = (fila->inicio + fila->qtd) % tam;

    //Adicionando o aluno no vetor na posição pos
    fila->vetor[pos] = aluno;
    fila->qtd++;

}

Aluno * RetiraFila(Fila * fila){
    if(fila == NULL || fila->qtd == 0){
        printf("Erroo !!!!\n");
        return NULL;
    }

    Aluno * aluno = fila->vetor[fila->inicio];
    //Faz incremento circular na posição do inicio
    fila->inicio = (fila->inicio+1) % tam;
    fila->qtd--;

    return aluno;

}


void ImprimirFila(Fila * fila){

    for (int i = 0;i < fila->qtd;i++){
        int pos = (fila->inicio + i) % tam;
        PrintarAluno(fila->vetor[pos]);
    }
}






