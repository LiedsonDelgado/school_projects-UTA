#include<stdio.h>
#include<stdlib.h>

#include<unistd.h>
#include<sys/wait.h>

int main(){

	int  p_filho1  = fork();
if(p_filho1  ==  0){
	sleep(3);
		printf("Processo filho 1 terminou PID: %d \n",getpid());
			exit(0);

}else
	if(p_filho1  > 0){
		int p_filho2 = fork();

	if(p_filho2  ==  0){
	sleep(3);
		printf("Processo filho 2 terminou PID: %d \n",getpid());
			exit(0);

}else
	if(p_filho2  > 0){
		int estado;
		int filho;
			filho=wait(&estado);
				printf("O processo filho que terminou primeiro foi: %d",filho);
					wait(NULL);
	}
}

return 0;
}
