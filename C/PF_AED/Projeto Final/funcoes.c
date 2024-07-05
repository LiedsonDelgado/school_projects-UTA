#include "prototipos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

// ################# OPÇÃO-1 ##################### //

void adicionarMusica(Musica **playlist){
    Musica *novaMusica = (Musica *)malloc(sizeof(Musica));
    printf(" Título: ");
    scanf(" %[^\n]", novaMusica->titulo);        // Lê uma linha inteira incluindo espaços
    printf(" Artista: ");
    scanf(" %[^\n]", novaMusica->artista);       // Lê uma linha inteira incluindo espaços
    printf(" Duração (segundos): ");
    scanf("%d", &novaMusica->duracao);
    printf(" Ano: ");
    scanf("%d", &novaMusica->ano);
    novaMusica->proxima = NULL;

    if (*playlist == NULL) {
        *playlist = novaMusica;
    } else {
        Musica *temp = *playlist;
        while (temp->proxima != NULL) {
            temp = temp->proxima;
        }
        temp->proxima = novaMusica;
    }
    printf("\n Música adicionada na PlayList!\n\n");
}


// ################# OPÇÃO-2 ##################### //

void removerMusica(Musica **playlist) {
    char titulo[100];
    printf(" Título da música a remover: ");
    scanf(" %[^\n]", titulo);

    Musica *temp = *playlist, *prev = NULL;

    if (temp != NULL && strcmp(temp->titulo, titulo) == 0) {
        *playlist = temp->proxima;
        free(temp);
        printf(" Música removida da PlayList!\n");
        return;
    }

    while (temp != NULL && strcmp(temp->titulo, titulo) != 0) {
        prev = temp;
        temp = temp->proxima;
    }

    if (temp == NULL) {
        printf(" Música não encontrada!\n");
        return;
    }

    prev->proxima = temp->proxima;
    free(temp);
    printf(" Música removida!\n");
}


// ################# OPÇÃO-3 ##################### //

void reproduzirPlaylist(Musica *playlist, int ordem) {
    if (playlist == NULL) {
        printf(" Playlist vazia!\n");
        return;
    }

    if (ordem == 1) {
        Musica *temp = playlist;
        while (temp != NULL) {
            printf(" Título: %s, Artista: %s, Duração: %d segundos, Ano: %d\n",
                   temp->titulo, temp->artista, temp->duracao, temp->ano);
            temp = temp->proxima;
        }
    } else if (ordem == 2) {
        // Reproduzir em ordem decrescente: usamos recursão para imprimir em ordem inversa
        if (playlist->proxima != NULL) {
            reproduzirPlaylist(playlist->proxima, ordem);
        }
        printf(" Título: %s, Artista: %s, Duração: %d segundos, Ano: %d\n",
               playlist->titulo, playlist->artista, playlist->duracao, playlist->ano);
    } else {
        printf(" Ordem inválida!\n");
    }
}


// ################# OPÇÃO-4 ##################### //

void procurarMusica(Musica *playlist) {
    int opcao, ano;
    char artista[100];
    printf(" Procurar por:\n1. Artista\n2. Ano\n");
    scanf("%d", &opcao);

    if (opcao == 1) {
        printf(" Nome do artista: ");
        scanf(" %[^\n]", artista);
        Musica *temp = playlist;
        while (temp != NULL) {
            if (strcmp(temp->artista, artista) == 0) {
                printf(" Título: %s, Artista: %s, Duração: %d segundos, Ano: %d\n",
                       temp->titulo, temp->artista, temp->duracao, temp->ano);
            }
            temp = temp->proxima;
        }
    } else if (opcao == 2) {
        printf(" Ano: ");
        scanf("%d", &ano);
        Musica *temp = playlist;
        while (temp != NULL) {
            if (temp->ano == ano) {
                printf(" Título: %s, Artista: %s, Duração: %d segundos, Ano: %d\n",
                       temp->titulo, temp->artista, temp->duracao, temp->ano);
            }
            temp = temp->proxima;
        }
    } else {
        printf(" Opção inválida!\n");
    }
}


// ################# OPÇÃO-5 ##################### //

void duracaoPlaylist(Musica *playlist) {
    int totalMusicas = 0, totalDuracao = 0;
    Musica *temp = playlist;
    while (temp != NULL) {
        totalMusicas++;
        totalDuracao += temp->duracao;
        temp = temp->proxima;
    }

    int horas = totalDuracao / 3600;
    int minutos = (totalDuracao % 3600) / 60;
    int segundos = totalDuracao % 60;

    printf(" Número total de músicas: %d\n", totalMusicas);
    printf(" Tempo total de duração: %d horas, %d minutos, %d segundos\n", horas, minutos, segundos);
}


// ################# OPÇÃO-6 ##################### //

void avancarPlaylist(Musica **playlist, Musica **atual) {
    if (*atual == NULL) {
        *atual = *playlist;
    } else if ((*atual)->proxima != NULL) {
        *atual = (*atual)->proxima;
    } else {
        printf(" Já está na última música da playlist!\n");
    }

    if (*atual != NULL) {
        printf(" Reproduzindo: %s - %s\n", (*atual)->titulo, (*atual)->artista);
    }
}


// ################# OPÇÃO-7 ##################### //

void retrocederPlaylist(Musica **playlist, Musica **atual) {
    if (*atual == NULL) {
        printf(" Playlist vazia ou não começou a reprodução!\n");
        return;
    }

    if (*atual == *playlist) {
        printf(" Já está na primeira música da playlist!\n");
        return;
    }

    Musica *temp = *playlist;
    while (temp->proxima != *atual) {
        temp = temp->proxima;
    }
    *atual = temp;

    if (*atual != NULL) {
        printf(" Reproduzindo: %s - %s\n", (*atual)->titulo, (*atual)->artista);
    }
}


// ################# OPÇÃO-8 ##################### //

void guardarPlaylist(Musica *playlist) {
    FILE *arquivo = fopen("playlist.txt", "w");
    if (arquivo == NULL) {
        printf(" Erro ao abrir o arquivo!\n");
        return;
    }

    Musica *temp = playlist;
    while (temp != NULL) {
        fprintf(arquivo, "%s\n%s\n%d\n%d\n", temp->titulo, temp->artista, temp->duracao, temp->ano);
        temp = temp->proxima;
    }
    fclose(arquivo);
    printf(" Playlist guardada com sucesso!\n");
}


// ################# OPÇÃO-9 ##################### //

void carregarPlaylist(Musica **playlist) {
    FILE *arquivo = fopen("playlist.txt", "r");
    if (arquivo == NULL) {
        printf(" Erro ao abrir o arquivo!\n");
        return;
    }

    char titulo[100], artista[100];
    int duracao, ano;
    while (fscanf(arquivo, " %[^\n]\n%[^\n]\n%d\n%d\n", titulo, artista, &duracao, &ano) == 4) {
        Musica *novaMusica = (Musica *)malloc(sizeof(Musica));
        strcpy(novaMusica->titulo, titulo);
        strcpy(novaMusica->artista, artista);
        novaMusica->duracao = duracao;
        novaMusica->ano = ano;
        novaMusica->proxima = NULL;

        if (*playlist == NULL) {
            *playlist = novaMusica;
        } else {
            Musica *temp = *playlist;
            while (temp->proxima != NULL) {
                temp = temp->proxima;
            }
            temp->proxima = novaMusica;
        }
    }
    fclose(arquivo);
    printf(" Playlist carregada com sucesso!\n");
}
