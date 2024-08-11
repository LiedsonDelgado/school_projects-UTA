#include<stdio.h>
#include <locale.h>

int main(){
setlocale (LC_ALL,"portuguese");//caracteres do Portugues(ex.:acentos,etc)	
 
 double C,F;
 char escolha;
 printf("Escolha 'C' para converter de Fahrenheit para Celsius\n");
 printf("Escolha 'F' para converter de Celsius para Fahrenheit\n");
     printf("Sua Escolha: ");
          scanf("%c",&escolha);

switch(escolha){
	case 'C':
	     case'c':
			printf("Introduza a temperatura em Fahrenheit: ");
			      scanf("%lf",&F);
			           C=(F-32)*5/9;
			           printf("A temperatura em Celsius: %.1lf\n",C);
			             break;
//-----------------------------------------------------------------------			      
	case 'F':
		case'f':
			printf("Introduza a temperatura em Celsius: ");
			      scanf("%lf",&C);
			           F=(C*9/5)+32;
			           printf("A temperatura em Fahrenheit: %.1lf\n",F);
					     break;				
}          
	return 0;
}
