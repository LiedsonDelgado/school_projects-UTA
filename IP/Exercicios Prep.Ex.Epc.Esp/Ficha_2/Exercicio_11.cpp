#include<stdio.h>
#include <locale.h>

int main(){
	setlocale (LC_ALL,"portuguese");//caracteres do Portugues(ex.:acentos,etc)
double IMC,Peso,Altura,Q_Altura;//Peso(kg) e Altura (m),Q_Altura <=> Altura^2
printf("CALCULADORA DE IMC(�NDICE MASSA CORPORAL)\n\n");
printf("ALTURA: ");
     scanf("%lf",&Altura);
printf("PESO: ");
     scanf("%lf",&Peso);
     
Q_Altura=Altura*Altura;
IMC=Peso/Q_Altura;//Unidade(IMC)=KG/M^2
printf("--IMC(�NDICE MASSA CORPORAL):%.1lf kg/m^2\n",IMC);

//Determinar Classifica��o com Base no IMC
if(IMC>0.0 && IMC<18.5){
	printf("Classifica��o:Magro\n");
}else if(IMC>=18.5 && IMC<25.0){
	printf("Classifica��o:Sa�davel\n");
}else if(IMC>=25.0 && IMC<30){
	printf("Classifica��o:Forte\n");
}
else
	printf("Classifica��o:Obeso\n");
	return 0;
}
