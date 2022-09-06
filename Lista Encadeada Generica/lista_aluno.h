#ifndef LISTAALUNO_H
#define LISTAALUNO_H

#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"
#include "lista_gen.h"

ListaGen* ListaAluno_Inicializa ( void );
void  ListaAluno_add_final (ListaGen* lista, Aluno* aluno );
void ListaAluno_remove_por_nome ( ListaGen* lista, char* nome );
void ListaAluno_remove_por_matricula ( ListaGen* lista, int mat);
void ListaAluno_destroi ( ListaGen** lista_ref );
void ListaAluno_imprime ( ListaGen* lista );
float ListaAluno_media_cr ( ListaGen* lista );

#endif