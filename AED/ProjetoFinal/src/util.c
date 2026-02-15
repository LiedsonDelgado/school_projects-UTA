#include"util.h"

/**
 * @brief Lê e faz validação de inteiros não-negativos da entrada do usuario
 * @param prompt uma string constante com a mensagem do usuario
 * @return valor inteiro digitado e validado do usuario
 */
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
            printf("ERRO: Entrada invalida, por favor digite um numero inteiro nao negativo\n");
        }
    } while (inputResults != 1 || valueInput < 0);

    return valueInput;
}

/**
 * @brief Lê e faz a validação de strings da entrada de usuario
 * @param prompt uma string constante com a mensagem do usuario
 * @param destination local onde a string será armazenada
 * @param maxLenght tamanho maximo que a string pode ter
 * @return - `0` erro na leitura (EOF, erro do sistema, etc)
 * @return - `1` string válida lida com sucesso
 */
int validateString(const char *prompt, char *destination, int maxLenght){
    // Buffer muito pequeno (precisa de espaço para pelo menos 1 char + '\0')
    if(maxLenght < 2) return 0;

    while(1){
        printf("%s", prompt);

        //leitura da string usando fgets
        // fgets retorna NULL em caso de erro ou EOF
        if(fgets(destination, maxLenght, stdin) == NULL){
            // Se não foi EOF (fim de arquivo), pode ser erro de leitura
            // Limpa o buffer de entrada para evitar problemas em leituras futuras
            if(!feof(stdin)){
                int c;
                while((c = getchar()) != '\n' && c != EOF);
            }
            return 0; //retorna erro
        }

        //calcula o comprinento da  string
        int len = (int)strlen(destination);  

        //remove o caractere de nova linha ('\n) se existir
        if (len > 0 && destination[len - 1] == '\n') {
            destination[len - 1] = '\0'; //substitui  '\n'  por '\0'
            len--;  //atualiza o  comprimento sem o '\0'
        } 
        // Se não tinha '\n' e o buffer está cheio, significa que
        // a entrada do usuário era maior que o buffer
        //limpa  os  caracteres extras que ficaram no  buffer  de  entrada
        else if (len == maxLenght - 1) {  
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
        }

        //variaveis de validação
        int onlySpaces = 1; //assume que é so espaço ate prover o contrario
        int isEmpty = (len == 0); //verifica se a string esta vazia

        // Percorre a string verificando se tem algum caractere não-espaço
        // O loop para antecipadamente se encontrar um caractere não-espaço
        for(int i = 0; i < len && onlySpaces; i++){
            // isspace() verifica: espaço, tab, newline, etc.
            // Cast para unsigned char evita problemas com chars negativos
            if (!isspace((unsigned char)destination[i])) {
                onlySpaces = 0; // Encontrou caractere não-espaço
            }
        }

        // Validação final: string não pode ser vazia nem conter apenas espaços
        if(isEmpty || onlySpaces) {
            printf("ERRO: entrada vazia ou invalida. Tente novamente.\n");
        } else {
            return 1;
        }
    }
}

char generateCorrectOption(){
    //ASCII Code: A-65, B-66, C-67, D-68

    srand(time(NULL)); //gera um novo numero

    int num = rand()%(68-65+1)+65;
    char opt = (char)num;

    return opt;
}