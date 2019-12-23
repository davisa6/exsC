#include <stdio.h>
#include <stdlib.h>


// c = Linhas
// d = Colunas

int main (int argc, char *argv[]){
    // declarando o ponteiro do arquivo como fptr 
    FILE *fptr;
    //Abrindo o arquivo com argv[1] que é um arquivo txt
    fptr = fopen(argv[1],"r");
    
    //Condições para checar se o número de argumentos é diferente do que devia ser
    if (argc != 2) {
        return 1;
    }
    //Se o arquivo for nulo, retorna 1 tb
    if (!fptr){
        return 1;
    }
    //Contador pra checar linhas
    int c = 0;
    //Enquanto não chegar no fim do arquivo
    while (!feof(fptr)){
        int aux =  fgetc(fptr);
        //Se for quebra de linha, adiciona 1 no contador
        if (aux == '\n')
            c++;
    }
    //Voltar ao início do arquivo
    rewind(fptr);

    //Adicionando 1 ao contador, pq ele nunca conta a primeira linha, só conta as quebras de linha
    c++;
    int d = 0;
    char e = '0';
    //Vai checando nas linhas
     while (e!='\n'){
         //fgetc obtem o conteúdo dentro do while
         e = fgetc(fptr);
         //Com o número de espaços, vai ser possível saber o número de colunas -1
         if (e == ' '){
             d++;
         }
     }
    d++;
    //Volta pra o início do arquivo
    rewind(fptr);   
    //Pra escanear a matriz
    int matriz[c][d];
    int somalin = 0;
    int somacol = 0;
    int arlin [c];
    int arcol [d];
    int posv = 0;
    for (int i = 0; i<c; i++){
        for (int j = 0; j<d; j++){
            //fscanf pega como parâmetro o ponteiro pra arquivo, o tipo, e o endereço de memória de onde você quer armazenar
            fscanf(fptr, "%d", &matriz[i][j]);
        }
    }
    //Função comentada pra printar a matriz
    /*for (int i = 0; i<c; i++){
        printf("\n");
        for (int j = 0; j<d; j++){
            printf("%d ",matriz[i][j]);
        }
    }*/
    //Função pra somar as linhas, e armazenar em um array as somas
    for (int i = 0; i<c; i++){
        //Zera a soma
        somalin = 0;
        for (int j = 0; j<d; j++){
            //Soma as linhas e atribui
                somalin += matriz[i][j];
                arlin [i] = somalin;
    }}
    //Função pra somar as colunas e armazenar em um array essas somas
    for (int j = 0; j<d; j++){
        somacol = 0;
        for (int i = 0; i<c; i++){
            //Soma as colunas e atribui, o raciocínio das colunas é basicamente o inverso o das linhas, por isso é matriz [i][j] com os "fors" diferentes do das linhas
                somacol += matriz[i][j];
                arcol [j] = somacol;
    }}
    //Pra checar as posições vencedoras
    for (int i = 0; i<c; i++){
        for (int j = 0; j<d; j++){
            //If simples p checar se a soma da coluna é maior que a da linha
            if (arcol[i] > arlin[j])
            //Se for, contador de posições vencedoras ++
                posv++;
        }}
    printf("%d",posv);
//Fecha o arquivo
    fclose(fptr);
}