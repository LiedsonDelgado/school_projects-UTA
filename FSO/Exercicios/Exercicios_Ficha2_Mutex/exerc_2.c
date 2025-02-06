#include<stdio.h>
#include<pthread.h>

#define NUM_THREADS 10
#define NUM_ITERACOES 20

int soma = 0;
pthread_mutex_t mutex;

void *incrementar(void *args){
        int j;
        j+= *(int*)args;

        pthread_mutex_lock(&mutex);
        soma+=j;
        pthread_mutex_unlock(&mutex);

        return NULL;
}

int main(){
	int v[NUM_THREADS]={20,20,30,40,50};

        pthread_t threads[NUM_THREADS];
        pthread_mutex_init(&mutex,NULL);

        for(int i=0; i < NUM_THREADS;i++)
                pthread_create(&threads[i],NULL,incrementar,(void*)&v[i]);

        for(int i=0;i < NUM_THREADS;i++)
                pthread_join(threads[i],NULL);

        printf("Soma Total:%d",soma);
        pthread_mutex_destroy(&mutex);
        return 0;
}
