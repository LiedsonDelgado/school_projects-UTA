#include<stdio.h>
#include <locale.h>

int main(){
setlocale (LC_ALL,"portuguese");//caracteres do Portugues(ex.:acentos,etc)
int n,d;//n=número , d=divisor;

printf("Introduza um nº: ");
     scanf("%d",&n);
printf("Os divisores de %d sao:",n,d);
//------------------------------------------
for(d=1;d<=n;d++){
	if(n%d==0){
		printf("\n> %d",d);
    }
  }
}
