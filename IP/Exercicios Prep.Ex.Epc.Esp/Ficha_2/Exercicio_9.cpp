#include<stdio.h>
#include <locale.h>

//USANDO IF-ELSE
int main(){
setlocale (LC_ALL,"portuguese");//caracteres do Portugues(ex.:acentos,etc)
int mes;
printf("Por Favor,introduza o n�mero do M�s(1 a 12): ");
     scanf("%d",&mes);
//Janeiro
if(mes==1){
printf("O nome do M�s � Janeiro");
}
//Fevereiro
else if(mes==2){
printf("O nome do M�s � Fevereiro");
}
//Mar�o
else if(mes==3){
printf("O nome do M�s � Mar�o");
}
//Abril
else if(mes==4){
printf("O nome do M�s � Abril");
}
//Maio
else if(mes==5){
printf("O nome do M�s � Maio");
}
//Junho
else if(mes==6){
printf("O nome do M�s � Junho ");
}
//Julho
else if(mes==7){
printf("O nome do M�s � Julho");
}
//Agosto
else if(mes==8){
printf("O nome do M�s � Agosto");
}
//Setembro
else if(mes==9){
printf("O nome do M�s � Setembro");
}
//Outubro
else if(mes==10){
printf("O nome do M�s � Outubro");
}
//Novembro
else if(mes==11){
printf("O nome do M�s � Novembro");
}
//Dezembro
else if(mes==12){
printf("O nome do M�s � Dezembro");
}
//Opcao Invalida
else
     printf("ERRO!!!O M�s %d n�o existe.Tente novamente\n".Tente novamente\n",mes);
return 0;
}
//-------------------------------------------------------------------------------------------
//USANDO SWITCH
int main(){
setlocale (LC_ALL,"portuguese");//caracteres do Portugues(ex.:acentos,etc)	
	int mes;
	printf("Por Favor,introduza o n�mero do M�s(1 a 12): ");
     scanf("%d",&mes);
switch(mes){
	case 1:
		printf("O nome do M�s � Janeiro");
		break;
    case 2:
    	printf("O nome do M�s � Fevereiro");
    	break;
    case 3:
    	printf("O nome do M�s � Mar�o");
    	break;
    case 4:
    	printf("O nome do M�s � Abril");
    	break;
    case 5:
    	printf("O nome do M�s � Maio");
    	break;
    case 6:
    	printf("O nome do M�s � Junho");
    	break;
    case 7:
    	printf("O nome do M�s � Julho");
    	break;
    case 8:
    	printf("O nome do M�s � Agosto");
    	break;
    case 9:
    	printf("O nome do M�s � Setembro");
    	break;
    case 10:
    	printf("O nome do M�s � Outubro");
    	break;
    case 11:
    	printf("O nome do M�s � Novembro");
    	break;
    case 12:
    	printf("O nome do M�s � Dezembro");
    	break;
default:
     printf("ERRO!!! O M�s %d n�o existe.Tente novamente\n",mes);
}
return 0;
}
