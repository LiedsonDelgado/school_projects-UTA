#include<stdio.h>

int main(){
    char *v = "Memoria";
    char *p;
    p = v;
    int n = (sizeof(v)/sizeof(v[0]))-1;

    printf("String inicial: ");
    for(int i=0;i<n;i++){
        printf("%c",*(p+i));
    }

    printf("\nString revertida: ");
    for(int i=n-1;i>=0;i--){
        printf("%c",*(p+i));
    }
    printf("\n");

    return 0;
}
