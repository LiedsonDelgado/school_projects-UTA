#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main(){
pid_t pid=fork();
if(pid<0){
	perror("Erro_ao_criar_processo");
		return 1;
}else if(pid==0){
	printf("Processo_Filho(PID):%d\n",getpid());
	printf("Processo Filho Terminado");
		exit(0);
}else{
	printf("Processo_Pai(PPID):%d",getppid());
	printf("Processo Pai Aguardando");
	if(wait==NULL){
		printf("Processo Filho Terminou");
	}
}

return 0;
}

