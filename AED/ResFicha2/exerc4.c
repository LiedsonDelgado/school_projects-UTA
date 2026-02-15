#include<stdio.h>
#include<stdlib.h>

int main(){
    int *v = (int*)malloc(sizeof(int)*1);
    if(v == NULL){
        printf("Erro ao alocar memoria!\n");
        return 0;
    }

    printf("Digite um valor: ");
    scanf("%d",v);
    printf("O valor digitado foi %d\n\n",*v);

    free(v);
    printf("Memoria libertada!\n");

    return 0;
}
