#include "aluno.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Fila.h"

int main(){
    Aluno * a1,*a2,*a3,*a4,*a5;

    a1 = InsereAluno("bruno",1);
    a2 = InsereAluno("luca",2);
    a3 = InsereAluno("carlos",3);    
    a4 = InsereAluno("joao",4);
    a5 = InsereAluno("thiago",5);

    Fila * fila = inicializaFila();

    InsereFila(fila, a1);
    InsereFila(fila, a2);
    InsereFila(fila, a3);
    InsereFila(fila, a4);
    InsereFila(fila, a5);

    ImprimirFila(fila);

    printf("\n======== Retirando Aluno da Fila ========\n");
    RetiraFila(fila);

    ImprimirFila(fila);
    return 0;
}





