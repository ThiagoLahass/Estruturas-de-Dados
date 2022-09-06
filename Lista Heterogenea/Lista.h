#ifndef lista_h
#define lista_h
#include "aluno.h"
#include "Professor.h"

typedef struct lista Lista;

Lista * inicializaLista();
Lista * InsereAlunoNaLista(Lista * lista, Aluno * aluno);
Lista * InsereProfessorNaLista(Lista * lista , Professor * professor );
void ImprimiLista(Lista * lista);
void LiberaLista(Lista * lista);

#endif