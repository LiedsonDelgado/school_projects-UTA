#include<stdio.h>

int numero(int a,int b)
{
	if(a<b)
	printf("%d eh o maior numero",b);
	   else if(a>b)
	     printf("%d eh o maior numero",a);
	     else
	     printf("%d eh igual %d",a,b);
}

main()
{
int a,b,n;
	printf("Introduza um numero:\n");
	scanf("%d",&a);
	
	printf("Introduza um numero n:\n");
	scanf("%d",&b);

numero(a,b);	
}
