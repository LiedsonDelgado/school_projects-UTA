#include<stdio.h>

int palindromo(char palavra[],int inicio,int fim){
    if(inicio<=fim){
        return 1;
    }
    if(palavra[inicio] == palavra[fim]){
        return 0;
    }
    return(palavra,inicio+1,fim-1);
}

int main(){
    char palavra[] = "osso";
    int inic = 0;
    int fim = sizeof(palavra)/sizeof(palavra[0]);

    int palindromo = palindromo(palavra,inic,fim-1);
    if(palindromo == 0){
        printf("Nao e palindromo");
    }
    printf("E palindromo");

    return 0;
}