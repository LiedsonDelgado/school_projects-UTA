#include<stdio.h>

void ordem_inv(int v[],int *n,int TAM)
{
	if(n>0)
	{
	printf("%d\n",v[TAM-1]);	
	}
	else{
	
	int i;
	for(i=0;i<TAM;i++)
	{
	printf("%d\n",n);	
	}
}

}

main()
{
	int n,v,TAM;
	printf("Introduza um numero:\n");
	scanf("%d",&n);
	
	printf("%d",v);
	ordem_inv(v,&n,TAM);
	
return 0;	
}
