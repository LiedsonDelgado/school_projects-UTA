#include<stdio.h>

int produto(int a,int b){
    if(a == 0 || b == 0){
        return 0;
    }
    return a+produto(a,b-1);
}


int main(){
    int a = 2;
    int b = 3;

    int res = produto(a,b);
    printf("%d x %d = %d",a,b,res);
    return 0;
}
