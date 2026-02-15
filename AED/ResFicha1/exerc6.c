#include<stdio.h>

int conta_impares(int n){
    if(n == 0){
        return 0;
    }

    if(n%2 != 0){
        return 1+conta_impares(n-1);
    }

    return conta_impares(n-1);
}

int main(){
    int n = 10;
    int res_conta_impares = conta_impares(n);

    printf("De 1 a %d existem %d numeros impares\n",n,res_conta_impares);

    return 0;
}