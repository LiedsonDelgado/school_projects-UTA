#include<stdio.h>

int main(){
    int v[] = {1,3,5,7,9};
    int *p_v = NULL;
    p_v = v;
    int n = sizeof(v)/sizeof(v[0]);
    int soma = 0;

    printf("Elementos do vetor: ");
    while(p_v != v+n){
        printf("%d ",*p_v);
        soma += *p_v;
        p_v++;
    }
    printf("\nA soma dos elementos do vetor = %d\n",soma);

    return 0;
}
