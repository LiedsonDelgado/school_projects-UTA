#include<stdio.h>

int ordem_inversa(int v[],int n)
{
	if(n==0)
	{
		printf("%d\n",v[n]);
	}
	else
	{
		printf("%d",v[n]);
		ordem_inversa(v,n-1);
	}
}

int main()
{
	int n;
	int v[n];
	
printf("Tamanho do vetor:\n");
scanf("%d",&n);

 printf("Elementos do vetor:\n");
    for(int i=0;i<n;i++) {
        scanf("%d",&v[i]);
		}

ordem_inversa(v,n-1);

}
