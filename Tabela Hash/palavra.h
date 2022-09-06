#ifndef PALAVRA_H
#define PALAVRA_H

typedef struct palavra Palavra;

Palavra* palavra_inicializa ( char* str );

char* palavra_retorna_string ( Palavra* palavra );

int palavra_retorna_num_ocorrencias ( Palavra* palavra );

void palavra_incrementa_num_ocorrencia( Palavra* palavra );

Palavra* palavra_busca ( Palavra* lista, char* str );

Palavra* palavra_retorna_prox ( Palavra* palavra );

Palavra* palavra_insere ( Palavra* lista, Palavra* palavra );

int palavra_num_palavras ( Palavra* lista );

void palavra_imprime_lista ( Palavra* lista );

void palavra_libera_lista ( Palavra* lista );

#endif