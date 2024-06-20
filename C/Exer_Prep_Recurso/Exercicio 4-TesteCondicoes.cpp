#include<stdio.h>

main()
{
int a,b,c;
printf("Introduza um primeiro numero:\n");	
	scanf("%d",&a);
printf("Introduza um segundo numero:\n");
	scanf("%d",&b);	
printf("Introduza um terceiro numero:\n");	
	scanf("%d",&c);	
	
if(a>b&&a>c)
printf("O maior numero e %d",a);	
      else if(b>a&&b>c)	
	     printf("O maior numero e %d",b);
	else
	printf("O maior numero e %d",c);
	
}
