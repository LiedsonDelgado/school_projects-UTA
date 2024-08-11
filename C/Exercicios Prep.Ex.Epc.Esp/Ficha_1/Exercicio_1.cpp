#include<stdio.h>
#include <locale.h>

int main(){
setlocale (LC_ALL,"portuguese");//caracteres do Portugues(ex.:acentos,etc)	
	int idade;
	printf("Introduza a sua Idade: ");
	   scanf("%d",&idade);
	       printf("Idade inserida pelo utilizador é:%d ano(s)",idade);
	return 0;
}
