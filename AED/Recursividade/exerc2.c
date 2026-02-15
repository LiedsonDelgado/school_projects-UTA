#include<stdio.h>

int crescente_pares(int n){
    if(n == 1){
        return 2;
    }
        crescente_pares(n-1);
    if(n%2 == 0 && n>=2){
        
        printf("%d\n",n);
    }
}

int main(){
    crescente_pares(11);
    return 0;
}
