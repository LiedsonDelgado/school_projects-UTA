#include<stdio.h>
#include <locale.h>

int main(){
setlocale (LC_ALL,"portuguese");//caracteres do Portugues(ex.:acentos,etc)	
     int x,y;
printf("Introduza 2 n�meros para obter as 4 (+1 operacao extra)opera��es b�sicas\n");
     printf("PRIMEIRO N�MERO: ");
          scanf("%d",&x);
     printf("SEGUNDO N�MERO: ");
          scanf("%d",&y);
             printf("%d+%d=%d\n",x,y,x+y);
             printf("%d-%d=%d\n",x,y,x-y);
             printf("%d*%d=%d\n",x,y,x*y);
             printf("(DIVISAO INTEIRA) %d/%d=%d\n",x,y,x/y);
             printf("(RESTO DE DIVISAO) %d por %d=%d\n",x,y,x%y);
	             return 0;
}
