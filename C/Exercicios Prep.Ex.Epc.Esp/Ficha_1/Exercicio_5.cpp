#include<stdio.h>
#include <locale.h>
#include<math.h>

int main(){
setlocale (LC_ALL,"portuguese");//caracteres do Portugues(ex.:acentos,etc)		
      double a,b,hip;
printf("-Calcule a Hipotenusa(HIP)de um triângulo\n");
printf("-H^2=Ca^2+Co^2\n");
//--------------------------------------------------------------------------
     printf("\n(Cateto Oposto)Cop =");
         scanf("%lf",&a);//catateto oposto(co)=a;
     printf("(Cateto Adjacente)Cap =");
         scanf("%lf",&b);//catateto odjacente(ca)=b;
//--------------------------------------------------------------------------
double total_cat_op=a*a;//a*a=a^2=Ca^2
double total_cat_adj=b*b;//b*b=b^2=Cb^2
hip=total_cat_op+total_cat_adj;//Hip=Ca^2+Co^2
     double raiz=sqrt(hip);//RaizQuadrada de Hip
//--------------------------------------------------------------------------     
printf("\nA Hipotenusa de Co=%.1lf e Cadj=%.1lf =%.2lf\n",a,b,raiz);

printf("\nH^2=Ca^2+Co^2\n");
printf("H^2= %.1lf + %.1lf\n",total_cat_op,total_cat_adj);
printf("H^2=%.1lf\n",hip);
printf("H=sqrt(%.1lf)\n",hip);
printf("H=%.2lf",raiz);
return 0;
}
