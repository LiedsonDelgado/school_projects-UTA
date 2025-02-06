#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>

sem_t sem;
long x=10; //valor a ser decrementado pelas 2 threads
long i;

void* func(void *arg){
    long it = (long)arg; //converteu o arg de (void) para (long)
    
sem_wait(&sem);
    if(it==0){
        x--;
        printf("A Thread %ld decrementou x para %ld\n",it+1,x);
            sem_post(&sem);
    }else{
        x++;
        printf("A Thread %ld incrementou x para %ld\n",it+1,x);
            sem_post(&sem);
    }


return NULL;
}

int main(){
    pthread_t thread[2];

    sem_init(&sem,0,1);

        for(i=0;i<2;i++){
            pthread_create(&thread[i],NULL,func,(void*)i);
        }

        for(i=0;i<2;i++){
            pthread_join(thread[i],NULL);
        }
        sem_destroy(&sem);
    
    return 0;
}