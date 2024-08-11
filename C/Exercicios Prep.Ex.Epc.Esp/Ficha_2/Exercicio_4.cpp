#include<stdio.h>
#include <locale.h>
//Usando o Operador Ternario(?)
int main(){
setlocale (LC_ALL,"portuguese");//caracteres do Portugues(ex.:acentos,etc)	
int n1,n2,n3,maior;
   printf("Introduza o primeiro número: ");
        scanf("%d",&n1);
   printf("Introduza o segundo número: ");
        scanf("%d",&n2);
   printf("Introduza o terceiro número: ");
        scanf("%d",&n3);

maior=(n1>n2) ? (n1>n3 ? n1:n3):(n2>n3 ? n2:n3);
     printf("O maior número é: %d",maior);
 
return 0;
}
//----------------------------------------------------------------------------
//Sem Usar o Operador ternario
int main(){
setlocale (LC_ALL,"portuguese");//caracteres do Portugues(ex.:acentos,etc)	
int n1,n2,n3,maior;
   printf("Introduza o primeiro número: ");
        scanf("%d",&n1);
   printf("Introduza o segundo número: ");
        scanf("%d",&n2);
   printf("Introduza o terceiro número: ");
        scanf("%d",&n3);
        
if(n1>n2&&n1>n3){
	printf("O maior número é: %d",n1);
}
//-------------------------------------
else if(n2>n1&&n2>n3){
	printf("O maior número é: %d",n2);
	}
//-------------------------------------
else if(n3>n1&&n3>n2){
	printf("O maior número é: %d",n3);
}
return 0;
}
