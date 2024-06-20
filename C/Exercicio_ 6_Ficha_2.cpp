#include<stdio.h>
#include<stdlib.h>

typedef struct{
	
	float n_real;	
	float n_imaginario;

}Complexo;

Complexo complexo_soma(Complexo a,Complexo b)
{	

Complexo soma;
soma.n_real=a.n_real+b.n_real;
soma.n_imaginario=a.n_imaginario+b.n_imaginario;

return soma;

}


int main(){
	Complexo num_1,num_2,resultado;
	
	printf("Insira numero 1 <=> x+yi:\n");
	     scanf("%f+%fi",&num_1.n_real,&num_1.n_imaginario);
	
	printf("Insira numero 2 <=> x+yi:\n");
	     scanf("%f+%fi",&num_2.n_real,&num_2.n_imaginario);
	
	resultado=complexo_soma(num_1,num_2);
	
	printf("A soma dos Numeros Complexos e:\n");
	printf("%.1f+%.1fi",resultado.n_real,resultado.n_imaginario);

return 0;
}
