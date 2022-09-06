#ifndef LISTADPLALUNO_H
#define LISTADPLALUNO_H

#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"

typedef struct celula Celula;
typedef struct lista_dpl Lista_dpl;

Celula* Celula_Inicializa ( Aluno* aluno );
Lista_dpl* Lista_dpl_Inicializa ();
void  Lista_dpl_add_final (Lista_dpl* lista, Aluno* aluno );
void Lista_dpl_remove_aluno ( Lista_dpl* lista, char* nome );
void Lista_dpl_destroi ( Lista_dpl** lista_ref );
void Lista_dpl_imprime ( const Lista_dpl* lista );
void Lista_dpl_imprime_reverse ( const Lista_dpl* lista );

#endif