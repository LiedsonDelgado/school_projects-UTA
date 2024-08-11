#include<stdio.h>
#include <locale.h>

int main(){
setlocale (LC_ALL,"portuguese");//caracteres do Portugues(ex.:acentos,etc)	
 int numero;
   printf("Introduza um numero: ");
      scanf("%d",&numero);
      
if(numero>0){
     printf("%d é POSITIVO\n",numero);
}else if(numero<0){
     printf("%d é NEGATIVO",numero);
	 }else
	     printf("%d é igual a 0",numero);	  
return 0;
}
