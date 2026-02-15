#include<stdio.h>
#include<stdlib.h>

int* criar_vetor(int n){
    int *v = (int*)malloc(sizeof(int)*n);
    if(v == NULL){
        printf("Erro ao alocar memoria...");
        exit(EXIT_FAILURE);
    }
    for(int i=0;i<n;i++){
        v[i] = 10;
    }
    return v;
}

int main(){
    int *v;
    int n = 5;

    v = criar_vetor(n);

    printf("Vetor: ");
    for(int i=0;i<n;i++){
        printf("%d ",v[i]);
    }

    free(v);
    printf("\nMemoria libertada...\n");

    return 0;
}
