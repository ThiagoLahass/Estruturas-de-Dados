#ifndef ALUNO_H
#define ALUNO_H

typedef struct aluno Aluno;

Aluno* aluno_cria( char* nome, int matricula );

char* aluno_nome (Aluno* aluno);

int aluno_matricula(Aluno* aluno);

void aluno_imprime(Aluno* aluno);

void aluno_libera( Aluno* aluno );


#endif