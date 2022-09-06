#ifndef fila_h
#define fila_h

typedef struct fila Fila;

Fila * iniciandoFila();
Fila * InsereNaFila(Fila * fila,Aluno* aluno);
Fila * RetiraDaFila(Fila * fila);
void ImprimiFila(Fila * fila);

#endif