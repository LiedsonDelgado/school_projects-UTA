#include<stdio.h>

void ordem(int N)
{
	if(N<0)
         return;
         
		 else{
	        printf("%d",N);
	        ordem(N-1);
	    }
}

main()
{
	int N;
	 printf("Introduza um numero:\n");
	     scanf("%d",&N);
         ordem(N);
	return 0;
}
