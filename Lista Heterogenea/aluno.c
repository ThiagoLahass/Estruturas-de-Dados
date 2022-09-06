#include "aluno.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct aluno {
    char * nome;
    int matricula;
    
};

//Passando a matricula atraves da tablea hash
int TabHash(char * nome){
    int total = 0;
    for(int i = 0;nome[i] != '\0';i++ ){
        total += nome[i];
    }

    return total;
}

Aluno * InsereAluno(char * nome){
    Aluno * aluno = malloc(sizeof(Aluno));

    aluno->nome = strdup(nome);
    aluno->matricula = TabHash(nome);

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







