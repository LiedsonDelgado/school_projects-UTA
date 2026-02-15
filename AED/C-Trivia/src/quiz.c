#include"quiz.h"
#include"util.h"

//========================= SYSTEM FUNCTIONS ========================================

void menu(QuestionList *qList, PlayerTree **pTree){
    int option;
    do
    {
        printf("\n----- QUIZ GAME -----\n");
        printf("1 - Jogar\n");
        printf("2 - Adicionar nova pergunta\n");
        printf("3 - Eliminar pergunta\n");
        printf("4 - Mostrar  todas as perguntas\n");
        printf("5 - Mostrar classificacao\n");
        printf("6 - Procurar Jogador\n");
        printf("0 - Sair\n");
        option = validateInt("Digite a tua opcao: ");

        switch (option){
            case 0://completo
                printf("Saindo...\n");
                break;

            case 1://completo
                playGame(*qList,pTree);
                break;

            case 2:{
                char question[256];
                char qOptions[4][70];
                char *optPtrs[4];      
                char answer;

                if(!validateString("Digite a pergunta: ", question, 256)){
                    printf("ERRO: falha ao ler a string.\n");
                    break;
                }

                for (int i = 0; i < 4; i++){
                    if(!validateString("Digite uma opcao: ", qOptions[i], 70)){
                        printf("ERRO: falha ao ler a opcao %c.\n", 'A'+i);
                        break;
                    }
                    optPtrs[i] = qOptions[i];
                }

                answer = validateChar("Digite a resposta correta (A-D): ");

                QuestionNode *q = createQuestion(question, optPtrs, answer);
                if(q == NULL){
                    printf("ERRO: falha ao criar pergunta.\n");
                    break;
                }

                addNewQuestion(qList,q);
                printf("SUCESSO: Pergunta adicionada.\n");

                break;
            }

            case 3:{//completo
                if(emptyQuestionList(*qList)){
                    printf("ERRO: lista de perguntas vazia!\n");
                    break;
                }
                showAllQuestions(*qList);
                int position = validateInt("Digite o numero da questão a eliminar: ");

                if(removeQuestionByPosition(qList,position)){
                    printf("SUCESSO: Pergunta eliminada\n");
                } else {
                    printf("ERRO: Pergunta não encontrada/ou falha ao tentar eliminar a pergunta\n");
                }
                break;
            }

            case 4://completo
                showAllQuestions(*qList);
                break;

            case 5://completo
                displayScoreboard(*pTree);
                break;

            case 6:
                printf("ERRO: esta opcao ainda não foi implementada\n");
                break;
        
            default://completo
                printf("ERRO: opcao invalida!\n");
                break;
        }
    } while (option != 0);
    
}

void playGame(QuestionList qList, PlayerTree **pTree){
    if(emptyQuestionList(qList)){
        printf("ERRO: lista de perguntas vazia");
        return;
    }
    char playerName[100];
    int score = 0, totalQuestions = 0, questionNunber = 1;
    char playerAnswer;
    QuestionList currentQ = qList;

    if(!validateString("\nDigite o seu nome: ", playerName, 100)){
        printf("ERRO: falha ao registar nome.\n");        
        return;
    }

    printf("SUCESSO: nome registado.\n\n");

    while (currentQ != NULL){
        totalQuestions++;
        currentQ = currentQ->next;
    }

    printf("\n--Bem-Vindo %s! Voce tera %d questoes para responder.\n\n",playerName,totalQuestions);
    currentQ = qList;

    while (currentQ != NULL){
        printf("\n---Questao %d de %d ---\n",questionNunber,totalQuestions);
        printf("%s\n",currentQ->question);

        for (int i = 0; i < 4; i++){
            printf("[%c] - %s\n",'A'+i,currentQ->options[i]);
        }
        
        playerAnswer = validateChar("Digite a sua resposta (A-D): ");

        if(playerAnswer == currentQ->correctAnswer){
            printf("CORRETO\n");
            score++;
        }else{
            printf("ERRADO! A resposta correta era: %c\n", currentQ->correctAnswer);
        }
        
        currentQ = currentQ->next;
        questionNunber++;

    }

    printf("\n------- RESULTADO FINAL -------\n");
    printf("Jogador: %s\n",playerName);
    printf("Score: %d de %d (%d%%)\n",score,totalQuestions, (score*100)/totalQuestions);
    printf("-------------------------------\n\n");
    
    addPlayerIntoTree(pTree,playerName,score);
    printf("Guardando dados do jogador.....\n");

}

//========================= PLAYER FUNCTIONS ========================================

PlayerTree* createPlayerTreeNode(){
    PlayerTree* node = (PlayerTree*)malloc(sizeof(PlayerTree));
    if(node == NULL){
        printf("Erro ao alocar memoria!\n");
        exit(EXIT_FAILURE);
    }

    node->playerName = malloc(100 * sizeof(char));
    if(node->playerName == NULL){
        printf("Erro ao alocar memoria para nome!\n");
        free(node);
        exit(EXIT_FAILURE);
    }

    node->playerName[0] = '\0';
    node->score = 0;
    node->left = NULL;
    node->right = NULL;

    return node;
}

void addPlayerIntoTree(PlayerTree** tree,char playerName[],int score){
    PlayerTree* node = createPlayerTreeNode();
    strcpy(node->playerName,playerName);
    node->score = score;

    if(*tree == NULL){
        *tree = node;
        return;
    }

    PlayerTree* current = *tree;
    PlayerTree* father = NULL;

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

void displayScoreboard(PlayerTree* tree){
    if(tree == NULL){
        printf("ERRO: lista de jogadores vazia.\n");
        return;
    }

    printf("\n========== CLASSIFICACAO ==========\n");
    printf("%-30s | %s\n", "Nome", "Pontuacao");
    printf("----------------------------------\n");
    displayScoreboardInOrder(tree);
    printf("===================================\n\n");
}

void displayScoreboardInOrder(PlayerTree* tree){
    if(tree == NULL) return;

    // InOrder: esquerda, nó, direita (ordem alfabética)
    displayScoreboardInOrder(tree->left);
    printf("%-30s | %d\n", tree->playerName, tree->score);
    displayScoreboardInOrder(tree->right);
}

void searchPlayer(PlayerTree* tree,char* playerName){
    if(tree == NULL){
        return;
    }

    if(strcmp(tree->playerName,playerName) == 0){
        printf("Nome: %s\n",tree->playerName);
        printf("Pontuacao: %d\n",tree->score);
    }
    searchPlayer(tree->left,playerName);
    searchPlayer(tree->right,playerName);
}

void freePlayerTree(PlayerTree** tree){
    if(*tree == NULL) return;

    freePlayerTree(&(*tree)->left);
    freePlayerTree(&(*tree)->right);

    free((*tree)->playerName);
    free(*tree);
    *tree = NULL;
}


int removePlayerFromTree(PlayerTree** tree, char* playerName){
    if(*tree == NULL) return 0;

    int cmp = strcmp(playerName, (*tree)->playerName);

    if(cmp < 0){
        return removePlayerFromTree(&(*tree)->left, playerName);
    } else if(cmp > 0){
        return removePlayerFromTree(&(*tree)->right, playerName);
    } else {
        // Encontrou o nó
        PlayerTree* temp = *tree;

        // Caso 1: Folha (sem filhos)
        if(temp->left == NULL && temp->right == NULL){
            free(temp->playerName);
            free(temp);
            *tree = NULL;
            return 1;
        }

        // Caso 2: Tem apenas filho direito
        if(temp->left == NULL){
            *tree = temp->right;
            free(temp->playerName);
            free(temp);
            return 1;
        }

        // Caso 2: Tem apenas filho esquerdo
        if(temp->right == NULL){
            *tree = temp->left;
            free(temp->playerName);
            free(temp);
            return 1;
        }

        // Caso 3: Tem dois filhos
        // Encontra o menor nó da subárvore direita (sucessor inorder)
        PlayerTree* minRight = temp->right;
        while(minRight->left != NULL){
            minRight = minRight->left;
        }

        strcpy(temp->playerName, minRight->playerName);
        temp->score = minRight->score;

        return removePlayerFromTree(&temp->right, minRight->playerName);
    }
}

//========================= QUESTION FUNCTIONS ========================================

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

    newNode->question = malloc(strlen(question)+1);
    if(newNode->question == NULL){
        free(newNode);
        return NULL;
    }
    strcpy(newNode->question, question);

    for(int i = 0; i < 4; i++){
        newNode->options[i] = malloc(strlen(options[i]) + 1);
        if(newNode->options[i] == NULL){
            for(int j = 0; j < i; j++){
                free(newNode->options[j]);
            }
            free(newNode->question);
            free(newNode);
            return NULL;
        }
        strcpy(newNode->options[i], options[i]);
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

// int removeQuestion(QuestionList *qList, QuestionNode *questionToRemove){
    
//     //Verifica se a lista está vazia (aponta para NULL)
//     if(emptyQuestionList(*qList)){
//         return 0;  // Lista vazia, não há o que remover
//     }
    
//     // 3. Verifica se o nó a ser removido é NULL
//     if(questionToRemove == NULL) {
//         return 0; // Nó inválido, não faz nada
//     }
    
//     QuestionList *q = *qList;

//     //caso o nó a ser  removido for o primeiro
//     if(q == questionToRemove) { 
//         *qList = q->next;
//         free(q);
//         return 1;
//     }

//     //busca o nó no  resto dalista
//     while(q->next  != NULL && q->next != questionToRemove){
//         q = q->next;
//     }

//     //caso se encontrar  o nó
//     if(q->next == questionToRemove) {
//         QuestionNode *qToRemove  = q->next;
//         q->next = qToRemove->next;
//         free(qToRemove);
//         return 1;
//     }else{
//         return 0;
//     }
// }

void showAllQuestions(QuestionList list){
    if(emptyQuestionList(list)){
        printf("ERRO: lista esta vazia.\n");
        return;
    }

    int i = 1;
    QuestionList currentNode = list;
    printf("\n====== LISTA DE QUESTOES ======\n");
    while (currentNode != NULL){
        printf("- Questao %d: %s\n",i,currentNode->question);
        for(int j = 0; j < 4;  j++){
            printf("  %c) %s\n", 'A'+j,  currentNode->options[j]);
        }
        printf("Resposta correta: %c\n", currentNode->correctAnswer);
        currentNode = currentNode->next;
        i++;
    }
    printf("\n====== FIM DA LISTA DE QUESTOES ======\n\n");
}

void freeQuestionList(QuestionList *list) {
    QuestionNode *current = *list;
    while (current != NULL) {
        QuestionNode *next = current->next;

        free(current->question);
        for (int i = 0; i < 4; i++) {
            free(current->options[i]);
        }
        free(current);

        current = next;
    }
    *list = NULL;
}

int removeQuestionByPosition(QuestionList *list, int questionPosition){
    if(emptyQuestionList(*list))  return 0;

    if(questionPosition < 1) return 0;

    QuestionList ql = *list;
    int n = 1;

    if(questionPosition == 1){
        *list = ql->next;
        for (int i = 0; i < 4; i++){
            free(ql->options[i]);
        }
        free(ql->question);
        free(ql);
        return 1;
    }

    while (ql != NULL && n <  questionPosition-1){
        ql =  ql->next;
        n++;
    }

    if(ql == NULL || ql->next == NULL) return 0;

    QuestionList  qR = ql->next;
    ql->next = qR->next;
    for(int i = 0; i < 4; i++){
        free(qR->options[i]);
    }
    free(qR->question);
    free(qR);
    return 1;    
}

//========================= FILE FUNCTIONS ========================================

void saveQuestionList(QuestionList qlist){
  FILE *file = fopen("data/ListOfQuestions.txt", "w");
  if(file ==  NULL){
    printf("ERRO: nao foi possivel abrir o ficheiro");
    return;
  }

  QuestionList l  = qlist;
  while (l  != NULL){
    fprintf(file, "%s\n", l->question);

    for(int i = 0; i<4; i++){
      fprintf(file, "%s\n", l->options[i]);
    }

    fprintf(file,  "%c\n", l->correctAnswer);
    l  = l->next;
  }
  fclose(file);
  printf("SUCESSO: lista de  perguntas guardada em data/\n");
}

void loadQuestionList(QuestionList *qlist){
  FILE  *file = fopen("data/ListOfQuestions.txt", "r");
  if(file ==  NULL){
    printf("ERRO: nao foi possivel abrir  o ficheiro");
    return;
  }

  createQuestionList(qlist);

  char qQuestion[256];
  char qOptions[4][100];
  char qAnswer;
  char buffer[10];

  while (fgets(qQuestion, sizeof(qQuestion), file)){
    qQuestion[strcspn(qQuestion, "\n")] = '\0';

    for(int i = 0; i < 4; i++){
      if(!fgets(qOptions[i], sizeof(qOptions[i]), file)) break;
      qOptions[i][strcspn(qOptions[i], "\n")] = '\0';
    }

    if(!fgets(buffer,  sizeof(buffer), file)) break;
    qAnswer = toupper(buffer[0]);

    char *questionCpy = malloc(strlen(qQuestion) + 1);
    strcpy(questionCpy,qQuestion);

    char *opt[4];
    for (int i = 0; i < 4; i++){
      opt[i] = qOptions[i];
    }

    QuestionNode *q = createQuestion(questionCpy,  opt, qAnswer);
    addNewQuestion(qlist, q);
  }
  fclose(file);
  printf("SUCESSO: lista de perguntas carregada de data/\n");
}