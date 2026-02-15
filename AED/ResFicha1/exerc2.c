#include<stdio.h>

int potencia(int b,int e){ //b-base e-expoente
    if(e == 0 || b == 0){
        return 1;
    }
    if(e > 0){
        return b*potencia(b,e-1);
    }
    if(e < 0){ //pensar na solucao
        float res;
        res = 1/(b*potencia(b,e+w1));
        return res;
    }
}

int main(){
    int base = 2;
    int exp = -5;

    int res = potencia(base,exp);

    printf("%d^%d = %d",base,exp,res);

    return 0;
}
