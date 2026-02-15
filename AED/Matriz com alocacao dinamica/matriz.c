#include <stdio.h>
#include <stdlib.h>

int** criarMatriz(int linhas, int colunas) {
    int **matriz = (int **)malloc(linhas * sizeof(int*));

    if (matriz == NULL) {
        printf("Erro ao alocar memoria\n");
        exit(1);
    }

    for (int i = 0; i < linhas; i++) {
        matriz[i] = (int *)malloc(colunas * sizeof(int));

        if (matriz[i] == NULL) {
            printf("Erro ao alocar memoria\n");
            exit(1);
        }
    }

    return matriz;
}

void adicionarElementos(int **matriz, int linhas, int colunas) {
    int valor = 1;

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            matriz[i][j] = valor++;
        }
    }
}

void imprimirMatriz(int **matriz, int linhas, int colunas) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

void libertarMatriz(int **matriz, int linhas) {
    for (int i = 0; i < linhas; i++) {
        free(matriz[i]);
    }
    free(matriz);
}

int main() {
    int linhas = 3;
    int colunas = 4;

    int **matriz = criarMatriz(linhas, colunas);

    adicionarElementos(matriz, linhas, colunas);
    imprimirMatriz(matriz, linhas, colunas);

    libertarMatriz(matriz, linhas);

    return 0;
}
