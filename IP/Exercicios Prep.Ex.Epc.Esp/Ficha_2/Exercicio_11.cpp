#include<stdio.h>
#include <locale.h>

int main(){
	setlocale (LC_ALL,"portuguese");//caracteres do Portugues(ex.:acentos,etc)
double IMC,Peso,Altura,Q_Altura;//Peso(kg) e Altura (m),Q_Altura <=> Altura^2
printf("CALCULADORA DE IMC(ÍNDICE MASSA CORPORAL)\n\n");
printf("ALTURA: ");
     scanf("%lf",&Altura);
printf("PESO: ");
     scanf("%lf",&Peso);
     
Q_Altura=Altura*Altura;
IMC=Peso/Q_Altura;//Unidade(IMC)=KG/M^2
printf("--IMC(ÍNDICE MASSA CORPORAL):%.1lf kg/m^2\n",IMC);

//Determinar Classificação com Base no IMC
if(IMC>0.0 && IMC<18.5){
	printf("Classificação:Magro\n");
}else if(IMC>=18.5 && IMC<25.0){
	printf("Classificação:Saúdavel\n");
}else if(IMC>=25.0 && IMC<30){
	printf("Classificação:Forte\n");
}
else
	printf("Classificação:Obeso\n");
	return 0;
}
