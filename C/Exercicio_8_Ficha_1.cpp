#include<stdio.h>

int potencia(int n,int x){
	if(n==0){
return 1;
}
else if(n>0){
return x * potencia(n-1,x);
}
else{
return 1*(x*potencia(-n,x));
}
}

int main()
{
	int x,n;
printf("Introduza uma Base:\n");
scanf("%d",&x);

printf("Introduza um Expoente:\n");
scanf("%d",&n);

int resultado=potencia(n,x);
printf("Resultado(%d^%d):%d",x,n,resultado);
	
	return 0;
}
