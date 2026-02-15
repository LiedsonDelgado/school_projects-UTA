#include<stdio.h>

int somar_elem_vet(int v[],int i){
    int soma = 0;

    if(i>10){
        return soma;
    }else{
        soma = v[i]+somar_elem_vet(v,i+1);
    }

    /*for(int i=0;i<n;i++){
        soma += v[i];
    }*/

    return soma;
}

int main(){
    int v[] = {1,2,3,4,5,6,7,8,9,10};
    int res = somar_elem_vet(v,0);

    printf("Resultado soma: %d\n",res);

    return 0;
}
