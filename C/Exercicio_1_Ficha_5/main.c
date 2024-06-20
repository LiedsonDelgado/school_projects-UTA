#include "exercicio_1_ficha_5.h"
#include<locale.h>//Biblioteca para permitir caracteres especiais

//Funçao para exibir opcoes do Menu
void opcoes_Menu(){
    printf("--------MENU---------\n");
    printf("(1)-Adicionar Aluno\n");
    printf("(2)-Remover Aluno\n");
    printf("(3)-Procurar Aluno pelo Nome\n");
    printf("(4)-Procurar Aluno pelo Numero\n");
    printf("(5)-Mostrar Lista de Alunos\n");
    printf("(0)-Sair\n");
    printf("------------------------\n");
}

// Funçoes para as Opçoes selecionada pelo Usuario
void executar_opcoes(int opcoes, PALUNO *lista_alunos){
    switch (opcoes){
        case 0:
            printf("Encerrando...\n");

            break;
        case 1:{
            dados_Aluno(lista_alunos);
            printf("\n(Aluno adicionado com sucesso!)\n");

            break;
        }
        case 2:{
            char nome[50];
            printf("\nDigite o Nome do aluno a ser removido: ");
            scanf("%s",nome);

            *lista_alunos=delete_student(*lista_alunos, nome);
            printf("(Aluno foi removido com sucesso!)\n");

            break;
        }
        case 3:{
            char nome[50];
            printf("\nDigite o Nome do Aluno que deseja procurar: ");
            scanf("%s",nome);
            PALUNO aluno= search_by_name(*lista_alunos,nome);
            if (aluno!=NULL) {
                printf("Aluno foi Encontrado:\n");
                printf("Nome: %s\n",aluno->nome);
                printf("Numero: %d\n",aluno->numero);
            }
            else{
                printf("Aluno nao foi encontrado!\n");
            }
            break;
        }
        case 4:{
            int numero;
            printf("\nDigite o Numero do Aluno que deseja procurar: ");
            scanf("%d", &numero);
            PALUNO aluno = search_by_number(*lista_alunos,numero);
            if (aluno!= NULL){
                printf("Aluno foi encontrado:\n");
                printf("Nome: %s\n", aluno->nome);
                printf("Numero: %d\n", aluno->numero);
            }
            else{
                printf("Aluno nao foi encontrado!\n");
            }
            break;
        }
        case 5:{
            imprimirLista(*lista_alunos);

            break;
        }
        default:
        printf("\n<Tente Novamente!>\n");
    }
}

int main(){
    PALUNO lista_alunos=NULL;
    setlocale(LC_ALL,"PORTUGUESE");//Permite caracteres especiais
    int opcoes;
    do {
        opcoes_Menu();
        printf("Escolha uma opcao: ");
        scanf("%d",&opcoes);
        getchar();//Funcao para limpar o buffer do teclado

        executar_opcoes(opcoes,&lista_alunos);

    } while(opcoes!=0);

    return 0;
}
