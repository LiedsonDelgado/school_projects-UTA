#include<stdio.h>

int encontrar_elem_vetor(int v[],int i,int num){
    if(v[i] == num){
        printf("%d-encontrou\n",i+1);
        return 1;
    }else{
        //printf("%d-nao encontrou\n",i+1);
        encontrar_elem_vetor(v,i+1,num);
        return 0;
    }

    /*for(int i=0;i<n;i++){
        if(v[i] == num){
            printf("encontrou\n");
        }else{
            printf("nao encontrou\n");
        }
    }*/
}

int main(){
    int v[] = {1,3,4,6,8,11};
    encontrar_elem_vetor(v,0,6);
    return 0;
}
