#include<stdio.h>
#include<stdlib.h>

typedef struct{
	
	float n_real;	
	float n_imaginario;

}Complexo;

int main(){
	Complexo num_1,num_2;
	
	printf("Insira numero <=> x+yi:\n");
	     scanf("%f+%fi",&num_1.n_real,&num_1.n_imaginario);
	
	printf("Insira numero <=> x+yi:\n");
	     scanf("%f+%fi",&num_2.n_real,&num_2.n_imaginario);
	
	printf("Os Numeros Complexos sao:\n");
	             printf("Numero 1:%.0f+%.0fi\n",num_1.n_real,num_1.n_imaginario);
	             
	             printf("Numero 2:%.0f+%.0fi\n",num_2.n_real,num_2.n_imaginario);
	
	
}
