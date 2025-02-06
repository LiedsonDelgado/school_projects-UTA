#include<stdio.h>
#include <locale.h>

int main(){
setlocale (LC_ALL,"portuguese");//caracteres do Portugues(ex.:acentos,etc)	

    double dolar,cve=101.02,total_cve;
printf("Converter DÓLAR(USD) para ESCUDOS CABO VERDIANOS(CVE)");
    printf("\nQuantia de Dólare(s):");
     scanf("%lf",&dolar);
       total_cve=dolar*cve;   
         printf("%.2lf USD = %.2lf CVE",dolar,total_cve);	
              return 0;
}
