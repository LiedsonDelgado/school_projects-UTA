#include<stdio.h>
#include<stdlib.h>

void imprimir_reverso(int *v,int n){
    if(n >= 0){
        printf("%d ",v[n]);
        imprimir_reverso(v,n-1);
    }

    return;
}

int main(){
    int v[] = {1,2,3,4,5,6,7,8,9,10};
    int n = sizeof(v)/sizeof(v[0])-1;

    printf("Vetor original:  ");
    for(int i=0;i<=n;i++){
        printf("%d ",v[i]);
    }
    printf("\nVetor invertido: ");
    imprimir_reverso(v,n);
    printf("\n");

    return 0;
}
