#include<stdio.h>
#include <locale.h>

int main(){
setlocale (LC_ALL,"portuguese");//caracteres do Portugues(ex.:acentos,etc)
     double nota_1,nota_2,nota_3,nota_final;
          printf("Nota 1:");
              scanf("%lf",&nota_1);             
          printf("Nota 2:");
              scanf("%lf",&nota_2);              
          printf("Nota 3:");
              scanf("%lf",&nota_3);
          
nota_final=(nota_1+nota_2+nota_3)/3;
     printf("A nota final do Aluno(Média):%0.lf",nota_final);
return 0;
}
