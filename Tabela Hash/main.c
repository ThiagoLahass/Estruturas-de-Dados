#include "tab_hash.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TAM_TAB 127
#define TAM_PAL 64

int le_palavra( FILE* arquivo, char* str ) {
    int i = 0, c;

    while ( (c = fgetc(arquivo)) != EOF ) {
        if( isalpha( c )){
            break;
        }
    }
    
    if ( c == EOF ){
        return 0;
    }
    else {
        str[i++] = c;
    }

    while ((i < TAM_PAL - 1) && (c = fgetc(arquivo)) != EOF && isalpha(c) ){
        str[i++] = c;
    }

    str[i] = '\0';

    return i; 
}

int main( int argc, char** argv ) {

    FILE* arquivo;
    
    char s[TAM_PAL];

    if( argc == 2 ){
        arquivo = fopen( argv[1], "rt" );
    }
    
    if( arquivo == NULL ) {
        printf("Arquivo não encontrado!\n");
    }

    TabHash* tabHash;
    Palavra* p;

    tabHash = tabHash_inicializa( TAM_TAB );

    while( le_palavra( arquivo, s )) {
        p = tabHash_adiciona_palavra( tabHash, s );
        palavra_incrementa_num_ocorrencia(p);
    }


    tabHash_imprime( tabHash );

    tabHash_libera( tabHash );

    fclose(arquivo);


    return 0;
}