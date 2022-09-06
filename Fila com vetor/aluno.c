#include "aluno.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct aluno {
    char * nome;
    int matricula;
};

Aluno * InsereAluno(char * nome,int matricula){
    Aluno * aluno = malloc(sizeof(Aluno));

    aluno->nome = strdup(nome);
    aluno->matricula = matricula;

    return aluno;
}

char * RetornaNome(Aluno * aluno){
    return aluno->nome;
}

int RetornaMatricula(Aluno * aluno){
    return aluno->matricula;
}

void PrintarAluno(Aluno *  aluno){
    printf("Aluno: %s // Matricula: %d\n",aluno->nome,aluno->matricula);
}

void LiberarAluno(Aluno * aluno){
    free(aluno->nome);
    free(aluno);
}







