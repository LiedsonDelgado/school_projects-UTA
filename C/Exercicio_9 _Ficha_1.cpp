#include<stdio.h>

int ackermann(int m,int n)
{
	if(m=0)
	{
		return ackermann(m,n+1);
		printf("%d,%d",m,n);
	}
	else if(n=0)
	{
		return ackermann(m-1,1);
	}
	else if(n>0&&m>0)
    {
    	return ackermann(m-1,ackermann(m,n-1));
    }
}

main()
{
	int m,n;
	printf("Introduza M inteiro positivo:\n");
	scanf("%d",&m);
	
	printf("Introduza N inteiro positivo:\n");
	scanf("%d",&n);
	
	int resultado=ackermann(m,n);
	printf("Resultado:%d%d%d",resultado);
	return 0;
}
