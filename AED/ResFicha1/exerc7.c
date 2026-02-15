#include<stdio.h>

int mdc(int x,int y){
    if(y == 0){
        return x;
    }
    return mdc(y,x%y);
}

int main(){
    int x = 459;
    int y = 126;
    int res_mdc = mdc(x,y);

    printf("MDC entre %d e %d e %d",x,y,res_mdc);

    return 0;
}