#ifndef ALUNO_H
#define ALUNO_H

#include <stdio.h>
#include <stdlib.h>

typedef struct aluno Aluno;

Aluno* Aloca_aluno ( char* nome, int matricula );
int Retorna_matricula (Aluno* aluno);
char* Retorna_nome (Aluno* aluno);
void Imprime_aluno (Aluno* aluno);
void Desaloca_aluno (Aluno* aluno);

#endif