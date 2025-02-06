#include<stdio.h>
#include <locale.h>

int main(){
setlocale (LC_ALL,"portuguese");//caracteres do Portugues(ex.:acentos,etc)
double preco_carne=400,consumo_carne_individual=0.350,preco_cerveja=120,n_pessoas,gasto_total;  //preco/kg carne=400$(1kg carne=400$), preço 
                                                                                               //cerveja=250$(1 cerveja=250$)/consumo de carne
                                                                                              //pessoa 350g de 1000g(0,350 kg de 1kg)

     printf("Quantas pessoas irão para o churrasco:");
         scanf("%lf",&n_pessoas);
         
	gasto_total=consumo_carne_individual*n_pessoas*preco_carne+preco_cerveja*n_pessoas;
	printf("O gasto total sera de %.2lf",gasto_total);
	return 0;
}
