#ifndef ARVORE_H
#define ARVORE_H
#include "aluno.h"

typedef struct arv Arv;

//cria uma arvore vazia
Arv* arv_cria_vazia();

//cria uma arvore com a informacao do no
//raiz aluno, e com subárvore esquerda 'e' e subárvores direita 'd'
Arv* arv_cria( Aluno* aluno, Arv* e, Arv* d);

//libera o espaco de memoria ocupado pela arvore 'a'
Arv* arv_libera( Arv* a);

//retorna true se a arvore estiver vazia
//caso contrario, retorna false
int arv_vazia (Arv* a);

//indica a ocorrencia (1) ou nao (0) do aluno com nome 'nome'
int arv_pertence (Arv* a, char* nome);

//imprime as informacoes dos nos da arvore
void arv_imprime( Arv* a);

// retorna altura de uma arvore
int arv_altura (Arv* a);

//retorna no pai de um no
Arv* arv_pai (Arv* a, char* nome);

//retorna qauntidade de folhas de uma arvore binaria
int arv_folhas ( Arv* a );

//retorna numero de ocorrencias de um dado aluno na arvore
int arv_ocorrencias ( Arv* a, char* nome);

//retorna o campo informacao de um dado no
Aluno* arv_info ( Arv* a );

//Busca o aluno de matricula chave e retorna a sua arvore
Arv* arv_busca ( Arv* a, int chave);

//Retira o aluno de matricula chave e retorna a sua arvore
Arv* arv_retira ( Arv* a, int chave);

//Insere o aluno na sua devida posição e retorna a sua arvore
Arv* arv_insere ( Arv* a, Aluno* aluno );


#endif