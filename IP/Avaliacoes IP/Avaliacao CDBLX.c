/*Este programa ira calcular o seu PESO IDEAL com base no seu SEXO e a ALTURA*/
#include<stdio.h>
int main(){
float peso_ideal;
char sexo;
int altura;

printf("O seu sexo: \n");
scanf("%c",&sexo);
printf("A sua altura em centimetros: \n");
scanf("%d",&altura);

switch(sexo){
	case'f': case'F':
	peso_ideal=altura*0.85-85;
	printf("O seu peso ideal e %.2f Kg \n",peso_ideal);

	case'm': case'M':
	peso_ideal=altura*0.95-95;
	printf("O seu peso ideal e %.2f Kg \n",peso_ideal);
break;
defaul:
     printf("");
}
return 0;


}
