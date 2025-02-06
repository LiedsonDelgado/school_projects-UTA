#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include <locale.h>

int main(){
setlocale (LC_ALL,"portuguese");//caracteres do Portugues(ex.:acentos,etc)	
int x,mod;
double e=2.718,b1,r1,r2;//Valor do Nepar e=2,72

printf("f(x)=1/x.e^x se x>0\n");
printf("       e^|x| se x<=0\n\n");
     printf("Introduza um valor X: ");
         scanf("%d",&x);
         
if(x>0){//CASO 1 se x>0
r1=(1.0/x)*pow(e,x); //Resultado Final (a^x) do Caso 1
	 printf("f(%d)=1/%d.e^%d se x>0 = %.2lf\n",x,x,x,r1);
}

else{//CASO 2 se x<=0
mod=abs(x);   // |x| (modulo de x)
r2=pow(e,mod);
     printf("f(%d)=e^|%d| se x<=0 = %.2lf",x,x,r2); 
}
return 0;
}
