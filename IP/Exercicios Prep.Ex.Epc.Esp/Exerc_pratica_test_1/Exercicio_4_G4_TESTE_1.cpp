#include<stdio.h>
#include<locale.h>
int main(){
setlocale (LC_ALL,"portuguese");//caracteres do Portugues(ex.:acentos,etc)
#define M 100 //define constante M com tamanho max 100
int i,cont=0,n,n_sequencia[M]; //j usado para armazenar valor numa posi��o do array

printf("Insira N�s (digite 0-sair)\n");
do{
	printf("Insira um N�:");
	    scanf("%d",&n);
if(n!=0 && cont<M){
	n_sequencia[cont]=n;
	cont++;
}
}
while(n!=0);

printf("Sequ�ncia inserida foi: ");
for(i=0;i<cont;i++){
		printf("%d",n_sequencia[i]);
}
}
