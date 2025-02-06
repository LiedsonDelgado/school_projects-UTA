#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#define MAX_NUM 50 //Limite maximo para 50 numeros

int main()
{
int numeros[MAX_NUM];
int quantidade=0;
int opcao,indice;

do{
printf("\nMENU PARA ADICIONAR NUMERO\n\n"); //MENU DE OPCOES
printf("1.Adicionar Numeros\n");
printf("2.Remover Numeros\n");
printf("3.Listar Numeros\n");
printf("4.Sair\n");
printf(">>Escolha uma Opcao: ");
    scanf("%d",&opcao);
switch(opcao){
case 1:
    adicionar_numero(numeros,&quantidade);//Executa a funcao para adicionar um numero
    break;
case 2:
    printf("\nDigite o indice do numero para remover(0 a %d: ",quantidade-1);//Remove o numero atraves do indice seu indice
    scanf("%d",&indice);
    remover_numero(numeros,&quantidade,indice);//Executa a funcao para remover um numero
    break;

case 3:
    listar_numero(numeros,quantidade);//Executa a funcao para listar um numero
    break;

case 4:
    printf("Saindo...\n");//Termina a execucao do programa
    break;

default:
    printf("\nOpcao invalida! Tente novamente.\n");//Caso a opcao digitada nao for nenhuma das validas
        break;
}
}
while(opcao!=4);
return 0;
}
