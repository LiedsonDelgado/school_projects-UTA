#include<stdio.h>

int inv_num(int num,int inv){
    if(num == 0){
        return inv;
    }
    return inv_num(num/10,inv*10+(num%10));
}

int main(){
    int num = 1234;

    int res = inv_num(num,0);

    printf("O numero: %d seu inverso sera: %d",num,res);

    return 0;
}
