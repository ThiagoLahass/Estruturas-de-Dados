#include <stdio.h>
#include <stdlib.h>
#include "lista_aluno.h"

int main() {

    ListaGen* lista_aluno;
    Aluno* a1 = Aloca_aluno( "Thiago", 100, 9.81);
    Aluno* a2 = Aloca_aluno( "Gabriel", 101, 10);
    Aluno* a3 = Aloca_aluno( "Bruno", 102, 9.9);

    lista_aluno = ListaAluno_Inicializa();

    printf("\nLista aluno 1:\n");
    ListaAluno_imprime( lista_aluno );
    puts("---------------------------");
    
    ListaAluno_add_final(lista_aluno, a1);
    ListaAluno_add_final(lista_aluno, a2);
    ListaAluno_add_final(lista_aluno, a3);

    printf("\nLista aluno 1:\n");
    ListaAluno_imprime( lista_aluno );
    puts("---------------------------");


    ListaAluno_remove_por_nome( lista_aluno, "Thiago" );
    printf("\nLista aluno 1:\n");
    ListaAluno_imprime( lista_aluno );
    puts("---------------------------");


    Aluno* a4 = Aloca_aluno( "Joao", 103, 5);
    ListaAluno_add_final(lista_aluno, a4);

    printf("\nLista aluno 1:\n");
    ListaAluno_imprime( lista_aluno );
    puts("---------------------------");


    ListaGen* lista_aluno2;
    Aluno* a10 = Aloca_aluno( "Pedro", 110, 7);
    Aluno* a11 = Aloca_aluno( "Jose", 111, 1);
    Aluno* a12 = Aloca_aluno( "Luiz", 112, 8);

    lista_aluno2 = ListaAluno_Inicializa();

    printf("\nLista aluno 2:\n");
    puts("---------------------------");
    
    ListaAluno_add_final(lista_aluno2, a10);
    ListaAluno_add_final(lista_aluno2, a11);
    ListaAluno_add_final(lista_aluno2, a12);

    printf("\nLista aluno 2:\n");
    ListaAluno_imprime( lista_aluno2 );
    puts("---------------------------");


    ListaAluno_remove_por_matricula( lista_aluno2, 111 );

    printf("\nLista aluno 2:\n");
    ListaAluno_imprime( lista_aluno2 );
    puts("---------------------------");


    Aluno* a13 = Aloca_aluno( "Leo", 113, 3.3);
    ListaAluno_add_final(lista_aluno2, a13);

    printf("\nLista aluno 2:\n");
    ListaAluno_imprime( lista_aluno2 );
    puts("---------------------------");

    float media_t1 = ListaAluno_media_cr( lista_aluno );
    
    printf("\nLista aluno 1 final:\n");
    ListaAluno_imprime( lista_aluno );

    printf("Média turma 1: %.2f\n", media_t1 );
    puts("---------------------------");


    float media_t2 = ListaAluno_media_cr( lista_aluno2 );
    
    printf("\nLista aluno 2 final:\n");
    ListaAluno_imprime( lista_aluno2 );
    printf("Média turma 2: %.2f\n", media_t2 );
    puts("---------------------------");




    Desaloca_aluno(a1);
    Desaloca_aluno(a2);
    Desaloca_aluno(a3);
    Desaloca_aluno(a4);
    Desaloca_aluno(a10);
    Desaloca_aluno(a11);
    Desaloca_aluno(a12);
    Desaloca_aluno(a13);
    ListaAluno_destroi( &lista_aluno );
    ListaAluno_destroi( &lista_aluno2 );

    return 0;
}