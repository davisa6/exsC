#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* ordenar(char* palavra, int tamanho){
    char aux;
    for (int i =0; i<tamanho; i++){
        for (int j = 0; j<tamanho-1; j++){
            if (palavra[j] > palavra[j+1]){
             aux = palavra[j+1];
             palavra[j+1] = palavra[j];
             palavra[j] = aux;   
            }
        }
    }
    return palavra;
}

void validar (char* palavra1, char* palavra2){
    if (strlen(palavra1) == strlen(palavra2)){
        ordenar(palavra1, strlen(palavra1));
        ordenar(palavra2, strlen(palavra2));
    if (strcmp(palavra1, palavra2) == 0)
        printf("1");
    else
        printf("0");
    }
    else{
        printf("0");
    }
}


int main (int argc, char *argv[]){
    validar(argv[1],argv[2]);
}