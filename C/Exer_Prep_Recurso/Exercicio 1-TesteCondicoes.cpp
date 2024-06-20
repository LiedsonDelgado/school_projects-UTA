#include<stdio.h>
int i;
int main()
{
printf("Introduza a sua idade:\n");
scanf("%d",&i);

if(i>=18)
   printf("Tem %d anos,entao tem idade para conduzir legalmente.",i);
        else
         printf("Nao tem idade para conduzir legalmente.");
}
