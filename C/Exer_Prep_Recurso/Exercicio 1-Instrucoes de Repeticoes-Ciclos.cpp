#include<stdio.h>

main()
{
	int n_par,n,soma=0;
	printf("Entre 1 e 75:\n");
for(n=1;n<=75;n++){

     if(n%2==0)
         {
	     soma+=n;
         printf("O numero %d eh par\n",n);		
         }
	
}
printf("A soma de todos os numeros pares eh:%d\n",soma);
}
