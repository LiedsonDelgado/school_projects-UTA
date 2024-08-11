#include<stdio.h>
#include <locale.h>


int main(){
setlocale (LC_ALL,"portuguese");//caracteres do Portugues(ex.:acentos,etc)	
   
   double euro,cve,total_cve;
printf("Introduza a cotação do EURO(€) em ESCUDOS CABO VERDIANOS(CVE): ");
     scanf("%lf",&cve);

printf("Quantos (€)EURO(S) vc tem na sua conta: ");
     scanf("%lf",&euro);
         
		 total_cve=euro*cve;
         printf("\nEntao vc tem %.0lf (€)EURO(S)....equivalente a %.2lf ESCUDOS CABO VERDIANOS(CVE)",euro,total_cve);  	

return 0;
}
