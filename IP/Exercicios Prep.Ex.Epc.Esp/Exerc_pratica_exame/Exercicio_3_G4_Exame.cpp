#include<stdio.h>

int produto(int v1[],int v2[],int t){
	int soma=0;
	int i;
for(i=0;i<t;i++){
soma+=v1[i]*v2[i];	
}
return soma;
}

int main(){
	int resultado;
	//TESTE DE VALORES PARA OS VETORES ou INTRODUZIR VALORES MANUALMENTE PARA EFETUAR O CALCULO PS:Pedindo o tamanho do vetor
   int v1[] = {0, 2, 4};
    int v2[] = {1, 3, 5};
    int t=3;
    //*OU
    //*int t = sizeof(v1) / sizeof(v1[0]); // Calcula o tamanho dos vetores  
resultado=produto(v1, v2, t);    
    printf("O produto dos vetores e: %d\n", resultado);
         return 0;
}
