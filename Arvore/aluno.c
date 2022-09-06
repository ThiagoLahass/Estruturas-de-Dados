#include "aluno.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct aluno{
    char* name;
    int matricula;
};

Aluno* aluno_cria( char* nome, int matricula ){
    Aluno* aluno = (Aluno*) calloc(1, sizeof(Aluno));
    aluno->matricula = matricula;
    aluno->name = strdup(nome);

    return aluno;
}

char* aluno_nome (Aluno* aluno){
    return aluno->name;
}

int aluno_matricula(Aluno* aluno){
    return aluno->matricula;
}

void aluno_imprime(Aluno* aluno){
    printf("%s", aluno_nome( aluno ));
}

void aluno_libera( Aluno* aluno ){
    free (aluno->name);
    free (aluno);
}

