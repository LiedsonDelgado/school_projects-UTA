#include<stdio.h>

const int NUMELEMS=3;

void ler_Vetor(int v[])
{
	int i;
	for(i=0;i<NUMELEMS;i++)
	{
     printf("Introduza o elemento %d do vetor:",i+1);
     	scanf("%d",&v[i]);
	}
}

void escrever_Vetor(int v[])
{
	int i;
	
printf("\nVetor:");
printf("{");
	for(i=0;i<NUMELEMS;i++)
	{
     printf("%d,",v[i]);
	}
printf("}");
printf("\n");
}

int main()
{
int v[NUMELEMS];
printf("Introduza os elementos do Vetor:\n");

ler_Vetor(v);	
escrever_Vetor(v);	
	
	return 0;
}
