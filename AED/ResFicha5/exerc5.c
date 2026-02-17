#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct music{
    char* title;
    int duration;
    struct music* next;
}Music;

typedef struct playlist{
    Music* start;
    Music* end;
}Playlist;

void menu(){
    printf("\n1-Adicionar musica\n");
    printf("2-Remover musica\n");
    printf("3-Mostrar playlist\n");
    printf("0-Sair\n");
}

void createPlaylist(Playlist* p){
    p->start = NULL;
    p->end = NULL;
}

int isEmpty(Playlist* p){
    return (p->start == NULL);
}

int playlistSize(Playlist* p){
    int size = 0;
    
    Music* aux = p->start;
    while(aux != NULL){
        size++;
        aux = aux->next;
    }
    return size;
}

void firtMusic(Playlist* p){
    if(isEmpty(p)){
        printf("A playlist esta vazia!\n");
        return;
    }
    printf("--MUSICA--\n");
    printf("-Titulo: %s",p->start->title);
    printf("-Duracao: %d",p->start->duration);
}

void addToPlaylist(Playlist *p,char* title,int duration){
    Music* newMusic = (Music*)malloc(sizeof(Music));
    if(newMusic == NULL){
        printf("Erro ao alocar memoria!\n");
        exit(EXIT_FAILURE);
    }

    newMusic->title = (char*)malloc(sizeof(char)*100);
    if(newMusic->title == NULL){
        printf("Erro ao alocar memoria!\n");
        exit(EXIT_FAILURE);
    }

    strcpy(newMusic->title,title);
    newMusic->duration = duration;
    newMusic->next = NULL;

    if(isEmpty(p)){
        p->start = p->end = newMusic;
    }else{
        p->end->next = newMusic;
        p->end = newMusic;
    }
}

void removeToPlaylist(Playlist *p){
    if(isEmpty(p)){
        printf("A fila esta vazia!\n");
        return;
    }
    Music* aux = p->start;
    p->start = p->start->next;
    if(p->start == NULL){
        p->end = NULL;
    }
    free(aux);
}

void showPlaylist(Playlist* p){
    Music* aux = p->start;

    printf("----PLAYLIST---\n");
    while(aux != NULL){
        printf("-------------\n");
        printf("Titulo: %s\n",aux->title);
        printf("Duracao: %ds\n",aux->duration);
        printf("-------------\n");
        aux = aux->next;
    }
}

int main(){
    Playlist* p = (Playlist*)malloc(sizeof(Playlist));
    if(p == NULL){
        printf("Erro ao alocar memoria!\n");
        exit(EXIT_FAILURE);
    }

    createPlaylist(p);

    char* title = (char*)malloc(sizeof(char)*100);
    if(title == NULL){
        printf("Erro ao alocar memoria!\n");
        exit(EXIT_FAILURE);
    }

    int duration;
    int opt;

    do{
        menu();
        printf("Escolha uma opcao: ");
        scanf("%d",&opt);

        switch(opt){
            case 0:
            printf("Encerrando...\n");
            break;

            case 1:
            printf("Titulo: ");
            scanf("%s",title);

            printf("Duracao(em segundos): ");
            scanf("%d",&duration);

            addToPlaylist(p,title,duration);
            printf("Musica adicionada na playlist!\n");
            break;

            case 2:
            removeToPlaylist(p);
            printf("Musica removida da playlist!\n");
            break;

            case 3:
            showPlaylist(p);
            break;

            default:
            printf("Opcao invalida, tente novamente!\n");
            break;
        }
    }while(opt != 0);

    return 0;
}