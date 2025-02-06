#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(){
int id,i;

for(i=0;i<3;i++){
	id=fork();
	if(id==0){
		printf("PID FILHO:%d",getpid());
		exit(0);
	}
}

for(i=0;i<3;i++){
	wait(NULL);
}
printf("\nPAI Terminado\n");

}
