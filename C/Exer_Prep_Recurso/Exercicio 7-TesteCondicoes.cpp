#include<stdio.h>

int main()
{
	int h_trabalho,n_filhos;
	int salario_h=500;
	
	float salario_total;
	printf("Quantas Horas de Trabalho:\n");
	scanf("%d",&h_trabalho);
	
	printf("Quantos Filhos:\n");
	scanf("%d",&n_filhos);
	
if(n_filhos>0)
{
     salario_total=salario_h*h_trabalho+(salario_h*h_trabalho*0.03*n_filhos);
	 printf("Salario Total:%.1f\n",salario_total);
}
		 else
		 {
         salario_total=salario_h*h_trabalho;
		 printf("Salario Total:%.1f",salario_total);
	     }
}
