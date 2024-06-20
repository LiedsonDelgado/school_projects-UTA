#include<stdio.h>

float temperatura,resultado;
char opcao;
main()
{
printf("--Opcoes--\n");
printf("1.Celsius\n");
printf("2.Fahrenheit\n\n");

printf("Escolha Opcao Conversao de Temperatura:\n");	
scanf("%s",&opcao);

	 switch(opcao)
	 { 	
     case 'C':
	 case 'c':
	 printf("\nIntroduza a temperatura em Fahrenheit:\n");
	 scanf("%f",&temperatura);
	 
	     resultado=(temperatura-32)*5/9;
         printf("%2.fF foi convertida para %.1fC\n",temperatura,resultado);
                 break;
         
     case 'F':
	 case'f':
     printf("\nIntroduza a temperatura em Celsius:\n");
	 scanf("%f",&temperatura);
	 	
         resultado=(temperatura*9/5)+32;
         printf("%2.fC foi convertida para %.1fF",temperatura,resultado);
                  break;
     }
return 0;
}
