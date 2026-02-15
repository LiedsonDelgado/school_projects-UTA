//Resolucao Pratica-Teste 2
//Leonardo Domingues
//Liedson Delgado
//Tiago Dongo

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define DISPONIVEL 0
#define EMPRESTADO 1
#define MAX 100

int nextId = 1;

typedef struct book{
  int id;
  char title[MAX];
  char author[MAX];
  int emprestado;
}Book;

typedef struct booklist{
  Book books;
  struct booklist *next;
}BookList;

typedef struct emprestimo{
  int bookId;
  char user[50];
  struct emprestimo *next;
}Loan;

typedef struct loanqueue{
  Loan *inicio;
  Loan *fim;
}LoanQueue;

// opção 1
void adicionarLivro(BookList **list, char *titulo, char *autor){
  BookList *novo = (BookList*)malloc(sizeof(BookList));
  if(novo == NULL){
    printf("ERRO: falha ao alocar memoria\n");
    return;
  }

  novo->books.id = nextId++;

  strcpy(novo->books.title, titulo);
  strcpy(novo->books.author, autor);

  novo->books.emprestado = DISPONIVEL;
  novo->next = NULL;

  if(*list == NULL){
    *list = novo;
  }else {
    BookList *temp = *list;
    while (temp->next != NULL){
      temp = temp->next;
    }
    temp->next = novo;
  }
  printf("SUCESSO: Livro [ %s ] adicionado\n",titulo);
}

// opção 2
void mostrarLivros(BookList *list){
  if(list == NULL){
    printf("ERRO: biblioteca vazia\n");
    return;
  }
  printf("\n----------------- Biblioteca Digital -----------------\n");
  printf("%-5s %-30s %-20s %-15s\n", "Id", "Titulo", "Autor", "Estado");
  printf("--------------------------------------------------------\n");

  while (list != NULL){
    printf("%-5d %-30s %-20s %-15s\n",
      list->books.id,
      list->books.title,
      list->books.author,
      list->books.emprestado == EMPRESTADO ? "Emprestado" : "Disponivel"
    );
    list = list->next;
  } 
}

BookList* findBookById(BookList *list, int id){
  while(list != NULL){
        if(list->books.id == id)
            return list;
        list = list->next;
      }
    return NULL;
}

void createBookLoan(LoanQueue *bl){
  bl->inicio = NULL;
  bl->fim = NULL;
}

int isBookLoanEmpty(LoanQueue* bL){
  return (bL->inicio == NULL);
}

//opção 3
void adicionarPedido(LoanQueue *loans, int bookId, char user[]){
  Loan *novo = (Loan*)malloc(sizeof(Loan));
  if(novo == NULL){
    printf("ERRO: falha ao alocar memoria");
    return;
  }

  novo->bookId = bookId;
  strcpy(novo->user, user);
  novo->next = NULL;

  if(isBookLoanEmpty(loans)){
    loans->inicio = loans->fim = novo;
  }else {
    loans->fim->next = novo;
    loans->fim = novo;
  }
  printf("SUCESSO: pedido de emprestimo adicionado a fila\n");
}

//opção 4
void processarPedido(BookList *list, LoanQueue *fila){
  if(isBookLoanEmpty(fila)){
        printf("ERRO: Fila de pedidos vazia.\n");
        return;
    }

    Loan *pedido = fila->inicio;
    BookList *livro = findBookById(list, pedido->bookId);

    //Se o livro não existe na lista → remove o pedido da fila.
    if(livro == NULL){
      printf("SUCESSO: pedido removido - livro Id %d nao existe.\n",pedido->bookId);
      fila->inicio = pedido->next;
      if(fila->inicio == NULL) fila->fim = NULL;
      free(pedido);
      return;
    }

    //Se o livro existe e está disponível → marca emprestado = 1 e remove o pedido da fila.
    if(livro != NULL && livro->books.emprestado == DISPONIVEL){
      livro->books.emprestado = EMPRESTADO;
      printf("SUCESSO: livro [ %s ] emprestado a [ %s ]\n",livro->books.title, pedido->user);
      fila->inicio = pedido->next;
      if(fila->inicio == NULL) fila->fim = NULL;
      free(pedido);
      return;
    }

    //Se o livro existe mas está emprestado → pedido permanece na fila.
}

//opção 5
void devolverLivro(Book* list,LoanQueue *fila,int bookId){
    BookList* livro = findBookById(list,bookId);

    if(livro == NULL){
        printf("O livro nao foi encontrado!\n");
    }

    if(livro->books.emprestado == DISPONIVEL){
        printf("O livro ja esta disponivel!\n");
    }

    printf("SUCESSO: livro [%s] devolvido.\n", livro->books.title);

    //termina tentando processar a fila
    if(!isBookLoanEmpty(fila)){
        processarPedido(list,fila);
    }
}

//opção 6
void mostrarPedidos(LoanQueue* loans){
    Loan* aux = loans->inicio;

    printf("--PEDIDOS--\n");
    while(aux != NULL){
        printf("-Nome utilizador: %s",aux->user);
        printf("-Id do livro: %d",aux->bookId);
        aux = aux->next;
    }
}

int main(){
    int opt;

    BookList *library = NULL;
    LoanQueue emprestimos;
    createBookLoan(&emprestimos);

    char title[MAX];
    char author[MAX];

    do{
      printf("\n1-Adicionar livro\n"); //feito
      printf("2-Mostrar livros(com estado)\n"); //feito
      printf("3-Adicionar pedido\n");
      printf("4-Processar pedidos\n");
      printf("5-Devolver livro\n");
      printf("6-Mostrar pedidos na fila\n");
      printf("7-Sair\n");
      printf("Escolha uma opcao: ");
      scanf("%d",&opt);
      getchar();

      switch(opt){
          case 1:{
            printf("\n--- Adicao de Livro ---\n");
            printf("Titulo do livro: ");
            fgets(title, MAX, stdin);
            title[strcspn(title, "\n")] = '\0';

            printf("Nome do autor: ");
            fgets(author, MAX, stdin);
            author[strcspn(author, "\n")] = '\0';

            adicionarLivro(&library, title, author);
            break;
          }

          case 2:
            mostrarLivros(library);
            break;

          case 3:{
            int bookId;
            char user[50];

            printf("ID do livro: ");
            scanf("%d", &bookId);

            printf("Nome do usuario: ");
            fgets(user, MAX, stdin);
            user[strcspn(user, "\n")] = '\0';

            adicionarPedido(&emprestimos,bookId,user);

            break;
          }

          case 4:
            break;

          case 5:
            break;

          case 6:
          break;

          case 7:
            printf("Saindo...!\n");
            break;

          default:
            printf("Opcao invalida,tente novamente!\n");
            break;
      }
    }while(opt != 7);

    return 0;
}