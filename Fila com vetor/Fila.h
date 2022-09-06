#ifndef fila_h
#define fila_h


typedef struct fila Fila;

Fila * inicializaFila();

void InsereFila(Fila * fila, Aluno * aluno);

Aluno * RetiraFila(Fila * fila);

void ImprimirFila(Fila * fila);

#endif