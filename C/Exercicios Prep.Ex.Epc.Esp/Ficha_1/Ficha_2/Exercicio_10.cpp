#include<stdio.h>
#include <locale.h>

int main(){
setlocale (LC_ALL,"portuguese");//caracteres do Portugues(ex.:acentos,etc)	
int mes,ano;
printf("Introduza uma Data\n");
printf("Introduza o Número do Mês: ");
     scanf("%d",&mes);
printf("Introduza o Ano: ");
     scanf("%d",&ano);
     
if(ano%4==0 && ano%100!=0 || ano%400){
 switch(mes){
	case 1:
		printf("Janeiro(%d) tem 31 dias\n",mes);
		printf("O ano de %d é Bissexto",ano);
		break;
    case 2:
    	printf("Fevereiro(%d) tem 29 dias\n",mes);
    	printf("O ano de %d é Bissexto\n",ano);
    	break;
    case 3:
    	printf("Março(%d) tem 31 dias\n",mes);
    	printf("O ano de %d é Bissexto\n",ano);
		break;
    case 4:
    	printf("Abril(%d) tem 30 dias\n",mes);
    	printf("O ano de %d é Bissexto\n",ano);
    	break;
    case 5:
    	printf("Maio(%d) tem 31 dias\n",mes);
    	printf("O ano de %d é Bissexto\n",ano);
    	break;
    case 6:
    	printf("Junho(%d) tem 30 dias\n",mes);
    	printf("O ano de %d é Bissexto\n",ano);
    	break;
    case 7:
    	printf("Julho(%d) tem 31 dias\n",mes);
    	printf("O ano de %d é Bissexto",ano);
    	break;
    case 8:
    	printf("Agosto(%d)tem 31 dias\n",mes);
    	printf("O ano de %d é Bissexto",ano);
    	break;
    case 9:
    	printf("Setembro(%d) tem 30 dias\n",mes);
    	printf("O ano de %d é Bissexto\n",ano);
    	break;
    case 10:
    	printf("Outubro(%d)tem 31 dias\n",mes);
    	printf("O ano de %d é Bissexto\n",ano);
    	break;
    case 11:
    	printf("Novembro(%d)tem 30 dias\n",mes);
    	printf("O ano de %d é Bissexto\n",ano);
    	break;
    case 12:
    	printf("Dezembro(%d)tem 31 dias\n",mes);
    	printf("O ano de %d é Bissexto\n",ano);
    	break;
default:
     printf("ERRO!!! O Mês %d não existe.Tente novamente\n",mes);
}
}else{
	switch(mes){
	case 1:
		printf("Janeiro(%d) tem 31 dias\n",mes);
		printf("O ano de %d é uma ano comum",ano);
		break;
    case 2:
    	printf("Fevereiro(%d) tem 28 dias\n",mes);
    	printf("O ano de %d é uma ano comum\n",ano);
    	break;
    case 3:
    	printf("Março(%d) tem 31 dias\n",mes);
    	printf("O ano de %d é uma ano comum\n",ano);
    	break;
    case 4:
    	printf("Abril(%d) tem 30 diasn\n",mes);
    	printf("O ano de %d é uma ano comum\n",ano);
    	break;
    case 5:
    	printf("Maio(%d) tem 31 dias\n",mes);
    	printf("O ano de %d é uma ano comum\n",ano);
    	break;
    case 6:
    	printf("Junho(%d) tem 30 dias\n",mes);
    	printf("O ano de %d é uma ano comum\n",ano);
    	break;
    case 7:
    	printf("Julho(%d) tem 31 dias\n",mes);
    	printf("O ano de %d é uma ano comum",ano);
    	break;
    case 8:
    	printf("Agosto(%d)tem 31 dias\n",mes);
    	printf("O ano de %d é uma ano comum\n",ano);
    	break;
    case 9:
    	printf("Setembro(%d) tem 30 dias\n",mes);
    	printf("O ano de %d é uma ano comum\n",ano);
    	break;
    case 10:
    	printf("Outubro(%d)tem 31 dias\n",mes);
    	printf("O ano de %d é uma ano comum\n",ano);
    	break;
    case 11:
    	printf("Novembro(%d)tem 30 dias\n",mes);
    	printf("O ano de %d é uma ano comum\n",ano);
    	break;
    case 12:
    	printf("Dezembro(%d)tem 31 dias\n",mes);
    	printf("O ano de %d é uma ano comum\n",ano);
    	break;
default:
     printf("ERRO!!! O Mês %d não existe.Tente novamente\n",mes);
}
}
	return 0;
}
