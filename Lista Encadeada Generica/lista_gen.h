#ifndef LISTA_GEN_H
#define LISTA_GEN_H

typedef struct listagen ListaGen;

ListaGen* ListaGen_Inicializa ( void );
void ListaGen_add_final (ListaGen* lista, void* elem );
void ListaGen_remove ( ListaGen* lista, int(*cmp)( void*, void* ) , void* chave );
void ListaGen_destroi ( ListaGen** lista_ref );
void ListaGen_imprime ( const ListaGen* lista, void(*imp)( void* ) );
int  ListaGen_percorre( ListaGen* lista, int(*cb)( void*, void* ), void* dado );

#endif