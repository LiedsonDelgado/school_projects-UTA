#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct
{ /*Estrutura que ir� armazenar informa��es de uma requisi��o*/
	
	char nomeUsuario[50];
	char equipamento[50];
	int estado;
	int devolvido;

}Requisicao;

void adicionarRequisicao(Requisicao requisicoes[],int*contador)/*Fun��o para adicionar requisi��o*/
{
printf("Nome do Usuario: ");	
	scanf("%s",requisicoes[*contador].nomeUsuario);
printf("Nome do Equipamento: ");	
	scanf("%s",requisicoes[*contador].equipamento);
	     requisicoes[*contador].estado=0;
	     requisicoes[*contador].devolvido=0;
	     (*contador)++;
}
void aprovar_requisicao(Requisicao*req)
{
   requisicoes->estado=1;
    printf("a requisicao de %s foi aprovada\n",requisicoes.nome_usuario);
}
main(){
}
