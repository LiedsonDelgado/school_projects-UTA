#include<stdio.h>
#include<math.h>
#include <locale.h>

int main(){
setlocale (LC_ALL,"portuguese");//caracteres do Portugues(ex.:acentos,etc)	
int a,b,c,res_b,res_4ac,raiz,delta,b_r; //res_b <=>b^2, raiz_inside calculo de tudo dentro da raiz, b_r=-b V -(-b),raiz calcula a raiz quadrada do delta(discriminante)
double x1,x2;
printf("CALCULE A EQUACÃO DO 2ºGRAU ( x=ax^2+bx+c )\n\n");//,onde c é uma constante
     printf("Introduza o valor de ax^2: ");
         scanf("%d",&a);
     printf("Introduza o valor de bx: ");
         scanf("%d",&b);
     printf("Introduza o valor de c: ");
         scanf("%d",&c);
//-----------------------------------------
res_b=b*b;
res_4ac=-4*a*c;
delta=res_b-(-res_4ac);
//----------------------------------------
if(delta>=0){
	raiz=sqrt(delta);
	b_r=-b;
x1=(b_r+raiz)/(2*a);
x2=(b_r-raiz)/(2*a);

printf("\nOs valores das raizes X1=%.2lf e X2=%.2lf",x1,x2);  
	
}else{
printf("\nNão é possivel calcular a raiz de um nº negativo\n");
}
	return 0;
}
