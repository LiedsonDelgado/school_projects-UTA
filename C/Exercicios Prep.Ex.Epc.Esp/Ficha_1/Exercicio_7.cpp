#include<stdio.h>
#include <locale.h>

int main(){
setlocale (LC_ALL,"portuguese");//caracteres do Portugues(ex.:acentos,etc)	

double C,F;
printf("---Calculadora de conversão de temperatura(Celsius para Fahrenheit)---\n");
  printf("Introduza a Temperatura em Graus Celsius:");
     scanf("%lf",&C);
F=(1.8*C)+32;
printf("[ C = %.1lf ]\n",C);
printf("[ F = %.1lf ]",F);

return 0;
}
