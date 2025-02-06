#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#define MAX_NUM 50//Limite maximo para 50 numeros

int adicionar_numero(int numeros[],int *quantidade){
if(*quantidade<MAX_NUM){//Verifica limite de numeros a ser adicionado
    printf("Digite um Numero: ");
        scanf("%d",&numeros[*quantidade]);
            (*quantidade++);
        printf(">Numero Adicionado\n");
}else{
    printf("Limite para adicionar numeros execedido\n");
}
return 0;
}

int listar_numero(int numeros[], int quantidade){//Procura se existe algum numero que foi adicionado
if(quantidade>0){//Se houver algum numero ele ira os listar
    printf("--Lista dos Numeros Adicionados--\n");
    int i;
    for(i=0;i<quantidade;i++){
        printf("%d.%d",i,numeros[i]);
    }
}else{//Caso contrario exibe que ele nao foi encontrado
    printf("Nenhum numero foi adicionado\n");
}
return 0;
}

int remover_numero(int numeros[],int *quantidade,int indice){//Remove um numero da Lista
    if(indice< 0 || indice >= *quantidade){// Verifica se o indice e valido
        printf("Indice invalido\n");
        return -1; // Retorna que houve erro
    }
    int i;
    for(i=indice;i<*quantidade;i++){
        numeros[i]=numeros[i+1];
    }
    (*quantidade--);
    printf(">Numero Removido");
return 0;
}
