#include<stdio.h>

int potencia(int n){
	if(n==0)
	 return 1;
	
	else
	 return 2*potencia(n-1);
}

main()
{
	int n;
 	printf("--2^n--\n");
	     printf("Escolha o (n):\n");
	         scanf("%d",&n);
	             int ptc=potencia(n);
	printf("\n2^%d=%d",n,ptc);
	 return 0;
}
