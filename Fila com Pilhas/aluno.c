#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "aluno.h"

typedef struct aluno{
	char* nome;
	int matricula;
}Aluno;

Aluno* Aloca_aluno ( char* nome, int matricula );
int Retorna_matricula (Aluno* aluno);
char* Retorna_nome (Aluno* aluno);
void Imprime_aluno (Aluno* aluno);
void Desaloca_aluno (Aluno* aluno);

Aluno* Aloca_aluno ( char* nome, int matricula ){

    Aluno* aluno = (Aluno*) malloc( sizeof(Aluno) );
	aluno->nome = strdup(nome);
	aluno->matricula = matricula;

    return aluno;
}

int Retorna_matricula (Aluno* aluno) {
    return aluno->matricula;
}

char* Retorna_nome (Aluno* aluno) {
    return aluno->nome;
}

void Imprime_aluno (Aluno* aluno) {
	printf("Nome: %s\n", 		aluno->nome);
	printf("Matricula: %d\n", 	aluno->matricula);
}

void Desaloca_aluno (Aluno* aluno) {
    free(aluno->nome);
    free(aluno);
}