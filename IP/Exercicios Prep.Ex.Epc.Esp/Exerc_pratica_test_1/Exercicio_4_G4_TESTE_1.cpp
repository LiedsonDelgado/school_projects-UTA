#include<stdio.h>
#include<locale.h>
int main(){
setlocale (LC_ALL,"portuguese");//caracteres do Portugues(ex.:acentos,etc)
#define M 100 //define constante M com tamanho max 100
int i,cont=0,n,n_sequencia[M]; //j usado para armazenar valor numa posição do array

printf("Insira Nºs (digite 0-sair)\n");
do{
	printf("Insira um Nº:");
	    scanf("%d",&n);
if(n!=0 && cont<M){
	n_sequencia[cont]=n;
	cont++;
}
}
while(n!=0);

printf("Sequência inserida foi: ");
for(i=0;i<cont;i++){
		printf("%d",n_sequencia[i]);
}
}
