#include <stdio.h>
#include <stdlib.h>

#include "matriz.h"

struct matriz {
    int** matriz;
    int linhas;
    int colunas;
};

Matriz* inicializaMatriz (int nlinhas, int ncolunas) {

    if( nlinhas > 0 && ncolunas > 0 ){

        Matriz* mat = (Matriz*) malloc( sizeof( Matriz ));
        mat->matriz = (int**) malloc( nlinhas * sizeof(int*));

        for(int i = 0; i < nlinhas; i++ ){
            mat->matriz[i] = (int*) calloc(ncolunas,  sizeof(int));
        }
        

        mat->linhas = nlinhas;
        mat->colunas = ncolunas;

        return mat;
    }
    else{
        fprintf(stderr, "ERRO: Erro na funcao 'inicializaMatriz'\n");
        fprintf(stderr, "nlinhas e ncolunas devem ser maiores que 0(zero)!\n");
        exit(EXIT_FAILURE);
    }
    
}

void modificaElemento (Matriz* mat, int linha, int coluna, int elem) {
    if( (linha < mat->linhas && linha >= 0) && (coluna < mat->colunas && coluna >= 0) &&  (mat != NULL) ){
        mat->matriz[linha][coluna] = elem;
    }
    else {
        fprintf(stderr, "ERRO: Erro na funcao 'modificaElemento'\n");
        fprintf(stderr, "Acesso de posicao invalida: [%d,%d]\nLinha deve estar no intervalo [0, %d) e\nColuna deve estar no intervalo [0, %d)!\n",linha, coluna, mat->linhas, mat->colunas);
        exit(EXIT_FAILURE);
    }
}

int recuperaElemento(Matriz* mat, int linha, int coluna) {
    if( (linha < mat->linhas  && linha >= 0) && (coluna < mat->colunas  && coluna >= 0) &&  (mat != NULL) ){
        return mat->matriz[linha][coluna];
    }
    else {
        fprintf(stderr, "ERRO: Erro na funcao 'recuperaElemento'\n");
        fprintf(stderr, "Acesso de posicao invalida: [%d,%d]\nLinha deve estar no intervalo [0, %d) e\nColuna deve estar no intervalo [0, %d)!\n",linha, coluna, mat->linhas, mat->colunas);
        exit(EXIT_FAILURE);
    }
}

int recuperaNColunas (Matriz* mat) {
    if( mat != NULL ){
        return mat->colunas;
    }
    else {
        fprintf(stderr, "ERRO: Erro na funcao 'recuperaNColunas'\n");
        fprintf(stderr, "A matriz dada nao existe\n");
        exit(EXIT_FAILURE);
    }
}


int recuperaNLinhas (Matriz* mat) {
    if( mat != NULL ){
        return mat->linhas;
    }
    else {
        fprintf(stderr, "ERRO: Erro na funcao 'recuperaNLinhas'\n");
        fprintf(stderr, "A matriz dada nao existe\n");
        exit(EXIT_FAILURE);
    }
}

Matriz* transposta (Matriz* mat) {
    if( mat != NULL ){
        int nlinhas = recuperaNLinhas(mat);
        int ncolunas = recuperaNColunas(mat);

        Matriz* aux = inicializaMatriz( ncolunas, nlinhas);

        for( int i = 0; i < nlinhas; i++ ) {
            for( int j = 0; j < ncolunas; j++ ) {
                modificaElemento( aux, j, i, recuperaElemento( mat, i, j ));
            }
        }

        return aux;
    }
    else {
        fprintf(stderr, "ERRO: Erro na funcao 'transposta'\n");
        fprintf(stderr, "A matriz dada nao existe\n");
        exit(EXIT_FAILURE);
    }
}

Matriz* multiplicacao (Matriz* mat1, Matriz* mat2) {

    int linhas_mat1 = recuperaNLinhas( mat1 );
    int linhas_mat2 = recuperaNLinhas( mat2 );
    int colunas_mat1 = recuperaNColunas( mat1 );
    int colunas_mat2 = recuperaNColunas( mat2 );

    if( ( mat1 != NULL ) && ( mat2 != NULL ) &&  ( colunas_mat1 == linhas_mat2) ){

        int somatorio = 0;
        Matriz* mult = inicializaMatriz( linhas_mat1, colunas_mat2);

        for( int i = 0; i < linhas_mat1; i++ ) {
            for( int j = 0; j < colunas_mat2; j++ ) {
                for( int k = 0; k < linhas_mat2; k++ ) {
                    somatorio += recuperaElemento(mat1, i, k) * recuperaElemento(mat2, k, j);
                }

                modificaElemento( mult, j, i, somatorio);
                somatorio = 0;
            }
        }

        return mult;
    }
    else {
        fprintf(stderr, "ERRO: Erro na funcao 'multiplicacao'\n");
        if( mat1 == NULL || mat2 == NULL )
            fprintf(stderr, "Pelo menos uma das matrizes dadas nao existe!\n");
        else
            fprintf(stderr, "Numero de colunas de mat1 nao corresponde ao numero de linhas de mat2!\nNumero de colunas de mat1 = %d\nNumero de linhas de mat2 = %d\n", colunas_mat1, linhas_mat2);
        exit(EXIT_FAILURE);
    }
}

void imprimeMatriz(Matriz* mat) {
    if( mat != NULL ){
        for( int i = 0; i < mat->linhas; i++ ) {
            for( int j = 0; j < mat->colunas; j++ ) {
                printf("%2d ", mat->matriz[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }
    else {
        fprintf(stderr, "ERRO: Erro na funcao 'imprimeMatriz'\n");
        fprintf(stderr, "A matriz dada nao existe\n");
        exit(EXIT_FAILURE);
    }
    
    
}

void destroiMatriz(Matriz* mat) {

    int nlinhas = recuperaNLinhas( mat );

    for(int i = 0; i < nlinhas; i++ ){
        free(mat->matriz[i]);
    }

    free(mat->matriz);

    free( mat );
}