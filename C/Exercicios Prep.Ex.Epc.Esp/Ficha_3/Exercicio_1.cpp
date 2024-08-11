#include<stdio.h>
#include <locale.h>

int main(){
setlocale (LC_ALL,"portuguese");//caracteres do Portugues(ex.:acentos,etc)
int n,n_par,soma=0;

printf("Soma dos Nºs pares entre 1 a 75\n");
for(n=1;n<=75;n++){
   if(n%2==0){
   	printf("%d é par\n",n);
   	soma+=n;
   }
}
printf("\nA soma dos Nºs pares de 1 a 75 = %d\n",soma);
}
