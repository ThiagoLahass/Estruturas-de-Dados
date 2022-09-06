#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "aluno.h"

typedef struct aluno{
	char* nome;
	int matricula;
    float CR;
}Aluno;

Aluno* Aloca_aluno ( char* nome, int matricula, float CR ){

    Aluno* aluno = (Aluno*) malloc( sizeof(Aluno) );
	aluno->nome = strdup(nome);
	aluno->matricula = matricula;
    aluno->CR = CR;

    return aluno;
}

int Retorna_matricula (Aluno* aluno) {
    return aluno->matricula;
}

char* Retorna_nome (Aluno* aluno) {
    return aluno->nome;
}

float Retorna_CR ( Aluno* aluno ) {
    return aluno->CR;
}

void Imprime_aluno (Aluno* aluno) {
	printf("Nome:       %s\n", 		aluno->nome);
	printf("Matricula:  %d\n", 	aluno->matricula);
    printf("CR:         %.2f\n\n", aluno->CR);
}

void Desaloca_aluno (Aluno* aluno) {
    free(aluno->nome);
    free(aluno);
}