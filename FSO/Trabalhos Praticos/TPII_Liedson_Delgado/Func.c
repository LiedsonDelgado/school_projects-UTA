#include"Def_Func.h" //faz o include da biblioteca do programador e suas funcoes definidas

#include<stdio.h>
#include<stdlib.h>

#include<unistd.h>
#include<sys/wait.h>
//------------------
float notas_testes(){
	int i, soma=0;
	int nota_tg[2];
	float nota_final_teste; //nota final de cada teste
	
for(i=0; i<2; i++){
	printf("Nota do %dº teste(15%): ",i+1); //i+1 mostra qual teste esta sendo inserido
		scanf("%d",&nota_tg[i]);
			soma+=nota_tg[i];
}
nota_final_teste=(soma/2) * 0.30; //calcula a nota final dos testes 15% cada
	printf(">A nota final dos 2 testes(30%): %.1f",nota_final_teste);

return 0;
}
//--------------
float notas_tg(){
	float n_tg_e; //nota final do trabalho de grupo escrito de 5%
	float n_tg_eoe;//nota final do trabalho de grupo escrito,oral ou experimental
	float n_tg_final; //nota final de ambos os trabalhos
//---------------
	float n_p; //nota participacao
	float n_p_final; //nota de participacao final ao aplicar o seu peso de 5%

	printf("Nota do Trabalho de Grupo(5%): ");
		scanf("%f",&n_tg_e);
	printf("Nota do Trabalho de Grupo(20%): ");
		scanf("%f",&n_tg_eoe);
			
n_tg_final=(n_tg_e * 0.05) + (n_tg_eoe * 0.20);
	printf(">A nota final dos 2 trabalhos de grupo(5% + 20%): %.1f",n_tg_final);
//----------------------------------------------------------------------------------
printf("\nNota de Participacao/Contribuicoes(5%): ");
		scanf("%f",&n_p);
n_p_final=n_p * 0.05;
	printf(">A nota final da participacao(5%): %.1f",n_p_final);

return 0;	
}
//--------------
float notas_tp(){
	int i;
	float soma=0.0;
	float nota_tp[4];
	float nota_final_tp; //nota final dos trabalhos praticos

	for(i=0; i<4; i++){
		printf("Nota do %dº trabalho pratico(10%): ",i+1); //i+1 usado apenas para mostrar qual trabalho esta sendo inserido
			scanf("%f",&nota_tp[i]);
			soma+=nota_tp[i];
	}
nota_final_tp=(soma/4) * 0.40; //calcula a nota final dos trabalhos praticos 10% cada
	printf(">A nota final dos 4 trabalhos praticos(40%): %.1f",nota_final_tp);

return 0;
}
