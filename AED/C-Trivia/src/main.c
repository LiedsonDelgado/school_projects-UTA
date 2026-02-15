/*
- Projeto Final da disciplina de Algoritmos e Estruturas de Dados

- Tema do Quiz: Ciência e Tecnologia

- Autores:
    - Hélio Rocha 
    - Leonardo Domingues
    - Liedson Delgado
    - Tiago Dongo
*/

#include<stdio.h>
#include"quiz.h"
#include"util.h"

int main(){
    setlocale(LC_ALL, "PORTUGUESE");

    QuestionList qList;
    PlayerTree *pTree = NULL;

    createQuestionList(&qList);

    menu(&qList, &pTree);

    freeQuestionList(&qList);
    freePlayerTree(&pTree);

    printf("\n Obrigado por jogar C-Trivia.\n");
    
    return 0;
}
