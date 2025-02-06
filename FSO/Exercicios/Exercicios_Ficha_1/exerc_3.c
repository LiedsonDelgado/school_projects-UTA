#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main(){
int id;

id=fork();
if(id==0){
	printf("\nPID Filho: %d\n",getpid());
	execl("/bin/date","date",NULL);
	perror("Error");
}else if(id>0){
	wait(NULL);
	printf("PAI esperando filho terminar");
}

return 0;
}
