#include<stdio.h>
#include <locale.h>

int main(){
setlocale (LC_ALL,"portuguese");//caracteres do Portugues(ex.:acentos,etc)
int n,i=1,soma=0;

do{
	printf("Introduza um nº: ");
     scanf("%d",&n);
	soma=soma+n;
	i=i+1;
}
while(i<=5);

printf("O total é %d",soma);
}
