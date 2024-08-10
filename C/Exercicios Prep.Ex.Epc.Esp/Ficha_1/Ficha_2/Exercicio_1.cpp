#include<stdio.h>
#include <locale.h>

int main(){
setlocale (LC_ALL,"portuguese");//caracteres do Portugues(ex.:acentos,etc)	
 int idade;
printf("Qual a sua idade? ");
     scanf("%d",&idade);
if(idade>=18){
	printf("Tem idade suficiente para conduzir legalmente\n");
}
     else
         printf("Não tem idade suficiente para conduzir legalmente");
	return 0;
}
