#include<stdio.h>
#include <locale.h>

int main(){
setlocale (LC_ALL,"portuguese");//caracteres do Portugues(ex.:acentos,etc)

int c1=0,c2=0,c3=0,c4=0,c5=0,c6=0; //variavel c1,c2,c3,c4,c5,c6 usado como contador
int i,n,quantidade;

printf("Introduza uma quantidade de nºs a serem inseridos: ");
     scanf("%d",&quantidade);
printf("Introduza os %d nºs\n",quantidade);
//-------------------------------------------------------------------------
for(i=0;i<quantidade;i++){
	printf("\nIntroduza o %dº nº: ",i+1);
	     scanf("%d",&n);
//-------------------------------------------------------------------------
if(n<=0){
	 c1++;
}else if(n>0 && n<=25){
	 c2++;
}else if(n>25 && n<=50){
	 c3++;
}else if(n>50 && n<=75){
	 c4++;
}else if(n>75 && n<=100){
	 c5++;
}else{
	 c6++;
}
}
//--------------------------------------
printf("\nNo Intervalo ]-8,0] tem %d nº(s)\n",c1);
printf("No Intervalo [0,25] tem %d nº(s)\n",c2);
printf("No Intervalo [25,50[ tem %d nº(s)\n",c3);
printf("No Intervalo [50,75] tem %d nº(s)\n",c4);
printf("No Intervalo [75,100] tem %d nº(s)\n",c5);
printf("No Intervalo [100,-8[ tem %d nº(s)\n",c6);
}
