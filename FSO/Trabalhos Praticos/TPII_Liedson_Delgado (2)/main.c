#include"Def_Func.h" //faz o include da biblioteca do programador e suas funcoes definidas

#include<stdio.h>
#include<stdlib.h>

#include<unistd.h>
#include<sys/wait.h>

int main(){

int filho1 = fork(); //crie o primeiro processo filho que ira criar outros 2 processos filhos
	if(filho1 == 0){
		printf("\n");
			notas_testes();
		printf("\n");
			notas_tp();
		printf("\n");
			notas_tg();
		printf("\n");
			notas_participacao();
		printf("\n");
			//------------------
			int filho2 = fork();
				if(filho2 == 0){
				   sleep(5);
				   	printf("\n");
						notas_testes();
					printf("\n");
						notas_tp();
					printf("\n");
						notas_tg();
					printf("\n");
						notas_participacao();
					printf("\n");
						//------------------
						int filho3 = fork();
							if(filho3 == 0){
							   sleep(5);
							   	printf("\n");
									notas_testes();
								printf("\n");
									notas_tp();
								printf("\n");
									notas_tg();
								printf("\n");
									notas_participacao();
								printf("\n");
							}else{
								wait(NULL);
							}
				}else{
					wait(NULL);
				}
}else{
	wait(NULL);
		printf("\nTodos os processos filhos terminaram");
}
return 0;
}
