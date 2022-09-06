#include "aluno.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Professor.h"


struct prof {
    char * nome;
    char **turma;
    int id; 
};


Professor * InsereProfessor(char * nome){
    Professor * prof = malloc(sizeof(Professor));

    prof->nome = strdup(nome);
    prof->turma = malloc(5 * sizeof(char *));
    
    for(int i = 0;i < 5 ;i++){
        prof->turma[i] = NULL; 
    }

    return prof;
}

Professor * AdicionandoTurma(Professor * prof ,Aluno * aluno){

    for(int i = 0;i < 5 ;i++){
        if (prof->turma[i] == NULL){
            prof->turma[i] = RetornaNome(aluno);
            return prof;
        }
    }
    printf("A turma esta muito cheia\n");
    return prof;
}

char * RetornaNomeProfessor(Professor * prof){
    return prof->nome;
}

void ImprimiTurma(Professor * prof){

    printf("\nProfessor : %s \nTurma :\n",RetornaNomeProfessor(prof));
    for (int i = 0;i < 5;i++){
        if (prof->turma[i] != NULL)
            printf("%s\n",prof->turma[i]);
    }  

}

void DestruirProfessor(Professor * prof){
    free(prof->nome);
    free(prof->turma);
    free(prof);
    
}



