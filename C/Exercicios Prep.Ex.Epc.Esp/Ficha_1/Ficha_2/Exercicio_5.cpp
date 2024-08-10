#include<stdio.h>
#include<locale.h>

int main(){
setlocale (LC_ALL,"portuguese");//caracteres do Portugues(ex.:acentos,etc)	
int numero;
printf("Insira um número para ver para determinar se é PAR ou ÍMPAR: ");
     scanf("%d",&numero);
if(numero%2==0){
printf("O número %d é PAR\n",numero);
}else
     printf("O número %d é ÍMPAR\n",numero);	  
return 0;
}
