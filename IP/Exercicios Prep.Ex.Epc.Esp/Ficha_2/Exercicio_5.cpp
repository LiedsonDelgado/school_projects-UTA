#include<stdio.h>
#include<locale.h>

int main(){
setlocale (LC_ALL,"portuguese");//caracteres do Portugues(ex.:acentos,etc)	
int numero;
printf("Insira um n�mero para ver para determinar se � PAR ou �MPAR: ");
     scanf("%d",&numero);
if(numero%2==0){
printf("O n�mero %d � PAR\n",numero);
}else
     printf("O n�mero %d � �MPAR\n",numero);	  
return 0;
}
