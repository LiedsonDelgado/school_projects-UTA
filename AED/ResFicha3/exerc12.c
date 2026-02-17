//exercicio 12 mas com alguns extras
#include<stdio.h>
#include<stdlib.h>

//Funcoes auxiliares
void menu(){
    printf("\n------------------\n");
    printf("1-Bubble Sort\n");
    printf("2-Selection Sort\n");
    printf("3-Insertion Sort\n");
    printf("4-Merge Sort\n");
    printf("5-Quick Sort\n");
    printf("6-Pesquisa Linear/Sequencial (Nao Ordenada)\n");
    printf("7-Pesquisa Linear/Sequencial (Ordenada)\n");
    printf("8-Pesquisa Binaria\n");
    printf("0-Sair\n");
    printf("------------------\n");
}

void sub_menu(){
    printf("\n------------------\n");
    printf("1-Ordem crescente\n");
    printf("2-Ordem decrescente\n");
    printf("------------------\n");
}

int exibir_vetor(int *v,int n){
    for(int i=0;i<n;i++){
        printf("%d ",v[i]);
    }
}

int ordem_crescente(int a,int b){
    return a>b;
}

int ordem_decrescente(int a,int b){
    return a<b;
}

int swap_elem(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

//Algoritmos de ordenacao
void bubble_sort(int *v,int n,int (*cmp)(int,int)){
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(cmp(v[j],v[j+1])){
                swap_elem(&v[j],&v[j+1]);
            }
        }
    }
}

void selection_sort(int *v,int n,int (*cmp)(int,int)){
    int index_min;
    for(int i=0;i<n-1;i++){
        index_min = i;
        for(int j=i+1;j<n;j++){
            if(cmp(v[index_min],v[j])){
                index_min = j;
            }
        }
        if(i != index_min){
            swap_elem(&v[i],&v[index_min]);
        }
    }
}

void insertion_sort(int *v,int n,int (*cmp)(int,int)){
    for(int i=1;i<n;i++){
        for(int j=i;j>=1 && cmp(v[j-1],v[j]);j--){
            swap_elem(&v[j],&v[j-1]);
        }
    }
}

void merge(){
    //...
}

void merge_sort(){
    //...
}

/*
int partition(int *v,int indexStart,int indexEnd,int (*cmp)(int,int)){
    int pivot = v[indexEnd];
    int bound = indexStart;

    for(int index=indexStart;index<indexEnd;index++){
        if(cmp(v[index],pivot)){
            swap_elem(&v[bound++],&v[index]);
        }
    }
    swap_elem(&v[bound],&v[indexEnd]);
    return bound;
}

void quick_sort(int *v,int indexStart,int indexEnd,int (*cmp)(int,int)){
    if(indexStart <= indexEnd){
        return;
    }

    int indexPivot = partition(v,indexStart,indexEnd,cmp(v[indexStart],v[indexEnd]));
    quick_sort(v,indexStart,indexPivot-1,cmp(v[indexStart],v[indexPivot-1]));
    quick_sort(v,indexPivot+1,indexEnd,cmp(v[indexPivot+1],v[indexEnd]));
}
*/

//Algoritmos de pesquisa
int pesquisa_linear_nao_ordenada(int *v,int n,int procurado){
    for(int i=0;i<n;i++){
        if(v[i] == procurado){
            return i;
        }
    }
    return -1;
}

int pesquisa_linear_ordenada(int *v,int n,int procurado){
    for(int i=0;i<n;i++){
        if(v[i] == procurado){
            return i;
        }else{
            if(v[i]>procurado){
                continue;
            }else{
                break;
            }
        }
    }
    return -1;
}

int pesquisa_binaria(int *v,int n,int procurado){
    int inicio = 0;
    int fim = n-1;
    int meio;

    while(inicio<=fim){
        meio = (inicio+fim)/2;

        if(procurado == v[meio]){
            return meio;
        }else{
            if(procurado>v[meio]){
                inicio = meio+1;
            }else{
                fim = meio-1;
            }
        }
    }
    return -1;
}

int main(){
    int n;
    int opc;
    int proc;
    int res_proc;

    printf("Quantos elementos o vetor tera: ");
    scanf("%d",&n);
    if(n<=0){
        printf("O vetor devera ter pelo menos 1 elemento!\n");
        exit(EXIT_FAILURE);
    }

    int *v = (int*)malloc(sizeof(int)*n);
    if(v == NULL){
        printf("Erro ao alocar memoria!\n");
        exit(EXIT_FAILURE);
    }

    printf("Introduza os elementos do vetor\n");
    for(int i=0;i<n;i++){
        printf("%d elemento: ",i+1);
        scanf("%d",&v[i]);
    }

    printf("\nVetor inicial: ");
    exibir_vetor(v,n);

    do{
        menu();
        printf("Escolha uma opcao: ");
        scanf("%d",&opc);

        switch(opc){
            case 0:
                printf("Encerrando...");
                break;

            case 1: //Bubble Sort
                sub_menu();
                printf("Escolha uma opcao: ");
                scanf("%d",&opc);
                switch(opc){
                    case 1:
                        bubble_sort(v,n,ordem_crescente);
                        printf("Bubble Sort-Ordem Crescente: ");
                        exibir_vetor(v,n);
                        break;

                    case 2:
                        bubble_sort(v,n,ordem_decrescente);
                        printf("Bubble Sort-Ordem Decrescente: ");
                        exibir_vetor(v,n);
                        break;

                    default:
                        printf("Opcao invalida,tente novamente!\n");
                        break;
                }
                break;

            case 2: //Selection Sort
                sub_menu();
                printf("Escolha uma opcao: ");
                scanf("%d",&opc);
                switch(opc){
                    case 1:
                        selection_sort(v,n,ordem_crescente);
                        printf("Selection Sort-Ordem Crescente: ");
                        exibir_vetor(v,n);
                        break;

                    case 2:
                        selection_sort(v,n,ordem_decrescente);
                        printf("Selection Sort-Ordem Decrescente: ");
                        exibir_vetor(v,n);
                        break;

                    default:
                        printf("Opcao invalida,tente novamente!\n");
                        break;
                }
                break;

            case 3: //Insertion Sort
                sub_menu();
                printf("Escolha uma opcao: ");
                scanf("%d",&opc);
                switch(opc){
                    case 1:
                        insertion_sort(v,n,ordem_crescente);
                        printf("Insertion Sort-Ordem Crescente: ");
                        exibir_vetor(v,n);
                        break;

                    case 2:
                        insertion_sort(v,n,ordem_decrescente);
                        printf("Insertion Sort-Ordem Decrescente: ");
                        exibir_vetor(v,n);
                        break;

                    default:
                        printf("Opcao invalida,tente novamente!\n");
                        break;
                }
                break;

            case 4: //Merge Sort
                sub_menu();
                printf("Escolha uma opcao: ");
                scanf("%d",&opc);
                switch(opc){
                    case 1:
                        break;

                    case 2:
                        break;

                    default:
                        printf("Opcao invalida,tente novamente!\n");
                        break;
                }
                break;

            case 5: //Quick Sort
                sub_menu();
                printf("Escolha uma opcao: ");
                scanf("%d",&opc);
                switch(opc){
                    case 1:
                        /*
                        quick_sort(v,0,n-1,ordem_crescente);
                        printf("Quick Sort-Ordem Crescente: ");
                        exibir_vetor(v,n);
                        */
                        break;

                    case 2:
                        /*
                        quick_sort(v,0,n-1,ordem_decrescente);
                        printf("Quick Sort-Ordem Decrescente: ");
                        exibir_vetor(v,n);
                        */
                        break;

                    default:
                        printf("Opcao invalida,tente novamente!\n");
                        break;
                }
                break;

            case 6: //Pesquisa Linear/Sequencial-Nao Ordenada
                printf("Qual elemento deseja procurar: ");
                scanf("%d",&proc);
                res_proc = pesquisa_linear_nao_ordenada(v,n,proc);

                if(res_proc == -1){
                    printf("O elemento nao foi encontrado!\n");
                }else{
                    printf("O elemento foi encontrado na posicao %d\n");
                }

                break;

            case 7: //Pesquisa Linear/Sequencial-Ordenada
                printf("Qual elemento deseja procurar: ");
                scanf("%d",&proc);
                res_proc = pesquisa_linear_ordenada(v,n,proc);

                if(res_proc == -1){
                    printf("O elemento nao foi encontrado!\n");
                }else{
                    printf("O elemento foi encontrado na posicao %d\n");
                }
                break;

            case 8: //Pesquisa Binaria
                printf("Qual elemento deseja procurar: ");
                scanf("%d",&proc);
                res_proc = pesquisa_binaria(v,n,proc);

                if(res_proc == -1){
                    printf("O elemento nao foi encontrado!\n");
                }else{
                    printf("O elemento foi encontrado na posicao %d\n");
                }
                break;

            default:
                printf("Opcao invalida,tente novamente!\n");
                break;
        }

    }while(opc != 0);


    return 0;
}