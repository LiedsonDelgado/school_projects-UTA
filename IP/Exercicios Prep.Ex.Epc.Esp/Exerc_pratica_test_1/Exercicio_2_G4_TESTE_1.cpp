//• sala fria e seca (temperatura < 20 e humidade < 35)-ok
//• sala fria e humida (temperatura < 20 e humidade > 75)-ok
//• sala quente e seca (temperatura > 30 e humidade < 35)-ok
//• sala quente e humida (temperatura > 30 e humidade > 75)-ok

#include<stdio.h>
#include<locale.h>
int main(){
setlocale (LC_ALL,"portuguese");//caracteres do Portugues(ex.:acentos,etc)	
	float temperatura,humidade;
	char porcentagem='%';
printf("Introduza a Temperatura da sala em ºC: ");
scanf("%f",&temperatura);

do{
	printf("Introduza o percentual(%c) da humidade da sala(0-100): ",porcentagem);
	       scanf("%f",&humidade);
}
while((humidade<0) || (humidade>100));
//--------------------------------------------------------------------------------
if((temperatura<20) && (humidade<35)){
printf("\nsala fria e seca\n");	
}
else if((temperatura<20) && (humidade>75)){
printf("\nsala fria e humida\n");	
}
else if((temperatura>30) && (humidade<35)){
printf("\nsala quente e seca\n");	
}else if((temperatura>30) && (humidade>75)){
     printf("\nsala quente e humida\n");
}else{
printf("A sala está em condicoes normais");
}
return 0;
}
