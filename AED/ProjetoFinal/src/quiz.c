/*
-> File Description
-> Ficheiro responsavel por armazenar a lógica das funções
*/

#include"quiz.h"
#include"util.h"

int validateInt(const char *prompt){
    /*
    valueInput - armazena o valor digitado pelo usuario
    inputResults - armazena o retorno da função scanf (1 = sucesso, 0 = falso)
    */
    int valueInput, inputResults;
    //variavel que armazena cada caratere lido
    // É int porque getchar() retorna um inteiro (incluindo EOF = -1)
    int character;
    do {
        printf("%s", prompt);
        inputResults = scanf("%d", &valueInput);

        //loop usado para consumir carateres restantes no buffer, se houver
        //EOF - End Of File (-1), detecta fim da entrada
        while((character = getchar()) != '\n' && character != EOF);

        //verifica se o retorno do scanf é diferente de 1 E/OU se o valor digitado é negativo
        if (inputResults !=  1 || valueInput <  0){
            printf("ERRO: Entrada invalida, por favor digite um número inteiro não negativo!\n");
        }
    } while (inputResults != 1 || valueInput < 0);

    return valueInput;
}

/**
 * @brief Função que imprime o menu principal do projeto
 */
void menu(){
    int option;
    do
    {
        printf("\n----- QUIZ GAME -----\n");
        printf("1 - Jogar\n");
        printf("2 - Adicionar nova pergunta\n");
        printf("3 - Eliminar pergunta\n");
        printf("4 - Mostrar  todas as perguntas\n");
        printf("5 - Mostrar classificação\n");
        printf("6 - Procurar jogador\n");
        printf("0 - Sair\n");
        option = validateInt("Digite a sua opção: ");

        switch (option){
            case 0:
            printf("Saindo...\n");
            break;

            case 1:
            break;

            case 2:
            break;

            case 3:
            break;

            case 4:
            break;

            case 5:
            break;

            case 6:
            break;

            default:
            printf("ERRO: Opção inválida, tente novamente!\n");
            break;
        }
    } while (option != 0);
}

//ESTA TERMINADO & FUNCIONANDO
Tree* createPlayerTreeNode(){
    Tree* node = (Tree*)malloc(sizeof(Tree));
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

int removePlayerFromTree(Tree** tree,char* playerName){
    if (tree == NULL || *tree == NULL || playerName == NULL){
        return 0;}

    int cmp = strcmp(playerName, (*tree)->playerName);

    if (cmp < 0){
        return removePlayerFromTree(&(*tree)->left, playerName){
        }else if (cmp > 0){
            
        }

        //Caso 1:Folha

        //Caso 2: Filho

        //Caso 3: Filhos

    return 1;
}

void createQuestionList(QuestionList *qlist){
    *qlist = NULL;
}

int emptyQuestionList(QuestionList qList){
    return (qList == NULL);
}

QuestionNode *createQuestion(char *question, char *options[4], char correctAnswer){
    QuestionNode *newNode = (QuestionNode*)malloc(sizeof(QuestionNode));
    if(newNode == NULL){
        return NULL;
    }

    newNode->question = question;

    for (int i = 0; i < 4; i++){
        newNode->options[i] = options[i];
    }
    
    newNode->correctAnswer = correctAnswer;
    newNode->next = NULL;

    return newNode;
}

void addNewQuestion(QuestionList *qList, QuestionNode *question){
    if (!qList || !question){
        return;
    }

    if (emptyQuestionList(*qList)){
        *qList = question;
        question->next = NULL;
        return;
    }

    QuestionNode *currentNode = *qList;
    while (currentNode->next != NULL){
        currentNode = currentNode->next;
    }
    
    currentNode->next = question;
    question->next = NULL;
}

int removeQuestion(QuestionList *qList, QuestionNode *questionToRemove){
    
    //Verifica se a lista está vazia (aponta para NULL)
    if(emptyQuestionList(*qList)){
        return 0;  // Lista vazia, não há o que remover
    }
    
    // 3. Verifica se o nó a ser removido é NULL
    if(questionToRemove == NULL) {
        return 0; // Nó inválido, não faz nada
    }
    
    QuestionList q = *qList;

    //caso o nó a ser  removido for o primeiro
    if(q == questionToRemove) { 
        *qList = q->next;
        free(q);
        return 1;
    }

    //busca o nó no  resto dalista
    while(q->next  != NULL && q->next != questionToRemove){
        q = q->next;
    }

    //caso se encontrar  o nó
    if(q->next == questionToRemove) {
        QuestionNode *qToRemove  = q->next;
        q->next = qToRemove->next;
        free(qToRemove);
        return 1;
    }else{
        return 0;
    }
}

void showAllTheQuestions(QuestionList* qList){

}

void showScore(QuestionList* qList){

}

char* searchPlayer(Player* playerTree){

}