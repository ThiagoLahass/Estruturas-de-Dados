#ifndef LISTAALUNO_H
#define LISTAALUNO_H

#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"

typedef struct celula Celula;
typedef struct lista Lista;

Celula* Celula_Inicializa ( Aluno* aluno );
Lista* Lista_Inicializa ();
void  Lista_add_final (Lista* lista, Aluno* aluno );
void Lista_remove_aluno ( Lista* lista, char* nome );
void Lista_destroi ( Lista** lista_ref );
void Lista_imprime ( const Lista* lista );

#endif