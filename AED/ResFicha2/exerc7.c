#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    char *v_char = (char*)malloc(sizeof(char)*100);
    if(v_char == NULL){
        printf("Erro ao alocar memoria\n");
        exit(EXIT_FAILURE);
    }
    printf(">Introduza uma palavra(ate 100 caracteres): ");
    scanf("%s",v_char);
    printf("\n>>String original: %s\n",v_char);

    char *v_char_copy = (char*)malloc(sizeof(char)*strlen(v_char)+1);
    strcpy(v_char_copy,v_char);
    printf(">>Copia da string: %s\n\n",v_char_copy);

    free(v_char);
    free(v_char_copy);
    printf("Memoria libertada...\n");

    return 0;
}
