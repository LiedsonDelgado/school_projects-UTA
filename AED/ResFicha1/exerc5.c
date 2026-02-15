#include<stdio.h>

void decimal_para_binario(int n){
    if(n == 0){ //caso base-se n for igual 0
        printf("00000");
        return;
    }
    else{ //caso recursivo
        decimal_para_binario(n/2);
        printf("%d",n%2);
    }
}

int main(){
    int n;

    printf("--Converter para binario--\n");
    printf("Digite um numero: ");
    scanf("%d",&n);

    decimal_para_binario(n);

    return 0;
}