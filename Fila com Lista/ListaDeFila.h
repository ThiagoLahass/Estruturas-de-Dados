#ifndef lista_h
#define lista_h

typedef struct lista Lista;

Lista * iniciandoLista();
Lista * InsereNaLista(Lista * lista,Aluno * aluno);
Lista * RetiraDalista(Lista * lista);
void ImprimirLista(Lista * lista);


#endif