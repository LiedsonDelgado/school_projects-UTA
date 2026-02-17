// Pilha
#include<stdio.h>
#include<stdlib.h>

#define MAX 100

typedef struct{
    int vetor[MAX];
    int n;
}stack;

void menu(){
    printf("\n--MENU DA PILHA--\n");
    printf("1-Empilhar\n");
    printf("2-Desempilhar\n");
    printf("3-Exibir topo da pilha\n");
    printf("4-Exibir todos os elementos da pilha\n");
    printf("5-Sair\n");
}

void createStack(stack *s){
    s->n = 0;
}

int isFull(stack *s){
    return s->n == MAX;
}

int isEmpty(stack *s){
    return s->n == 0;
}

void top(stack *s){
    if(isEmpty(s)){
        printf("A pilha esta vazia!\n");
        return;
    }

    int topo = s->vetor[s->n-1];
    printf("Elemento do topo: %d\n",topo);
}

void push(stack *s,int elem){
    if(isFull(s)){
        printf("A pilha esta cheia!\n");
        return;
    }
    s->vetor[s->n] = elem;
    s->n++;
}


int pop(stack *s){
    int top;

    if(isEmpty(s)){
        printf("A pilha esta vazia!\n");
        return 0;
    }

    top = s->vetor[s->n];
    s->n--;

    return top;
}

void showAllElem(stack *s){
    int n = s->n;

    for(int i=0;i<n;i++){
        printf("Elemento %d: %d\n",i+1,s->vetor[i]);
    }
}

int main(){
    int opc;
    int elem;
    int removedElem;
    stack *s;

    createStack(s);
    printf("Pilha criada com sucesso!\n");

    do{
        menu();
        printf("Digite a sua opcao: ");
        scanf("%d",&opc);

        switch(opc){
            case 0:
            printf("Encerrando...\n");
            break;

            case 1:
            printf("O elemento que deseja adicionar: ");
            scanf("%d",&elem);

            push(s,elem);
            printf("O elemento foi adicionado com sucesso\n");
            break;

            case 2:
            removedElem = pop(s);
            printf("O elemento %d foi removido com sucesso\n");
            break;

            case 3:
            top(s);
            break;

            case 4:
            showAllElem(s);
            break;

            case 5:
            free(s);
            printf("A pilha foi esvaziada!\n");
            break;

            default:
            printf("Opcao invalida, tente novamente!\n");
            break;
        }

    }while(opc != 0);

    return 0;
}