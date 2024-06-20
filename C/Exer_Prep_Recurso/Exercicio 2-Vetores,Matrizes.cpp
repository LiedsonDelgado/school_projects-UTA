#include<stdio.h>

const int NUMELEMS=3;

int soma_vetor(int v[],int tamanho)
{
	int i,soma=0;
	for(i=0;i<NUMELEMS;i++)
	{
		printf("Posicao v[%d] ==> Elemento %d;\n",i,v[i]);
			soma+=v[i];
	}
return soma;
}

void ler_Vetor(int v[],int tamanho)
{
int i;
for(i=0;i<NUMELEMS;i++)
{
printf("Introduza o elemento %d vetor:\n",i);
scanf("%d",&v[i]);	
}

}

int main()
{
	int i;
	int v[NUMELEMS];
	int tamanho=NUMELEMS;
printf("---Soma Elementos Vetor---\n\n");
     ler_Vetor(v,tamanho);
     int resultado=soma_vetor(v,tamanho);
     printf("\nResultado da Soma: %d\n",resultado);
}
