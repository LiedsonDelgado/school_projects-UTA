#include<stdio.h>

main()
{
	int n,divisor;
	printf("Introduza um numero:");
	     scanf("%d",&n);
	     
	 printf("Os divisores de %d sao:\n",n);
for(divisor=1;divisor<=n;divisor++)

{
if(n%divisor==0)
     printf("%d\n",divisor);  

 }
}
