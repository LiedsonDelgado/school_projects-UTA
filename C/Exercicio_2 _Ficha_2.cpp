#include<stdio.h>

void mm(int v[],int *max,int *min,int n)
{
	if(n<=0)
	{
	*min=*max=-1;	
		return;
	}
	int i;
	for(i=0;i<n;i++)
	{
		if(v[i]<*min)
		{
		v[i]=*min;	
		}
		else if(v[i]>*max)
		v[i]=*max;
	}
}

main()
{
	int v,max,min,x,y;
	
	printf("Introduza um numero:\n");
	scanf("%d",&x);
	
	printf("Introduza um numero:\n");
	scanf("%d",&y);
	
	printf("Entre %d e %d o maior eh %d",x,y,&max);
	
void mm(int v[],int *max,int *min,int n);
	return 0;
	
}
