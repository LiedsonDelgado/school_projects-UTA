#include<stdio.h>
#include <locale.h>

int main(){
setlocale (LC_ALL,"portuguese");//caracteres do Portugues(ex.:acentos,etc)	

int dias_atraso,multa=250,total_multa;//multa=250CVE/dia
   printf("---Entrega dos Livros(BIBLIOTECA DO ISECMAR)---\n");
         printf("Quantos dias vc esta atrasado para entregar os Livros:");
          scanf("%d",&dias_atraso);
//--------------------------------------------------------------------------------------------------------          
          if(dias_atraso>0){
          	total_multa=dias_atraso*multa;
          	printf("\nVc pagara uma multa de %d CVE pelos %d dia(s) de atraso",total_multa,dias_atraso);
		  }
//--------------------------------------------------------------------------------------------------------		  
		      else
		         printf("\nQue bom que vc os entregou a tempo!!!Então vc não pagará a multa");
return 0;
}
