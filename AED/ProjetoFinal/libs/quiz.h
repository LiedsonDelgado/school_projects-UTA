/*
-> File Description
-> Ficheiro responsavel por armazenar headers e as assinaturas de funções
*/

#ifndef QUIZ_H_INCLUDED
#define QUIZ_H_INCLUDED

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>

//Estruturas de Dados
//-------------------

//Estrutura que representa a arvore de usuarios/jogadores
typedef struct tree{
    char* playerName;
    int score;
    struct tree *left;
    struct tree *right;
}Tree;

//Estrutura da lista de perguntas
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

//Prototipos/Assinatura das Funcoes
//----------------------

/**
 * @brief Função que imprime o menu principal do sistema
 */
void menu();

Player* createPlayerTreeNode(); //cria a raiz da arvore e inicializa a arvore
void addPlayerIntoTree(Player** tree,char* playerName,int score); //adiciona o no que contem informacoes do jogador na arvore
int removePlayerFromTree(Player** tree,char* playerName); //remove o no que contem informacoes do jogador na arvore

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
 * @brief Cria uma nova questão
 * @param questionText Texto da pergunta
 * @param options Array de 4 opções
 * @param correctAnswer Resposta correta (A-D)
 * @return Ponteiro para questão ou NULL se erro
 */
QuestionList* createQuestionList(QuestionList *qlist); //cria o primeiro no da lista de questoes

/**
 * @brief Adiciona uma questão ao final da lista
 * @param qList Ponteiro para a lista
 * @param question Questão a adicionar
 */
void addNewQuestion(QuestionList *qList, QuestionNode *question); //recebe como parametro a lista de questoes e a questao que se quer adicionar nela

/**
 * @brief Remove uma questão da lista
 * @param qList Ponteiro para a lista
 * @param questionToRemove Questão a remover
 * @return `1` se sucesso, `0` se erro
 */
int removeQuestion(QuestionList *qList, QuestionNode *questionToRemove); //seleciona o elemento na lista guardar ele numa var auxiliar e ajustar a lista e apagar ele

char* searchPlayer(Player* playerTree);

void showAllTheQuestions(QuestionList* qList);
void showScore(QuestionList* qList);

#endif