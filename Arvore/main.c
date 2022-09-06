#include "arvore.h"
#include "aluno.h"
#include <stdio.h>
#include <stdlib.h>


int main() {

    //cria uma arvore para teste
    Aluno *a1, *a2, *a3, *a4, *a5, *a6;
    a1 = aluno_cria("Thiago",  101 );
    a2 = aluno_cria("Bruno",   102 );
    a3 = aluno_cria("Gatti",   103 );
    a4 = aluno_cria("Jao",     104 );
    a5 = aluno_cria("Patricia",105 );
    a6 = aluno_cria("Sinuca",  106 );


    Arv* a =    arv_cria(a1, 
                    arv_cria(a2,
                    arv_cria_vazia(),
                    arv_cria(a4, arv_cria_vazia(), arv_cria_vazia())
                    ),
                arv_cria(a3,
                    arv_cria(a5, arv_cria_vazia(), arv_cria_vazia()),
                    arv_cria(a6, arv_cria_vazia(), arv_cria_vazia())
                    )
                );

    arv_imprime(a);

    //verifica se o 'Thiago' pertence a arvore
    int pertence = arv_pertence( a, "Thiago" );
    printf("\n'Thiago' pertence?: %d\n", pertence);

    //verifica se o 'Raiam' pertence a arvore
    pertence = arv_pertence( a, "Raiam" );
    printf("'Raiam' pertence?: %d\n", pertence);

    //retorna o pai do no "Gatti" (deve ser 'Thiago' )
    Arv* pai = arv_pai( a, "Patricia" );
    printf("Pai do no 'Patricia': %s \n", arv_info( pai ));

    //retorna numero de folhas da arvore (3)
    int f = arv_folhas( a );
    printf("Numero de folhas da arvore: %d \n", f);

    //retorna o numero de ocorrencias de 'f' (1)
    int i = arv_ocorrencias( a, "Sinuca");
    printf("Numero de ocorrencias de 'Sinuca': %d \n", i);

    aluno_libera(a1);
    aluno_libera(a2);
    aluno_libera(a3);
    aluno_libera(a4);
    aluno_libera(a5);
    aluno_libera(a6);

    arv_libera(a);

    return 0;
}