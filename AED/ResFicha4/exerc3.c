#include<stdio.h>
#include<stdlib.h>

typedef struct List{
    int number;
    struct List *next;
}list;

void menu(){
    printf("\n1-Inserir elemento\n");
    printf("2-Mostrar todos os elementos\n");
    printf("3-Calcular soma dos elementos\n");
    printf("4-Calcular a media dos elementos\n");
    printf("0-Sair\n");
}

list* createEmptyList(list* l){
    l = NULL;

    return l;
}

int isEmpty(list* l){
    return l == NULL;
}

int listSize(list* l){
    int size = 0;
    while(l != NULL){
        l = l->next;
        size++;
    }

    return size;
}

list* insertElementsAtTheEnd(list* l,int elem){
    list* newNode = (list*)malloc(sizeof(list));
    if(newNode == NULL){
        printf("Erro ao alocar memoria!\n");
        exit(EXIT_FAILURE);
    }

    newNode->number = elem;
    newNode->next = NULL;

    if(l == NULL){
        return newNode;
    }

    list* aux = l;
    while(aux->next != NULL){
        aux = aux->next;
    }
    aux->next = newNode;

    return l;
}

int listElementsSum(list* l){
    int sum = 0;

    while(l != NULL){
        sum += l->number;
        l = l->next;
    }

    return sum;
}

float listElementsAverage(list* l){
    int sum = 0;
    float average = 0.0;
    int n = listSize(l);

    while(l != NULL){
        sum += l->number;
        l = l->next;
    }

    average = (float)sum/n;

    return average;
}

void showAllElements(list* l){
    if(isEmpty(l)){
        printf("A lista esta vazia!\n");
        return;
    }

    while(l != NULL){
        printf("%d ",l->number);
        l = l->next;
    }
}

int main(){
    list* l;
    int value;
    int sum;
    float average;
    int opt;

    l = NULL;

    do{
        menu();
        printf("Escolha uma opcao: ");
        scanf("%d",&opt);

        switch(opt){
            case 0:
            free(l);
            printf("Encerrando...\n");
            break;

            case 1:
            printf("Insira um valor: ");
            scanf("%d",&value);

            l = insertElementsAtTheEnd(l,value);
            printf("Elemento inserido com sucesso!\n");
            break;

            case 2:
            showAllElements(l);
            printf("\n");
            break;

            case 3:
            sum = listElementsSum(l);
            printf("Soma dos elementos da lista: %d\n",sum);
            break;

            case 4:
            average = listElementsAverage(l);
            printf("Media dos elementos da lista: %.2f\n",average);
            break;

            default:
            printf("Opcao invalida, tente novamente!\n");
            break;
        }
    }while(opt != 0);

    return 0;
}