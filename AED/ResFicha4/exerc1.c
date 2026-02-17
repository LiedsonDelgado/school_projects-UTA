#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int *a;
    int n;
}list;

int isEmpty(list v){
    return (v.n == 0);
}

int isFull(list v){
    int n = sizeof(v.a)/sizeof(v.a[0]);
    return (v.n == n);
}

list insertOnList(list v,int n){
    int elem;

    if(isFull(v)){
        printf("A lista esta cheia nao e possivel inserir mais valores!\n");
        exit(0);
    }

    printf("-Inserir elementos na lista-\n");
    for(int i=0;i<n;i++){
        printf("Elemento %d: ",i+1);
        scanf("%d",&elem);
        v.a[i] = elem;
        v.n++;
    }
    return v;
}

void showList(list v,int n){
    if(isEmpty(v)){
        printf("A lista esta vazia!\n");
    }

    printf("\nElementos da lista: ");
    for(int i=0;i<n;i++){
        printf("%d ",v.a[i]);
    }
}

int greatestValue(list v,int n){
    int greatest = v.a[0];
    for(int i=0;i<n;i++){
        if(v.a[i]>greatest){
            greatest = v.a[i];
        }
    }
    return greatest;
}

int lowestValue(list v,int n){
    int lowest = v.a[0];
    for(int i=0;i<n;i++){
        if(v.a[i]<lowest){
            lowest = v.a[i];
        }
    }
    return lowest;
}

void swapElem(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sortList(list v,int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(v.a[j]>v.a[j+1]){
                swapElem(&v.a[j],&v.a[j+1]);
            }
        }
    }
    printf("A lista foi ordenada!");
}

int main(){
    list v;
    int n;
    int l; // menor valor da lista
    int g; // maior valor da lista

    printf("Quantos elementos a lista tera: ");
    scanf("%d",&n);

    v.a = (int*)malloc(sizeof(int)*n);
    if(v.a == NULL){
        printf("Erro ao alocar memoria!\n");
        exit(EXIT_FAILURE);
    }
    v.n = 0;

    v = insertOnList(v,n);
    showList(v,n);

    l = lowestValue(v,n);
    g = greatestValue(v,n);
    printf("\nMenor valor: %d",l);
    printf("\nMaior Valor: %d\n\n",g);

    sortList(v,n);
    showList(v,n);

    return 0;
}