#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

pthread_mutex_t mutex;

void *print(void *arg){
char *s=(char*)arg;

pthread_mutex_lock(&mutex);
printf("%s\n",s);
pthread_mutex_unlock(&mutex);
	pthread_exit(NULL);
}

int main(){
pthread_t thread[3];
int i;
char *j[]={"Mensagem 1","Mensagem 2","Mensagem 3"};

pthread_mutex_init(&mutex,NULL);

for(i=0;i<3;i++){
pthread_create(&thread[i],NULL,print,(void*)j[i]);
pthread_join(thread[i],NULL);
}

pthread_mutex_destroy(&mutex);

return 0;
}
