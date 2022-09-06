#include "aluno.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "ListaDeFila.h"
#include "Fila.h"

int main(){

    Aluno * a1,*a2,*a3,*a4,*a5;

    a1 = InsereAluno("bruno",1);
    a2 = InsereAluno("luca",2);
    a3 = InsereAluno("carlos",3);    
    a4 = InsereAluno("joao",4);
    a5 = InsereAluno("thiago",5);

    Fila * fila = iniciandoFila();

    fila = InsereNaFila( fila,a1);
    fila = InsereNaFila( fila,a2);
    fila = InsereNaFila( fila,a3);
    fila = InsereNaFila( fila,a4);
    fila = InsereNaFila( fila,a5);

    ImprimiFila(fila);

    printf("\n========= Retira Aluno ========\n");
    fila = RetiraDaFila(fila);
    fila = RetiraDaFila(fila);

    ImprimiFila(fila);


    return 0;
}


