#include<stdlib.h>
#include<stdio.h>

#include<unistd.h>
#include<sys/wait.h>

int main(){
 
	int p_filho = fork();
		if(p_filho == 0){
			printf("Filho enviou outcode:**** \n");
				exit(2);	
}else{
	int estado;
		wait(&estado);
			if(WIFEXITED(estado)){
				int ret=WIFEXITED(estado);
					printf("O filho que terminou tem o codigo %d",ret);
			}
}
return 0;
}
