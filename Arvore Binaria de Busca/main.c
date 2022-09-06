#include "arvore.h"
#include "aluno.h"
#include <stdio.h>
#include <stdlib.h>


int main() {

    //cria uma arvore para teste
    Aluno *a1, *a2, *a3, *a4, *a5, *a6, *a7;
    a1 = aluno_cria("Thiago",  101 );
    a2 = aluno_cria("Bruno",   102 );
    a3 = aluno_cria("Gatti",   103 );
    a4 = aluno_cria("Jao",     110 );
    a5 = aluno_cria("Patricia",120 );
    a6 = aluno_cria("Sinuca",  130 );


    Arv* a = arv_cria(a1, arv_cria_vazia(), arv_cria_vazia());
    a = arv_insere( a, a2 );
    a = arv_insere( a, a3 );
    a = arv_insere( a, a4 );
    a = arv_insere( a, a5 );
    a = arv_insere( a, a6 );
    

    arv_imprime(a);
    puts("\n");

    //testa função busca
    puts("Busca o aluno de matricula 103 ( Gatti )");
    Arv* aux = arv_busca(a, 103 );
    aluno_imprime( arv_info(aux) );
    puts("\n");

    //testa a função insere
    puts("Insere o aluno de matricula 105 ( Leo )");
    a7 = aluno_cria("Leo",  105 );
    a = arv_insere( a, a7 );
    arv_imprime(a);
    puts("\n");

    //testa a função retira
    puts("Retira o aluno de matricula 110 ( Jao )");
    arv_retira( a, 110 );
    arv_imprime(a);
    puts("\n");



    aluno_libera(a1);
    aluno_libera(a2);
    aluno_libera(a3);
    aluno_libera(a4);
    aluno_libera(a5);
    aluno_libera(a6);
    aluno_libera(a7);

    arv_libera(a);

    return 0;
}