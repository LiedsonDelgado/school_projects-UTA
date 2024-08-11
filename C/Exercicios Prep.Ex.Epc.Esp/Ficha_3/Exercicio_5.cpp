#include<stdio.h>
#include <locale.h>

//Usando WHILE
int main(){
setlocale (LC_ALL,"portuguese");//caracteres do Portugues(ex.:acentos,etc)
  int i=1,N,fact=1;
  printf("Calcule !N\n");
      printf("Introduza o valor de N: ");
         scanf("%d",&N); 
//---------------------------------------    
  while(i<=N){
  	fact*=i;
  	i++;
}
printf("%d! = %d",N,fact);
    return 0;
}
//--------------------------------------------------------------------------
//Usando FOR
int main(){
setlocale (LC_ALL,"portuguese");//caracteres do Portugues(ex.:acentos,etc)
  int i,N,fact=1;
  printf("Calcule !N\n");
      printf("Introduza o valor de N: ");
         scanf("%d",&N); 
//---------------------------------------    
for(i=1;i<=N;i++){
fact*=i;
}
printf("%d! = %d",N,fact);
    return 0;
}
