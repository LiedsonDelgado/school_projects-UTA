#include<stdio.h>
#include <locale.h>

//USANDO IF-ELSE
int main(){
setlocale (LC_ALL,"portuguese");//caracteres do Portugues(ex.:acentos,etc)
int mes;
printf("Por Favor,introduza o número do Mês(1 a 12): ");
     scanf("%d",&mes);
//Janeiro
if(mes==1){
printf("O nome do Mês é Janeiro");
}
//Fevereiro
else if(mes==2){
printf("O nome do Mês é Fevereiro");
}
//Março
else if(mes==3){
printf("O nome do Mês é Março");
}
//Abril
else if(mes==4){
printf("O nome do Mês é Abril");
}
//Maio
else if(mes==5){
printf("O nome do Mês é Maio");
}
//Junho
else if(mes==6){
printf("O nome do Mês é Junho ");
}
//Julho
else if(mes==7){
printf("O nome do Mês é Julho");
}
//Agosto
else if(mes==8){
printf("O nome do Mês é Agosto");
}
//Setembro
else if(mes==9){
printf("O nome do Mês é Setembro");
}
//Outubro
else if(mes==10){
printf("O nome do Mês é Outubro");
}
//Novembro
else if(mes==11){
printf("O nome do Mês é Novembro");
}
//Dezembro
else if(mes==12){
printf("O nome do Mês é Dezembro");
}
//Opcao Invalida
else
     printf("ERRO!!!O Mês %d não existe.Tente novamente\n".Tente novamente\n",mes);
return 0;
}
//-------------------------------------------------------------------------------------------
//USANDO SWITCH
int main(){
setlocale (LC_ALL,"portuguese");//caracteres do Portugues(ex.:acentos,etc)	
	int mes;
	printf("Por Favor,introduza o número do Mês(1 a 12): ");
     scanf("%d",&mes);
switch(mes){
	case 1:
		printf("O nome do Mês é Janeiro");
		break;
    case 2:
    	printf("O nome do Mês é Fevereiro");
    	break;
    case 3:
    	printf("O nome do Mês é Março");
    	break;
    case 4:
    	printf("O nome do Mês é Abril");
    	break;
    case 5:
    	printf("O nome do Mês é Maio");
    	break;
    case 6:
    	printf("O nome do Mês é Junho");
    	break;
    case 7:
    	printf("O nome do Mês é Julho");
    	break;
    case 8:
    	printf("O nome do Mês é Agosto");
    	break;
    case 9:
    	printf("O nome do Mês é Setembro");
    	break;
    case 10:
    	printf("O nome do Mês é Outubro");
    	break;
    case 11:
    	printf("O nome do Mês é Novembro");
    	break;
    case 12:
    	printf("O nome do Mês é Dezembro");
    	break;
default:
     printf("ERRO!!! O Mês %d não existe.Tente novamente\n",mes);
}
return 0;
}
