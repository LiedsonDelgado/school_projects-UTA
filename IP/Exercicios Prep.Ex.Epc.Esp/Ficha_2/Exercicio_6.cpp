#include<stdio.h>
#include<locale.h>

int main(){
setlocale (LC_ALL,"portuguese");//caracteres do Portugues(ex.:acentos,etc)	
int x,y;
printf("Insira as Coordenadas de(x,y)\n\n");
     printf("Insira as Coordenadas do Eixo X(EIXO DAS ABCISSAS): ");
         scanf("%d",&x);
     printf("Insira as Coordenadas do Eixo Y(EIXO DAS ORDENADAS):");
         scanf("%d",&y);
//--------------------------------------------------------------------------
//Primeiro Quadrante	  
if(x>0 && y>0){
	printf("\nAs Coordenadas (%d,%d) est�o situadas no Primeiro Quadrante(1� Q)\n",x,y);
}
//Segundo Quadrante
else if(x<0 && y>0){
     printf("\nAs Coordenadas (%d,%d) est�o situadas no Segundo Quadrante(2� Q)\n",x,y);	
}
//Terceiro Quadrante
else if(x<0 && y<0){
     printf("\nAs Coordenadas (%d,%d) est�o situadas no Terceiro Quadrante(3� Q)\n",x,y);
}
//Quarto Quadrante
else if(x>0 && y<0){
     printf("\nAs Coordenadas (%d,%d) est�o situadas no Quarto Quadrante(4� Q)\n",x,y);
     
//Eixos Centrados na ORIGEM
//-------------------------------------------------------------------------------------
}else if(x==0 && y>0){
     printf("\nO ponto Y=%d est� localizado no EIXO DAS ORDENADAS ACIMA DA ORIGEM\n",y);
//------------------------
}else if(x==0 && y<0){
     printf("\nO ponto Y=%d est� localizado no EIXO DAS ORDENADAS ABAIXO DA ORIGEM\n",y);
}
//------------------------
else if(x>0 && y==0){
     printf("\nO ponto X=%d est� localizado no EIXO DAS ABCISSAS � DIREITA DA ORIGEM\n",x);
}
//-----------------------
else if(x<0 && y==0){
     printf("\nO ponto X=%d est� localizado no EIXO DAS ABCISSAS � ESQUERDA DA ORIGEM\n",x);
}
//Origem(0,0)
//-----------------------
else
    printf("\n O ponto est� na Origem (%d,%d)",x,y);
return 0;
}
