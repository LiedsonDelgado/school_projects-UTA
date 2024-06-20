#include<stdio.h>

main()
{
int x,y;
printf("Insira a coordenada x:\n");
	scanf("%d",&x);
printf("Insira a coordenada y:\n");
	scanf("%d",&y);
	
if(x>0&&y>0)//1st quadrante
printf("A coordenadas (%d,%d) estao no 1st quadrante\n",x,y);

if(x<0&&y>0)//2nd quadrante
printf("A coordenadas (%d,%d) estao no 2nd quadrante\n",x,y);
	 	
if(x<0&&y<0)//3rd quadrante
printf("A coordenadas (%d,%d) estao no 3rd quadrante\n",x,y);
		     
if(x>0&&y<0)//4th quadrante		         
printf("A coordenadas (%d,%d) estao no 4th quadrante\n",x,y);

if(x==0&&y>0||x==0&&y<0)//x centrado em 0
printf("A coordenadas (%d,%d) esta com o x centrado em 0(origem)\n",x,y);
	             
if(x>0&&y==0||x<0&&y==0)//y centrado em 0
printf("As coordenadas (%d,%d) esta com o y centrado em 0(origem)\n",x,y);
	
	else if(x==0&&y==0)
	printf("As coordenadas (x,y) estao centradas na origem(%d,%d)\n",x,y);
}
