#ifndef professor_h
#define professor_h
#include "aluno.h"

typedef struct prof Professor;

Professor * InsereProfessor(char * nome);
Professor * AdicionandoTurma(Professor * prof ,Aluno * aluno);
char * RetornaNomeProfessor(Professor * prof);
void ImprimiTurma(Professor * prof);
void DestruirProfessor(Professor * prof);



#endif 