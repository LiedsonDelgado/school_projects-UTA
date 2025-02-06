#include<stdio.h>
int main()
{
int n_filhos; //Numero de filhos
float pagamento_hora=500.0,percentual_por_filho=0.03;//pagamento de 500CVE/hora, 3% a mais do salario/filho
float horas_t;//Numero de horas trabalhadas
float salario_base,percentual_ganho,salario_total;//salario_base=sem filhos,percentual_ganho=com 1 ou mais filhos(n_filhos>0)

printf("CALCULO SALARIO FUNCIONARIO/HORA(+3%/FILHO)\n");
printf("Horas Trabalhadas: ");
     scanf("%f",&horas_t);
printf("Numero de Filhos: ");
      scanf("%d",&n_filhos);
      
salario_base=horas_t*pagamento_hora;

if(n_filhos>0){
	percentual_ganho=salario_base*percentual_por_filho*n_filhos;
	salario_total=salario_base+percentual_ganho;
             printf("O funcionario recebera %.2f CVE por %.1f hora(s)de trabalho,e por ter %d filho(s)",salario_total,horas_t,n_filhos);
}else{
       printf("O funcionario recebera %.2f CVE por %.1f hora(s) de trabalho",salario_base,horas_t);
}
}
