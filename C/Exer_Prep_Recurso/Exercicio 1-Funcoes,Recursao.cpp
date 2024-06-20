#include<stdio.h>

int maior(int a,int b,int c)
{
	 if(a>b&&a>c)
	 printf("%d eh maior que %d e %d\n",a,b,c);
	     
		 else if(b>a&&b>c)
	     printf("%d eh maior que %d e %d\n",b,a,c);
	     
		 else if(c>a&&c>b)
	     printf("%d eh maior que %d e %d\n",c,a,b);	
	      	 else
	         printf("Os %d=%d=%d",a,b,c);
}
int main()
{
	int a,b,c;
	
	printf("Introduza um numero:\n");
	 scanf("%d",&a);
	
	printf("Introduza um numero:\n");
	 scanf("%d",&b);
	
	printf("Introduza um numero:\n");
	 scanf("%d",&c);
	 
	 maior(a,b,c);
}
