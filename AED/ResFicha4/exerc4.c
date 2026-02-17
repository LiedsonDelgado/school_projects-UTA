#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct waitingline{
    char* name;
    struct waitingline* next;
}WaitingLine;

void menu(){
    printf("\n--FILA DE ESPERA--\n");
    printf("1-Entrar na fila\n");
    printf("2-Atender\n");
    printf("0-Sair\n");
}

void createWaitingLine(WaitingLine *wL){
    wL = NULL;
}

int isEmpty(WaitingLine *wL){
    return (wL == NULL);
}

void showWaintingLine(WaitingLine *wL){
    if(isEmpty(wL)){
        printf("A fila de espera se encontra vazia!\n");
    }
}

WaitingLine* addIntoWaitingLine(WaitingLine *wL,char* personName){
    WaitingLine* newNode = (WaitingLine*)malloc(sizeof(WaitingLine));
    if(newNode == NULL){
        printf("Erro ao alocar memoria!\n");
        exit(EXIT_FAILURE);
    }

    strcpy(newNode->name,personName);
    newNode->next = NULL;

    if(wL == NULL){
        return newNode;
    }

    WaitingLine* aux = wL;
    while(aux->next != NULL){
        aux = aux->next;
    }
    aux->next = newNode;

    return wL;
}

int removeFromWaintingLine(WaitingLine *wL,char* personName){
    if(isEmpty(wL)){
        return 0;
    }

    if(personName == NULL){
        return 0;
    }

    WaitingLine* l = wL;

    while(l->next != NULL || (strcmp(wL->name,personName)<0)){
        l = l->next;
    }

    if(strcmp(wL->name,personName) == 0){
        WaitingLine* aux = wL->next;
        wL->next = aux->next;

        free(aux);

        return 1;
    }
    return 0;
}

int main(){
    int opt;

    char* pName = (char*)malloc(sizeof(char)*100);
    if(pName == NULL){
        printf("Erro ao alocar memoria!\n");
        return 0;
    }

    WaitingLine* wL;
    createWaitingLine(wL);

    do{
        menu();
        printf("Escolha uma opcao: ");
        scanf("%d",&opt);

        switch(opt){
            case 0:
            printf("Encerrando...\n");
            break;

            case 1:
            printf("Nome da pessoa: ");
            scanf("%s",pName);

            wL = addIntoWaitingLine(wL,pName);
            printf("Pessoa adicionada na fila de espera\n");
            break;

            case 2:
            printf("Nome da pessoa: ");
            scanf("%s",pName);

            removeFromWaintingLine(wL,pName );
            printf("Pessoa removida na fila de espera\n");
            break;

            default:
            printf("Opcao invalida, tente novamente!\n");
            break;
        }
    }while(opt != 0);

    return 0;
}