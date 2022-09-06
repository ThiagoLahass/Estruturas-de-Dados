#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista_aluno.h"

typedef struct cr {
    float CR;
    int n;
} CR;

// ======================================================

int comparaMatricula( void* aluno, void* pMat ) {
    int mat = *((int*)(pMat));

    if( Retorna_matricula(aluno) == mat ){
        return 0;
    }

    return 1;
}

int comparaNome( void* aluno, void* nome ) {
    return strcmp( Retorna_nome(aluno), nome);
}

int imprime ( void* aluno, void* dado ) {
    Imprime_aluno(aluno);
    return 1;
}

int acumula ( void* aluno, void* dado ) {
    CR* acumulado = (CR*) dado;
    acumulado->CR += Retorna_CR(aluno);
    acumulado->n++;
    return 1;
}

// ======================================================

ListaGen* ListaAluno_Inicializa ( void ) {
    return ListaGen_Inicializa();
}


void  ListaAluno_add_final (ListaGen* lista, Aluno* aluno ) {
    ListaGen_add_final( lista, aluno);
}


void ListaAluno_remove_por_nome ( ListaGen* lista, char* nome ) {
    ListaGen_remove( lista, comparaNome, nome);
}


void ListaAluno_remove_por_matricula ( ListaGen* lista, int mat ) {
    ListaGen_remove( lista, comparaMatricula, &mat);
}


void ListaAluno_destroi ( ListaGen** lista_ref ) {
    ListaGen_destroi(lista_ref);
}


void ListaAluno_imprime ( ListaGen* lista ) {
    ListaGen_percorre( lista, imprime, NULL );
}

float ListaAluno_media_cr ( ListaGen* lista ) {
    CR* cr = (CR*)calloc( 1, sizeof(CR));

    ListaGen_percorre( lista, acumula, cr);

    float media = cr->CR/cr->n;
    free( cr );

    return media;
}