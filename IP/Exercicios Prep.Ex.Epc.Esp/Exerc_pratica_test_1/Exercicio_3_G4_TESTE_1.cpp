#include<stdio.h>
#include<locale.h>
int main(){
setlocale (LC_ALL,"portuguese");//caracteres do Portugues(ex.:acentos,etc)
   int a,b,c;
printf("DETERMINE SE UM TRI�NGULO � EQUILATERO,ISOSCELES OU ESCALENO APARTIR DOS 3 LADOS \n");
     printf("Lado A: ");
         scanf("%d",&a);
     printf("Lado B: ");
         scanf("%d",&b);
     printf("Lado C: ");
         scanf("%d",&c);

if((a!=b && a!=c)){
	printf("� um Tri�ngulo Escaleno");//ok
}else if((a==b && a==c)){
	printf("� um Tri�ngulo Equilatero");//ok
}else{
	printf("� um Tri�ngulo Isosceles");//ok
}
}
