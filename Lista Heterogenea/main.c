#include "aluno.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Professor.h"
#include "Lista.h"


int main(){

    Aluno * a1,*a2,*a3,*a4,*a5,*a6,*a7,*a8,*a9,*a10;

    a1 = InsereAluno("Afonso");
    a2 = InsereAluno("Bruno");
    a3 = InsereAluno("Carlos");
    a4 = InsereAluno("Daniel");
    a5 = InsereAluno("Elder");
    a6 = InsereAluno("Felipe");
    a7 = InsereAluno("Garbriel");
    a8 = InsereAluno("Hariel");
    a9 = InsereAluno("Icaro");
    a10 = InsereAluno("Joao");

    Professor *p1, *p2 ,*p3;

    p1 = InsereProfessor("Professor1");
    p2 = InsereProfessor("Professor2");
    p3 = InsereProfessor("Professor3");
    
    p1 = AdicionandoTurma(p1 , a4);
    p1 = AdicionandoTurma(p1 , a5);
    p1 = AdicionandoTurma(p1 , a6);

    p2 = AdicionandoTurma(p2 , a1);
    p2 = AdicionandoTurma(p2 , a2);
    p2 = AdicionandoTurma(p2 , a3);

    p3 = AdicionandoTurma(p3 , a7);
    p3 = AdicionandoTurma(p3 , a8);
    p3 = AdicionandoTurma(p3 , a9);
    p3 = AdicionandoTurma(p3 , a10);
    
    printf("\n============== Adicionando na Lista =============\n");
    Lista * lista = inicializaLista();
    
    lista = InsereAlunoNaLista(lista, a1);
    lista = InsereProfessorNaLista(lista,p1);
    lista = InsereAlunoNaLista(lista, a2);
    lista = InsereAlunoNaLista(lista, a3);
    lista = InsereAlunoNaLista(lista, a4);
    lista = InsereProfessorNaLista(lista,p2);
    lista = InsereAlunoNaLista(lista, a5);
    lista = InsereAlunoNaLista(lista, a6);
    lista = InsereAlunoNaLista(lista, a7);
    lista = InsereAlunoNaLista(lista, a8);
    lista = InsereProfessorNaLista(lista,p2);
    lista = InsereAlunoNaLista(lista, a9);
    lista = InsereAlunoNaLista(lista, a10);
   
    ImprimiLista( lista);

    LiberarAluno(a1);
    LiberarAluno(a2);
    LiberarAluno(a3);
    LiberarAluno(a4);
    LiberarAluno(a5);
    LiberarAluno(a6);
    LiberarAluno(a7);
    LiberarAluno(a8);
    LiberarAluno(a9);
    LiberarAluno(a10);

    DestruirProfessor(p1);
    DestruirProfessor(p2);
    DestruirProfessor(p3);

    LiberaLista(lista);


    return 0;
}


