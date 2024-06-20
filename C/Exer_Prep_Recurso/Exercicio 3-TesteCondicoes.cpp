#include<stdio.h>

main()
{
int n;
printf("Introduza um numero:\n");	
	scanf("%d",&n);
	
if(n>0)	
printf("%d eh positivo",n);
     else if(n==0)
         printf("O numero introduzido eh o zero");
          else
             printf("%d eh negativo",n);
}
