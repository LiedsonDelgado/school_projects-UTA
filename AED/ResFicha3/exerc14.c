//TPC1_LIEDSON DELGADO-LEIT

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void menu(){
    printf("\n----------------------------------------\n");
    printf("1-Inserir pais\n");
    printf("2-Ordenar paises(ordem alfabetica)\n");
    printf("3-Procurar por pais\n");
    printf("4-Exibir todos os paises\n");
    printf("5-Eliminar todos os paises\n");
    printf("0-Sair...\n");
    printf("----------------------------------------\n\n");
}

void sub_menu(){
    printf("\n----------------------------------------\n");
    printf("1-Por ordem crescente\n");
    printf("2-Por ordem decrescente\n");
    printf("----------------------------------------\n\n");
}

void string_swap(char **string1,char **string2){
    char *temp = *string1;
    *string1 = *string2;
    *string2 = temp;
}

void sorting_algorithm(char** v_countries,int n,int sorting_opt){
    if(n == 0){
        printf("A lista esta vazia\n");
        return;
    }

    if(sorting_opt == 1){ //ordem crescente
        for(int i=0;i<n-1;i++){
            for(int j=0;j<n-i-1;j++){
                if(strcmp(v_countries[j],v_countries[j+1])>0){
                    string_swap(&v_countries[j],&v_countries[j+1]);
                }
            }
        }
        printf("A lista foi ordenada\n");
    }

    else if(sorting_opt == 2){ //ordem decrescente
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(strcmp(v_countries[j],v_countries[j+1])<0){
                string_swap(&v_countries[j],&v_countries[j+1]);
            }
        }
    }
    printf("A lista foi ordenada\n");
    }else{
        printf("Opcao invalida,tente novamente!\n");
        exit(1);
    }
}

void searching_algoritm(char** v_countries,char* country_name,int n){
    int count = 0;

    if(n == 0){
        printf("A lista esta vazia\n");
        return;
    }

    for(int i=0;i<n;i++){
        if(strcmp(country_name,v_countries[i]) == 0){
            count++;
        }
    }

    if(count>0){
            printf("Pais %s foi encontrado na lista %d vez(es)\n",country_name,count);
    }else{
            printf("Pais nao encontrado na lista!\n");
    }
}

void show_all_countries(char** v_countries,int n){
    if(n == 0){
        printf("A lista esta vazia\n");
        return;
    }

    for(int i=0;i<n;i++){
        printf("-%s\n",v_countries[i]);
    }
}

int main(){
    int opt;
    int sorting_opt;
    int i = 0; //contador para o total de paises;

    char *country_name = (char*)malloc(sizeof(char)*100);
    if(country_name == NULL){
        printf("Erro ao alocar memoria\n");
        exit(EXIT_FAILURE);
    }

    char **countries_list = NULL;

    do{
        menu();
        printf(">Escolha uma opcao: ");
        scanf("%d",&opt);

        switch(opt){
            case 0:
                printf("Encerrando...\n");
                break;

            case 1:
                printf(">Introduza o nome do pais: ");
                scanf("%s",country_name);

                countries_list = (char**)realloc(countries_list,(i+1)*sizeof(char*));
                if(countries_list == NULL){
                    printf("Erro ao alocar memoria\n");
                    exit(EXIT_FAILURE);
                }

                countries_list[i] = (char*)malloc(strlen(country_name)+1);
                if(countries_list[i] == NULL){
                    printf("Erro ao alocar memoria\n");
                    exit(EXIT_FAILURE);
                }

                strcpy(countries_list[i],country_name);
                i++;

                printf("O pais foi adicioanado na lista\n");

                break;

            case 2:
                sub_menu();
                printf(">Escolha a forma de ordenacao: ");
                scanf("%d",&sorting_opt);

                sorting_algorithm(countries_list,i,sorting_opt);
                break;

            case 3:
                printf("Nome do pais a procurar: ");
                scanf("%s",country_name);
                searching_algoritm(countries_list,country_name,i);
                break;

            case 4:
                show_all_countries(countries_list,i);
                break;

            case 5:
                free(countries_list);
                printf("Todos os paises foram eliminados da lista\n");
                i = 0;
                break;

            default:
                printf("\nOpcao invalida,tente novamente!\n");
                break;

        }
    }while(opt != 0);

    return 0;
}
