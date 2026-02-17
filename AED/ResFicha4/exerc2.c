#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
    char name[100]; //nome do livro
    int year; //ano de publicacao
}book;

typedef struct{
    book *book; //vetor para livros
    int n; //contador de livros no catalogo
}catalog;

void menu(){
    printf("\n--Catalogo de livro--\n");
    printf("1-Adicionar livro\n");
    printf("2-Procurar livro(por nome)\n");
    printf("3-Exibir livros(algum ano)\n");
    printf("4-Exibir todos os livros!\n");
    printf("0-Sair!\n");
}

int isEmpty(catalog* bookCatalog){
    return bookCatalog->n == 0;
}

catalog* addBookToCatalog(catalog* bookCatalog,int i,char* bookName,int year){
    strcpy(bookCatalog->book[i].name,bookName);
    bookCatalog->book[i].year = year;
    bookCatalog->n += 1;

    return bookCatalog;
}

void searchBookByName(catalog* bookCatalog,char* bookName){
    int n = bookCatalog->n;

    for(int i=0;i<n;i++){
        if(strcmp(bookCatalog->book[i].name,bookName)==0){
            printf("O livro foi encontrado no catalogo!\n");
        }else{
            printf("O livro nao foi encontrado no catalogo!\n");
        }
    }
}

void showBookSinceThen(catalog* bookCatalog,int year){
    int cont = 0;
    int n = bookCatalog->n;

    for(int i=0;i<n;i++){
        if(bookCatalog->book[i].year >= year){
            printf("-Titulo: %s,Ano de publicacao: %d\n",bookCatalog->book[i].name,bookCatalog->book[i].year);
            cont++;
        }
    }
    printf("Foram encontrados %d livros desde %d\n",cont,year);
}

void showAllBooks(catalog* bookCatalog){
    int n = bookCatalog->n;

    for(int i=0;i<n;i++){
        printf("-Titulo: %s,Ano de publicacao: %d\n",bookCatalog->book[i].name,bookCatalog->book[i].year);
    }
}

int main(){
    int opc;
    char bookName[100];
    int year;

    int i = 0;

    catalog* bookCatalog = (catalog*)malloc(sizeof(catalog));
    if(bookCatalog == NULL){
        printf("Erro ao alocar memoria!\n");
        exit(EXIT_FAILURE);
    }

    bookCatalog->n = 0;
    bookCatalog->book = NULL;

    do{
        menu();
        printf("Escolha uma opcao: ");
        scanf("%d",&opc);

        switch(opc){
            case 0:
            printf("Encerrando...\n");
            break;

            case 1:
            bookCatalog->book = realloc(bookCatalog->book,sizeof(book)*(i+1));
            if(bookCatalog->book == NULL){
                printf("Erro ao alocar memoria!\n");
                exit(EXIT_FAILURE);
            }

            printf("Titulo do livro: ");
            scanf("%s",bookName);

            printf("Ano de publicacao: ");
            scanf("%d",&year);

            addBookToCatalog(bookCatalog,i,bookName,year);
            i++;
            printf("O livro foi adicionado ao catalogo!\n");
            break;

            case 2:
            if(isEmpty(bookCatalog)){
                printf("O catalogo esta vazio!\n");
                return 0;
            }

            printf("Titulo do livro: ");
            scanf("%s",bookName);

            searchBookByName(bookCatalog,bookName);
            break;

            case 3:
            if(isEmpty(bookCatalog)){
                printf("O catalogo esta vazio!\n");
                return 0;
            }

            printf("Ano de publicacao: ");
            scanf("%d",&year);
            showBookSinceThen(bookCatalog,year);
            break;

            case 4:
            if(isEmpty(bookCatalog)){
                printf("O catalogo esta vazio!\n");
                return 0;
            }

            showAllBooks(bookCatalog);
            break;

            default:
            printf("Opcao invalida, tente novamente!\n");
        }
    }while(opc != 0);

    return 0;
}