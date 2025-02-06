#include<stdio.h>
#include<pthread.h>

#define NUM_THREADS 5
#define NUM_ITERACOES 1000

int count = 0;
pthread_mutex_t mutex;

void *incrementar(void *args){
	int j=0;
	for(int i=0;i < NUM_ITERACOES;i++)
		j++;
	pthread_mutex_lock(&mutex);
	count+=j;
	pthread_mutex_unlock(&mutex);

	return NULL;
}

int main(){
	pthread_t threads[NUM_THREADS];
	pthread_mutex_init(&mutex,NULL);

	for(int i=0;i< NUM_THREADS;i++)
		pthread_create(&threads[i],NULL,incrementar,NULL);
	
	for(int i=0;i< NUM_THREADS;i++)
                pthread_join(threads[i],NULL);

	printf("Contador Final: %d\n",count);
	pthread_mutex_destroy(&mutex);
	return 0;

