#include<stdio.h>

void atualizar(int *x,int *y){
    printf("\nValores depois da chamada\n");
    *x = *x+5;
    *y = *y*2;

    printf("x = %d\n",*x);
    printf("y = %d\n",*y);
}

int main(){
    int x = 5;
    int y = 7;

    printf("Valores antes da chamada\n");
    printf("x = %d\n",x);
    printf("y = %d\n",y);

    atualizar(&x,&y);

    return 0;
}
