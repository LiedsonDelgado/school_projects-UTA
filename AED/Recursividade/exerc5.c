#include<stdio.h>

int num_digitos(int num,int cont){
    if(num < 10){
        cont += 1;
        return cont;
    }else{
        cont += 1;
        num_digitos(num/10,cont);
    }
}

int main(){
    int num;
    int res;

    printf("Digite um numero: ");
    scanf("%d",&num);

    res = num_digitos(num,0);
    printf("O numero %d contem %d digitos\n",num,res);

    return 0;
}
