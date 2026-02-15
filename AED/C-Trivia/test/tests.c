#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"quiz.h"
#include"util.h"

void testCreateQuestionList(){
    QuestionList qList;
    createQuestionList(&qList);

    printf("\n-Teste de createQuestionList \n");
    if (qList == NULL){
        printf("[PASS]: lista foi criada  com sucesso\n");
    }else{
        printf("[FAIL]: a lista nao foi criada\n");
    }
}

void testEmptyQuestionList(){
    QuestionList qList;
    createQuestionList(&qList);

    printf("\n-Teste emptyQuestionList com lista vazia\n ");
    if (emptyQuestionList(qList) == 1) {
        printf("[PASS]: return 1 - lista esta  vazia\n");
    }else {
        printf("[FAIL]: return 0 - lista nao esta  vazia\n");
    }

    QuestionNode *q = createQuestion("Q1", (char*[]){"A","B","C","D"}, 'A');
    addNewQuestion(&qList, q);

    printf("\n-Teste emptyQuestionList com lista com no: \n");
    if (emptyQuestionList(qList) ==  0) {
        printf("[PASS]: return 0  - lista nao esta vazia\n");
    }else {
        printf("[FAIL]: return 1 - lista  vazia\n");
    }
}

void testCreateQuestion(){
    char *op[4] = {"A","B","C","D"};
    char cat = 'A';
    QuestionNode *q = createQuestion("Onde se localizaa capital de Cabo Verde",op,cat);
    printf("\n-Teste createQuestion\n");
    if (q != NULL &&
        strcmp(q->question, "Onde se localizaa capital de Cabo Verde") == 0 &&
        strcmp(q->options[0],  "A") == 0 &&
        strcmp(q->options[1],  "B") == 0 &&
        strcmp(q->options[2],  "C") == 0 &&
        strcmp(q->options[3],  "D") == 0 &&
        q->correctAnswer == cat &&
        q->next == NULL
    ){
        printf("[PASS]: no criado corretamente com pergunta, opcoes e resposta\n");
    } else {
        printf("[FAIL]: erro na criacao do no da pergunta\n");
    } 
}

void testAddNewQuestion() {
    QuestionList qList;
    createQuestionList(&qList);

    QuestionNode *q1 = createQuestion("P1", (char*[]){"A","B","C","D"}, 'A');
    QuestionNode *q2 = createQuestion("P2", (char*[]){"A","B","C","D"}, 'B');

    addNewQuestion(&qList, q1);
    addNewQuestion(&qList, q2);

    printf("\n-Teste addNewQuestion:\n");
    if (qList == q1 && q1->next == q2 && q2->next == NULL) {
        printf("[PASS]: multiplos nos adicionados corretamente\n");
    } else {
        printf("[FAIL]: erro ao adicionar nos na lista\n");
    }
}

// void testRemoveQuestion() {
//     QuestionList qList;
//     createQuestionList(&qList);

//     QuestionNode *q1 = createQuestion("P1", (char*[]){"A","B","C","D"}, 'A');
//     QuestionNode *q2 = createQuestion("P2", (char*[]){"A","B","C","D"}, 'B');

//     addNewQuestion(&qList, q1);
//     addNewQuestion(&qList, q2);

//     printf("\n-Teste removeQuestion:\n");

//     // remover no do final
//     printf("-> Remover no final (q2): ");
//     if (removeQuestion(&qList, q2) && q1->next == NULL) {
//         printf("[PASS]: no final removido corretamente\n");
//     } else {
//         printf("[FAIL]: falha ao remover no final\n");
//     }

//     // remover no do inicio
//     printf("-> Remover no inicio (q1): ");
//     if (removeQuestion(&qList, q1) && emptyQuestionList(qList)) {
//         printf("[PASS]: no inicio removido corretamente, lista vazia\n");
//     } else {
//         printf("[FAIL]: falha ao remover no inicio\n");
//     }

//     // tentar remover no inexistente
//     printf("-> Remover no inexistente (q1 novamente): ");
//     if (!removeQuestion(&qList, q1)) {
//         printf("[PASS]: retorno 0 ao tentar remover no inexistente\n");
//     } else {
//         printf("[FAIL]: falha ao lidar com no inexistente\n");
//     }
// }

void testShowAllQuestions(){
    QuestionList list;
    createQuestionList(&list);

    QuestionNode *q1 = createQuestion("P1", (char*[]){"A","B","C","D"}, 'A');
    QuestionNode *q2 = createQuestion("P2", (char*[]){"A","B","C","D"}, 'B');

    addNewQuestion(&list, q1);
    addNewQuestion(&list, q2);

    printf("\nTeste showAllQuestions:\n");
    showAllQuestions(list);

    if(list == q1 && list->next == q2 && q2->next == NULL){
        printf("[PASS]: lista percorrida corretamente\n");
    } else{
        printf("[FAIL]: erro ao percorrer a lista\n");
    }
}

void testRemoveQuestionByPosition() {
    QuestionList qList;
    createQuestionList(&qList);

    char *q1Opts[] = {
        strdup("Praia de Santa Maria"),
        strdup("Cidade Velha"),
        strdup("Mindelo"),
        strdup("Sal Rei")
    };
    QuestionNode *q1 = createQuestion(strdup("Qual e a capital turistica de Cabo Verde?"), q1Opts, 'A');
    
    char *q2Opts[] = {
        strdup("Amapa"),
        strdup("Cabo Verde"),
        strdup("Moçambique"),
        strdup("Angola")
    };
    QuestionNode *q2 = createQuestion(strdup("Qual destes paises e um arquipelago africano?"), q2Opts, 'B');

    addNewQuestion(&qList, q1);
    addNewQuestion(&qList, q2);

    printf("\n-Teste removeQuestionByPosition:\n");

    // remover no do final (posição 2)
    printf("-> Remover no final (posicao 2): ");
    if (removeQuestionByPosition(&qList, 2) && q1->next == NULL) {
        printf("[PASS]: no final removido corretamente\n");
    } else {
        printf("[FAIL]: falha ao remover no final\n");
    }

    // remover no do inicio (posição 1)
    printf("-> Remover no inicio (posicao 1): ");
    if (removeQuestionByPosition(&qList, 1) && emptyQuestionList(qList)) {
        printf("[PASS]: no inicio removido corretamente, lista vazia\n");
    } else {
        printf("[FAIL]: falha ao remover no inicio\n");
    }

    // tentar remover no inexistente
    printf("-> Remover no inexistente (posicao 1 novamente): ");
    if (!removeQuestionByPosition(&qList, 1)) {
        printf("[PASS]: retorno 0 ao tentar remover no inexistente\n");
    } else {
        printf("[FAIL]: falha ao lidar com no inexistente\n");
    }
}

void testSaveLoadQuestionList() {
    QuestionList qList;
    createQuestionList(&qList);

    printf("\n--- Teste save/load QuestionList ---\n");

    // --- Criar perguntas ---
    char *q1Opts[] = {
        strdup("Praia de Santa Maria"),
        strdup("Cidade Velha"),
        strdup("Mindelo"),
        strdup("Sal Rei")
    };
    QuestionNode *q1 = createQuestion(strdup("Qual e a capital turistica de Cabo Verde?"), q1Opts, 'A');
    addNewQuestion(&qList, q1);

    char *q2Opts[] = {
        strdup("Amapa"),
        strdup("Cabo Verde"),
        strdup("Moçambique"),
        strdup("Angola")
    };
    QuestionNode *q2 = createQuestion(strdup("Qual destes paises e um arquipelago africano?"), q2Opts, 'B');
    addNewQuestion(&qList, q2);

    // --- Salvar a lista ---
    saveQuestionList(qList);

    // --- Liberar memória ---
    freeQuestionList(&qList);

    // --- Carregar a lista ---
    loadQuestionList(&qList);

    // --- Mostrar perguntas carregadas ---
    printf("\nPerguntas carregadas do ficheiro:\n");
    showAllQuestions(qList);

    // --- Verificações basicas ---
    int passed = 1;
    if (emptyQuestionList(qList)) passed = 0;

    if (passed && strcmp(qList->question, "Qual e a capital turistica de Cabo Verde?") != 0)
        passed = 0;
    if (passed && qList->correctAnswer != 'A')
        passed = 0;

    if (passed && qList->next != NULL) {
        if (strcmp(qList->next->question, "Qual destes paises e um arquipelago africano?") != 0)
            passed = 0;
        if (qList->next->correctAnswer != 'B')
            passed = 0;
    } else {
        passed = 0;
    }

    if (passed) {
        printf("[PASS]: save/load QuestionList funcionou corretamente\n");
    } else {
        printf("[FAIL]: erro no save/load QuestionList\n");
    }

    // --- Liberar memória final ---
    freeQuestionList(&qList);
}

int main(){

    printf("\n=== INICIO DOS TESTES DO QUIZ ===\n");

    testCreateQuestionList();
    testEmptyQuestionList();
    testCreateQuestion();
    testAddNewQuestion();
    //testRemoveQuestion();
    testShowAllQuestions();
    testRemoveQuestionByPosition();
    testSaveLoadQuestionList();

    printf("\n=== FIM DOS TESTES DO QUIZ ===\n");

    return 0;
}
