#include <stdio.h>
#include <stdlib.h>

#include "matriz.h"

int main() {
    Matriz* matriz = inicializaMatriz( 2, 3);
    imprimeMatriz( matriz );

    modificaElemento( matriz, 0, 0, 1);
    imprimeMatriz( matriz );

    modificaElemento( matriz, 0, 1, 2);
    modificaElemento( matriz, 0, 2, 3);
    modificaElemento( matriz, 1, 0, 4);
    modificaElemento( matriz, 1, 1, 5);
    modificaElemento( matriz, 1, 2, 6);
    imprimeMatriz( matriz );

    printf("matriz[1][1] = %d\n", recuperaElemento(matriz, 1, 1));

    printf("numero de linhas de matriz = %d\n", recuperaNLinhas(matriz) );

    printf("numero de colunas de matriz = %d\n\n", recuperaNColunas(matriz) );

    Matriz* matriz_transposta = transposta( matriz );
    imprimeMatriz( matriz_transposta );

    Matriz* produto = multiplicacao( matriz, matriz_transposta );
    imprimeMatriz( produto );

    destroiMatriz( matriz );
    destroiMatriz( matriz_transposta );
    destroiMatriz( produto );

    return 0;
}