#include<stdio.h>
#include<stdlib.h>

int* alocaMem(int n){
    int *v = (int*)malloc(sizeof(int)*n);
    if(v == NULL){
        printf("Erro ao alocar memoria\n");
        return 0;
    }
    return v;
}

int main(){
    int *v;
    int n;

    printf("Quantos elementos o vetor: ");
    scanf("%d",&n);

    v = alocaMem(n);

    printf("\nIntroduza os elementos do vetor\n");
    for(int i=0;i<n;i++){
        printf("%d-elemento: ",i+1);
        scanf("%d",&v[i]);
    }

    printf("\nElementos do vetor: ");
    for(int i=0;i<n;i++){
        printf("%d ",v[i]);
    }
    printf("\n");


    return 0;
}
