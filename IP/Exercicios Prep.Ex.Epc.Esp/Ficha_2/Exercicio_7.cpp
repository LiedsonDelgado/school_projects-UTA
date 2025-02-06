#include<stdio.h>
#include <locale.h>

int main(){
setlocale (LC_ALL,"portuguese");//caracteres do Portugues(ex.:acentos,etc)	
int pontuacao;
printf("Introduza uma Pontuação(0 a 20): ");
     scanf("%d",&pontuacao);
//------------------------
if(pontuacao<10 && pontuacao>=0){
	printf("\nInsuficiente\n");
}else if(pontuacao>=10 && pontuacao<13){
	printf("Suficiente\n");
}else if(pontuacao>=13 && pontuacao<16){
	printf("Bom\n");
}else if(pontuacao>=16 && pontuacao<19){
	printf("Notavel\n");
}else if(pontuacao>=19 && pontuacao<21){
	printf("Sobresaliente\n");
}
else
     printf("ERRO!!! Classificação %d está fora do Intervalo(0 a 20).Tente novamente\n",pontuacao);
return 0;
}
