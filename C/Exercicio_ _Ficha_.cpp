#include<stdio.h>
int fact(int n){
	if(n==0||n==1){
		return 1;
	}
	else
	return n*fact(n-1);
}

main(){
	int n;
	printf("!");
	scanf("%d",&n);
	
	fact(n);
	int r_fact=fact(n);
	
	printf("\n%d!=%d",n,r_fact);
	
}
