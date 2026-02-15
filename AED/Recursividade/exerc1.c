#include<stdio.h>

int ordem_decrescente(int n){
    if(n<1){
        return 1;
    }else{
        printf("%d\n",n);
        return ordem_decrescente(n-1);
    }
}

int main(){
    ordem_decrescente(10);
    return 0;
}
