#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct {
    char usuario[50];
    char equipamento[20];
    char estado[30];
    int devolvido;
} Requisicao;

void adicionarRequisicao(Requisicao requisicoes[], int *numRequisicoes) {
    printf("Nome do usuario: ");
    scanf("%s", requisicoes[*numRequisicoes].usuario);
    printf("Equipamento desejado: ");
    scanf("%s", requisicoes[*numRequisicoes].equipamento);
    strcpy(requisicoes[*numRequisicoes].estado, "Pendente");
    requisicoes[*numRequisicoes].devolvido = 0;
    (*numRequisicoes)++;
}

void listarRequisicoes(Requisicao requisicoes[], int *numRequisicoes) {
    printf("\nLista de Requisicoes:\n");
    for (int i = 0; i < numRequisicoes; i++) {
        printf("Usuario: %s, Equipamento: %s, Estado: %s, Devolvido: %s\n",
               requisicoes[i].usuario, requisicoes[i].equipamento,
               requisicoes[i].estado, (requisicoes[i].devolvido) ? "Sim" : "Nao");
    }
}

void aprovarRequisicao(Requisicao requisicoes[], int numRequisicoes) {
    char usuario[50];
    printf("Digite o nome do usuario para aprovar a requisicao: ");
    scanf("%s", usuario);

    for (int i = 0;   numRequisicoes; i++) {
        if (strcmp(requisicoes[i].usuario, usuario) == 0 && strcmp(requisicoes[i].estado,"Pendente") == 0) {
            strcpy(requisicoes[i].estado, "Aprovada");
            printf("Requisicao aprovada!\n");
            return;
        }
    }

    printf("Requisicao nao encontrada ou ja aprovada/rejeitada.\n");
}

void rejeitarRequisicao(Requisicao requisicoes[], int *numRequisicoes) {
    char usuario[50];
    printf("Digite o nome do usuario para rejeitar a requisicao: ");
    scanf("%s", usuario);

    for (int i = 0; i < numRequisicoes; i++) {
        if (strcmp(requisicoes[i].usuario, usuario) == 0 && strcmp(requisicoes[i].estado,"Pendente") == 0) {
            strcpy(requisicoes[i].estado, "Rejeitada");
            printf("Requisicao rejeitada!\n");
            return;
        }
    }

    printf("Requisicao nao encontrada ou ja foi aprovada/rejeitada.\n");
}

void registrarDevolucao(Requisicao requisicoes[], int numRequisicoes) {
    char usuario[50];
    printf("Introduza o nome do usuario para registrar a devolucao: ");
    scanf("%s", usuario);

    for (int i = 0; i < numRequisicoes; i++) {
        if (strcmp(requisicoes[i].usuario, usuario) == 0 && strcmp(requisicoes[i].estado, "Aprovada") == 0) {
            requisicoes[i].devolvido = 1;
            printf("Devolucao registrada com sucesso!\n");
            return;
        }
    }
    printf("Usuario nao foi encontrado ou requisicao nao foi aprovada.\n");
}

void listarRequisicoesPorUsuario(Requisicao requisicoes[], int numRequisicoes) {
    char usuario[50];
    printf("Introduza o nome do usuario para listar as requisicoes: ");
    scanf("%s", usuario);

    printf("\nRequisicoes de %s:\n", usuario);
    for (int i = 0;i < numRequisicoes; i++) {
        if (strcmp(requisicoes[i].usuario, usuario) == 0) {
            printf("Equipamento: %s, Estado: %s, Devolvido: %s\n",
                   requisicoes[i].equipamento, requisicoes[i].estado,
                   (requisicoes[i].devolvido) ? "Sim" : "Nao");
        }
    }
}

void listarRequisicoesAprovadas(Requisicao requisicoes[], int numRequisicoes) {
    printf("\nRequisicoes Aprovadas:\n");
    for (int i = 0; i < numRequisicoes; i++) {
        if (strcmp(requisicoes[i].estado, "Aprovada") == 0) {
            printf("Usuario: %s, Equipamento: %s, Devolvido: %s\n",
                   requisicoes[i].usuario, requisicoes[i].equipamento,
                   (requisicoes[i].devolvido) ? "Sim" : "Nao");
        }
    }
}

void listarRequisicoesDevolvidas(Requisicao requisicoes[], int numRequisicoes) {
    printf("\nRequisicoes Devolvidas:\n");
    for (int i = 0; i < numRequisicoes; i++) {
        if (requisicoes[i].devolvido) {
            printf("Usuario: %s, Equipamento: %s\n",
                   requisicoes[i].usuario, requisicoes[i].equipamento);
        }
    }
}

int main() {
    Requisicao requisicoes[100];
    int numRequisicoes = 0;
    int opcao;

    do {
    	printf("\nSistema Gestao de Requisicao e Devolucao de Equipamentos Informaticos\n");
        printf("----Menu----\n\n");
        printf("1. Adicionar Requisicao\n");
        printf("2. Listar Requisicoes\n");
        printf("3. Aprovar Requisicao\n");
        printf("4. Rejeitar Requisicao\n");
        printf("5. Registrar Devolucao\n");
        printf("6. Listar Requisicoes por Usuario\n");
        printf("7. Listar Requisicoes Aprovadas\n");
        printf("8. Listar Requisicoes Devolvidas\n");
        printf("9.+Info.\n");
        printf("10. Sair\n\n");
        printf("Digite a opcao que deseja: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionarRequisicao(requisicoes, &numRequisicoes);
                break;
            case 2:
                listarRequisicoes(requisicoes, numRequisicoes);
                break;
            case 3:
                aprovarRequisicao(requisicoes, numRequisicoes);
                break;
            case 4:
                rejeitarRequisicao(requisicoes, numRequisicoes);
                break;
            case 5:
                registrarDevolucao(requisicoes, numRequisicoes);
                break;
            case 6:
                listarRequisicoesPorUsuario(requisicoes, numRequisicoes);
                break;
            case 7:
                listarRequisicoesAprovadas(requisicoes, numRequisicoes);
                break;
            case 8:
                listarRequisicoesDevolvidas(requisicoes, numRequisicoes);
                break;
            case 9:
                printf("\nSistema de Gestao desenvolvido por:\n-ERIC REIS\n-LIEDSON DELGADO\n-TIAGO DONGO\nFoi criado em:30/01/2024\n\n");
                break;
            case 10:
                printf("Encerrando o programa...\n");
                break;
            default:
                printf("[OPCAO INVALIDA]\nTente novamente.\n\n");       
        }
    } while (opcao != 10);
}
