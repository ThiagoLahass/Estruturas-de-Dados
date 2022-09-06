#include <stdio.h>
#include <stdlib.h>
#include "lista_aluno.h"

int main() {

    Lista* lista_aluno;
    Aluno* a1 = Aloca_aluno( "Thiago", 100);
    Aluno* a2 = Aloca_aluno( "Gabriel", 101);
    Aluno* a3 = Aloca_aluno( "Bruno", 102);

    lista_aluno = Lista_Inicializa();
    
    Lista_add_final(lista_aluno, a1);
    Lista_add_final(lista_aluno, a2);
    Lista_add_final(lista_aluno, a3);
    printf("Lista aluno 1:\n");
    Lista_imprime( lista_aluno );

    puts("---------------------------");
    Lista_remove_aluno( lista_aluno, "Thiago" );
    printf("Lista aluno 1:\n");
    Lista_imprime( lista_aluno );

    Aluno* a4 = Aloca_aluno( "Joao", 103);
    Lista_add_final(lista_aluno, a4);

    puts("---------------------------");
    printf("Lista aluno 1:\n");
    Lista_imprime( lista_aluno );



    puts("");
    Lista* lista_aluno2;
    Aluno* a10 = Aloca_aluno( "Pedro", 110);
    Aluno* a11 = Aloca_aluno( "Jose", 111);
    Aluno* a12 = Aloca_aluno( "Luiz", 112);

    lista_aluno2 = Lista_Inicializa();
    
    Lista_add_final(lista_aluno2, a10);
    Lista_add_final(lista_aluno2, a11);
    Lista_add_final(lista_aluno2, a12);
    printf("Lista aluno 2:\n");
    Lista_imprime( lista_aluno2 );

    puts("---------------------------");
    Lista_remove_aluno( lista_aluno2, "Jose" );
    printf("Lista aluno 2:\n");
    Lista_imprime( lista_aluno2 );

    Aluno* a13 = Aloca_aluno( "Leo", 113);
    Lista_add_final(lista_aluno2, a13);

    puts("---------------------------");
    printf("Lista aluno 2:\n");
    Lista_imprime( lista_aluno2 );

    puts("\n---------------------------\n");
    printf("Lista aluno 1 final:\n");
    Lista_imprime( lista_aluno );

    puts("");
    
    printf("Lista aluno 2 final:\n");
    Lista_imprime( lista_aluno2 );


    Desaloca_aluno(a1);
    Desaloca_aluno(a2);
    Desaloca_aluno(a3);
    Desaloca_aluno(a4);
    Desaloca_aluno(a10);
    Desaloca_aluno(a11);
    Desaloca_aluno(a12);
    Desaloca_aluno(a13);
    Lista_destroi( &lista_aluno );
    Lista_destroi( &lista_aluno2 );

    return 0;
}