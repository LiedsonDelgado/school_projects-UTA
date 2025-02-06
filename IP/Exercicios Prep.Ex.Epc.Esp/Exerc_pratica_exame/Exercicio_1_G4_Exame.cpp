#include<stdio.h>
#include<locale.h>
int main()
{
setlocale(LC_ALL,"PORTUGUESE");
char p='%';
  int filhos;
  double pagamento_hora=500.0,horas,percentual_filho=0.03;//salario/hora, horas trabalhadas, percentual/filho
  double sal_base,percentual_ganho,salario_total;//salario base, percentual(+3%) ganho/cada filho, salario total
//-------------------------------
printf("Horas de Trabalho: ");
     scanf("%lf",&horas);
printf("Número de Filhos: ");
     scanf("%d",&filhos);

sal_base=horas*pagamento_hora;
//-------------------------------
if(filhos>0){
	
percentual_ganho=percentual_filho*sal_base*filhos;
salario_total=sal_base+percentual_ganho;
     printf("O seu Salário será de %.2lf CVE com bonús de 3%c pelas %.1lf hora(s) de trabalho pelo(s) %d filho(s)",salario_total,p,horas,filhos);
}
else
{
	printf("O seu Salário será de %.2lf CVE pela(s) %lf hora(s) de trabalho",sal_base,horas);
}
}
