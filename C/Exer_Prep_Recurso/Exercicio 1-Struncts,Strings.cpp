#include<stdio.h>
#include<string.h>

typedef struct
{
    char titulo[100];
    int duracao_mnts;
    char disp_aluguer[15];
} DVD;

void m_titulo(char titulo[100])
{
    printf("Titulo: %s\n", titulo);
}

void m_duracao(int duracao_mnts)
{
    printf("Duracao: %d\n", duracao_mnts);
}

void m_disp_aluguer(char disp_aluguer[15])
{
    printf("Disponibilidade Aluguer: ");
    for (int i = 0; i < 15; i++)
    {
        printf("%c ", disp_aluguer[i]);
    }
    printf("\n");
}

int main()
{
    int duracao_mnts;
    char titulo[100], disp_aluguer[15];

    printf("Titulo:\n");
    scanf("%s", titulo);

    printf("Duracao:\n");
    scanf("%d", &duracao_mnts);

    printf("Disponibilidade (15 characters):\n");
    for (int i = 0; i < 15; i++)
    {
        scanf(" %c", &disp_aluguer[i]);
    }

    m_titulo(titulo);
    m_duracao(duracao_mnts);
    m_disp_aluguer(disp_aluguer);

    return 0;
}

