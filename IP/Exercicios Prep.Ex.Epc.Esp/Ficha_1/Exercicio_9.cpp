#include<stdio.h>
#include<locale.h>

int main(){
setlocale (LC_ALL,"portuguese");//caracteres do Portugues(ex.:acentos,etc)
     double salario,salario_min,total_sal_min;
printf("Qual o Salario/M�s(CVE):");
     scanf("%lf",&salario);
printf("Qual o Salario Minimo/M�s(CVE):");
     scanf("%lf",&salario_min);
     
	 total_sal_min=salario/salario_min;
         printf("Vc ganha aproximadamente %.0lf Sal�rio(s)",total_sal_min);
return 0;
}
