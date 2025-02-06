#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>

void *print(void *arg){
char *s=(char*)arg;
printf("%s\n",s);
	pthread_exit(NULL);

int main(){
pthread_t t1,t2;

char *s1 = "Mensagem 1";
char *s2 = "Mensagem 2";

pthread_create(&t1,NULL,print,(void*)s1);
pthread_create(&t2,NULL,print,(void*)s2);

pthread_join(t1,NULL);
pthread_join(t2,NULL);

return 0;
}
