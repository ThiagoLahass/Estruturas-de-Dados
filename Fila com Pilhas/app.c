#include <stdio.h>
#include <stdlib.h>
#include "Fila.h"

/*
Ola professora
Nao entendi entendi muito bem o testador que voce solicitou,
entao fiz um testador simples mesmo, testando as funcionalidades 
do programa, ok?
*/

int main() {

    Fila* fila_alunos;
    Aluno* a1 = Aloca_aluno( "Thiago", 100);
    Aluno* a2 = Aloca_aluno( "Gabriel", 101);
    Aluno* a3 = Aloca_aluno( "Bruno", 102);

    fila_alunos = Fila_inicia( 10 );

    printf("Add Thiago:\n\n");
    Fila_insere( fila_alunos, a1 );
    Fila_imprime( fila_alunos );

    printf("\nAdd Gabriel:\n");
    printf("Add Bruno:\n\n");
    Fila_insere( fila_alunos, a2 );
    Fila_insere( fila_alunos, a3 );
    Fila_imprime( fila_alunos );

    
    printf("\nRemove :(Thiago)\n");
    Aluno* a4 = Fila_retira( fila_alunos );
    Fila_imprime( fila_alunos );

    printf("\nImprime aluno removido:(Thiago)\n");
    Imprime_aluno(a4);

    printf("Add Thiago:\n\n");
    Fila_insere( fila_alunos, a1 );
    Fila_imprime( fila_alunos );

    Desaloca_aluno( a1 );
    Desaloca_aluno( a2 );
    Desaloca_aluno( a3 );
    Fila_destroi( fila_alunos );

    return 0;
}