#include<stdio.h>
#include <locale.h>

int main(){
setlocale (LC_ALL,"portuguese");//caracteres do Portugues(ex.:acentos,etc)	
 double litros,custo_por_litro=160.0,total_sem_desconto,total_com_desconto;//Desconto de 5% se for acima de 40l de combustivel,custo/litro=160CVE
 char p='%';
 printf("SHELL GAS STATION\n\n");
printf("Quantos Litros de Combustível vc deseja? ");
     scanf("%lf",&litros);
     
//Sem Desconto    
if(litros<=40){
total_sem_desconto=litros*custo_por_litro;
	printf("\nVc colocou %.1lf litros de combustivel,total a pagar é %.1lf CVE",litros,total_sem_desconto);
}
//Com Desconto
else
      total_sem_desconto=litros*custo_por_litro;
       total_com_desconto=total_sem_desconto-total_sem_desconto*0.05;
           printf("\nVc colocou %.1lf litros de combustivel,total a pagar é %.1lf CVE +5%c de desconto por colocar mais de 40litros",litros,total_com_desconto,p);
return 0;
}
