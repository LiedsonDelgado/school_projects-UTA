#include<stdio.h>

float media(int x,int y,int z)
{
float media=x+y+z;
     if(media>=0)
     {
     printf("A media eh:%.1f",media/3);
     }
     else
         printf("Nao pode ser calculado");

}

int main()
{
int x,y,z;

	
printf("Introduza um numero:\n");
     scanf("%d",&x);	

printf("Introduza um numero:\n");
     scanf("%d",&y);	

printf("Introduza um numero:\n");
     scanf("%d",&z);
	
	return media(x,y,z);
}
