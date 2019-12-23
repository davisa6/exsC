#include <stdio.h>
#include <stdlib.h>

int *getnevennumbers (int a){
    int *array = malloc(a*sizeof(int));
    int b = 2;
    for (int i = 1; i<=a; i++)
        array[i] = i*2; 
    return array;
}
int main (int argc, char *argv[]){
    int a;
    a= atoi(argv[1]);
    int c = atoi(argv[1]);
    int b[a];
    int *lista = getnevennumbers(a);
    
    for (int i = 1; i<=a; i++){
        printf("%d ",lista[i]);
    }
    return 0;
}