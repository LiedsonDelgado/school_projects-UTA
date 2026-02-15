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

void testRemoveQuestion() {
    QuestionList qList;
    createQuestionList(&qList);

    QuestionNode *q1 = createQuestion("P1", (char*[]){"A","B","C","D"}, 'A');
    QuestionNode *q2 = createQuestion("P2", (char*[]){"A","B","C","D"}, 'B');

    addNewQuestion(&qList, q1);
    addNewQuestion(&qList, q2);

    printf("\n-Teste removeQuestion:\n");

    // remover no do final
    printf("-> Remover no final (q2): ");
    if (removeQuestion(&qList, q2) && q1->next == NULL) {
        printf("[PASS]: no final removido corretamente\n");
    } else {
        printf("[FAIL]: falha ao remover no final\n");
    }

    // remover no do inicio
    printf("-> Remover no inicio (q1): ");
    if (removeQuestion(&qList, q1) && emptyQuestionList(qList)) {
        printf("[PASS]: no inicio removido corretamente, lista vazia\n");
    } else {
        printf("[FAIL]: falha ao remover no inicio\n");
    }

    // tentar remover no inexistente
    printf("-> Remover no inexistente (q1 novamente): ");
    if (!removeQuestion(&qList, q1)) {
        printf("[PASS]: retorno 0 ao tentar remover no inexistente\n");
    } else {
        printf("[FAIL]: falha ao lidar com no inexistente\n");
    }
}

char generateCorrectOption(){
    //ASCII Code: A-65, B-66, C-67, D-68

    srand(time(NULL)); //gera um novo numero

    int num = rand()%(68-65+1)+65;
    char opt = (char)num;

    return opt;
}

int main(){

    printf("\n=== INICIO DOS TESTES DO QUIZ ===\n");

    testCreateQuestionList();
    testEmptyQuestionList();
    testCreateQuestion();
    testAddNewQuestion();
    testRemoveQuestion();

    printf("\n=== INICIO DOS TESTES DO QUIZ ===\n");

    printf("\n=== TESTE GERACAO DE ALEATORIA DE CARACTERES ===\n");
    char opt = generateCorrectOption();
    printf("%c",opt);
    return 0;


    //-----------------------------------------------------
//ESTA TERMINADO & FUNCIONANDO
Tree* createPlayerTreeNode(){
    Tree* node = (Player*)malloc(sizeof(Tree));
    if(node == NULL){
        printf("Erro ao alocar memoria!\n");
        exit(EXIT_FAILURE);
    }

    strcpy(node->playerName,"\0");
    node->score = 0;
    node->left = NULL;
    node->right = NULL;

    return node;
}

//ESTA TERMINADO & FUNCIONANDO
void addPlayerIntoTree(Tree** tree,char playerName[100],int score){
    Tree* node = createPlayerTreeNode();

    strcpy(node->playerName,playerName);
    node->score = score;

    if(*tree == NULL){
        *tree = node;
        return;
    }

    Tree* current = *tree;
    Tree* father = NULL;

    while(current != NULL){
        father = current;
        if(strcmp(node->playerName,current->playerName) < 0){
            current = current->left;
        }else{
            current = current->right;
        }
    }

    if(strcmp(father->playerName,playerName) < 0){
        father->right = node;
    }else{
        father->left = node;
    }
}
    //-----------------------------------------------------
}