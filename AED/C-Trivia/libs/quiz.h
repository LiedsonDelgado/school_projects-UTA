/**
 * @file quiz.h
 * @brief Header principal do sistema de quiz
 * 
 * Este ficheiro contém as declarações de estruturas de dados e funções
 * para o sistema de gerenciamento de quiz, incluindo:
 * - Árvore binária de jogadores
 * - Lista ligada de questões
 * - Funções de manipulação de dados
 */

#ifndef QUIZ_H_INCLUDED
#define QUIZ_H_INCLUDED

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<locale.h>

//========================= ESTRUTURAS DE DADOS ========================================

/**
 * @brief Estrutura que de dados responsavel por armazenar os jogadores
 * 
 * @param playerName array de caracteres que armazena o nome do jogador
 * @param score inteiro que armazena a pontuação do jogador
 * @param *left ponteiro para o nó filho esquerdo
 * @param *right ponteiro para o nó filho direito
 */
typedef struct player {
    char *playerName;      
    int score;                 
    struct player *left;       
    struct player *right;      
} PlayerTree;

/**
 * @brief estrututa de dados responsavel por armazenar uma lista de perguntas
 * @param *question ponteiro do tipo char que armazera a pergunta
 * @param *option array de string que armazera a `4 opções` de resposta 
 * @param correctAnswer caracter que armazera a resposta correta
 * @param *next ponteiro para o proximo nó da lista
 * 
 */
typedef struct questionNode{
    char *question;
    char *options[4];
    char correctAnswer;
    struct questionNode *next;
}QuestionNode;

/**
 * @brief Tipo para representar uma lista de questões
 */
typedef QuestionNode *QuestionList;

//========================= FUNÇÕES DE MANIPULAÇÃO DO QUIZ ========================================

/**
 * @brief Função que imprime o menu principal do sistema
 * 
 * Apresenta um menu com 7 opções (0-6) e processa a escolha do utilizador
 * em loop até que escolha sair (opção 0).
 * @param qList Ponteiro para a lista de questões (será passada às funções)
 * @param pTree Ponteiro duplo para a árvore de jogadores (para adicionar/consultar)
 * @return Void. Executa até o utilizador escolher sair (opção 0)
 */
void menu(QuestionList *qList, PlayerTree **pTree);

/**
 * @brief Executa um quiz completo com um jogador
 * @param qList Lista de questões a serem apresentadas
 * @param pTree Ponteiro duplo para a árvore de jogadores (para guardar resultado)
 * @return Void. A pontuação é guardada na árvore de jogadores
 */
void playGame(QuestionList qList, PlayerTree **pTree);

//========================= FUNÇÕES DE MANIPULAÇÃO DE PLAYERS ======================================

/**
 * @brief Cria e inicializa um novo nó para a árvore de jogadores 
 * 
 * Aloca dinamicamente memória para uma estrutura Player e inicializa
 * todos os seus campos com valores padrão. 
 * @returns `Ponteiro` para o novo nó Player inicializado\\
 * @returns `NULL` se falhar na alocação  da memoria 
 */
PlayerTree* createPlayerTreeNode();

/**
 * @brief Adiciona um novo jogador à árvore binária de pesquisa ordenada por nome
 * 
 * Insere um novo nó mantendo a ordem alfabética crescente dos nomes dos jogadores.
 * Se a árvore estiver vazia, o novo nó torna-se a raiz.
 * 
 * @param tree Ponteiro duplo para a raiz da árvore. 
 * @param playerName Nome do jogador (máx. 99 caracteres + terminador nulo).
 * @param score Pontuação inicial do jogador (inteiro, típico: 0-100).
 */
void addPlayerIntoTree(PlayerTree** tree,char playerName[], int score); 

/**
 * @brief Remove o no que contem informacoes do jogador na arvore
 * 
 * @param tree Ponteiro duplo para a raiz da árvore. 
 * @param playerName Nome do jogador (máx. 99 caracteres + terminador nulo).
 * 
 * @return `1` - se o jogador foi encontrado e removido com sucesso.\\
 * @return `0` - se o jogador não foi encontrado ou árvore está vazia.
 */
int removePlayerFromTree(PlayerTree** tree,char* playerName); 

/**
 * @brief Mostra a classificação dos jogadores em ordem alfabética  
 * @param tree Raiz da árvore de jogadores
 * @return `Void` - Imprime a tabela no stdout
 */
void displayScoreboard(PlayerTree* tree);

/**
 * @brief Função auxiliar para mostrar scoreboard em inorder
 */
void displayScoreboardInOrder(PlayerTree* tree);

/**
 * @brief Função que procura um jogador pelo seu nome e exibe a sua pontuação
 * Faz o percurso em pre-ordem pelos nós da árvore ate encontrar o no procurado
 */
void searchPlayer(PlayerTree** treem,char* playerName);

/**
 * @brief Liberta toda a memória da árvore de jogadores
  * Percorre recursivamente toda a árvore (pós-ordem) e liberta
 * a memória de cada nó e seu respectivo nome.
 * 
 * Processo (pós-ordem):
 * 1. Liberta subárvore esquerda
 * 2. Liberta subárvore direita
 * 3. Liberta o nó atual
 * 
 * @param tree Ponteiro duplo para a raiz da árvore
 * 
 * @return `Void` - Define o ponteiro como NULL após libertar
 */
void freePlayerTree(PlayerTree** tree);

//========================= FUNÇÕES DE MANIPULAÇÃO DO QUIZ ========================================

/**
 * @brief Inicializa uma lista de questões como vazia
 * @param qlist Ponteiro para a lista a ser inicializada
 */
void createQuestionList(QuestionList *qlist); 

/**
 * @brief Verifica se uma lista de questões está vazia
 * @param qList Lista de questões a verificar
 * @return 1 se vazia, 0 se não
 */
int emptyQuestionList(QuestionList qList);

/**
 * @brief Adiciona uma questão ao final da lista
 * @param qList Ponteiro para a lista
 * @param question Questão a adicionar
 */
void  addNewQuestion(QuestionList *qList, QuestionNode *question);

/**
 * @brief Cria uma nova questão
 * @param questionText Texto da pergunta
 * @param options Array de 4 opções
 * @param correctAnswer Resposta correta (A-D)
 * @return Ponteiro para questão ou NULL se erro
 */
QuestionNode *createQuestion(char *question, char *options[4], char correctAnswer);

/**
 * @brief Remove uma questão da lista
 * @param qList Ponteiro para a lista
 * @param questionToRemove Questão a remover
 * @return `1` se sucesso, `0` se erro
 */
int removeQuestion(QuestionList *qList, QuestionNode *questionToRemove);

/**
 * @brief Mostra todas as  questões da lista, com suas opções e resposta correta
 */
void showAllQuestions(QuestionList qlist);

/**
 * @brief Liberta toda a memoria alocada para a lista
 * @param *list ponteiro para a lista
 */
void freeQuestionList(QuestionList *qlist);

/**
 * @brief Remove uma questão da lista pela posição (0 = primeira)
 * @param qlist Ponteiro para a lista
 * @param questionPosition Posição da questão a remover
 * @return 1 se sucesso, 0 se posição inválida ou lista vazia
 */
int removeQuestionByPosition(QuestionList *qlist, int questionPosition);

//========================= FUNÇÕES DE MANIPULAÇÃO DE FICHEIROS ========================================

void saveQuestionList(QuestionList qlist);

void loadQuestionList(QuestionList *qlist);

#endif