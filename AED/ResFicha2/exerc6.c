#include<stdio.h>
#include<stdlib.h>

int main(){
    int *v = (int*)malloc(sizeof(int)*3);
    if(v == NULL){
        printf("Erro ao alocar memoria\n");
        exit(EXIT_FAILURE);
    }
    printf("Introduza 3 valores\n");
    for(int i=0;i<3;i++){
        printf("%d-valor: ",i+1);
        scanf("%d",&v[i]);
    }

    int *v_maior = realloc(v,6*sizeof(int));
    if(v_maior == NULL){
        printf("Erro ao alocar memoria\n");
        exit(EXIT_FAILURE);
    }
    printf("\nIntroduza mais 3 os valores\n");
    for(int i=3;i<6;i++){
        printf("%d-valor: ",i+1);
        scanf("%d",&v_maior[i]);
    }

    printf("\nElementos do vetor: ");
    for(int i = 0;i<6;i++){
        printf("%d ",v_maior[i]);
    }
    printf("\n");

    return 0;
}
