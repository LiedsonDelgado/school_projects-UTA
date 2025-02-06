#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <pthread.h>

pthread_mutex_t mutex; // declaracao do mutex que controla o acesso de cada thread a uma parte/bloco do codigo a executar

// Estrutura de Dados
struct INFO_FILMES
{
	char nome[150];
	int bilhetes_disponiveis;
	int ano_lancamento;
};

typedef struct INFO_FILMES FILME;

// Funcao que realiza a compra dos bilhetes de cada filme
void *comprar_filme(void *args){
	FILME *filmes = (FILME *)args; // Passa o argumento para um ponteiro para o vetor de filmes
	char escolha_filme[150];
	
	int quant_bilhetes;
	int quant_vendida_de_bilhetes=0;
	int max_bilhete_filme=6; // variavel que delimita o maximo de bilhetes disponibilizado de cada filme durante a compra

	int avancar_compra = 1; // avancar_compra e inicializado a 1 <=> SIM

	int i;
	int c=1;//variavel que exibe o cliente(thread) que esta a comprar algum bilhete no momento

printf("CINEMOVIES\n[FILMES EM EXIBICAO]\n");
	// Mostra os Filmes e os Bilhetes disponiveis;
	for (i = 0; i < 3; i++){
		printf(">Filme:%s\n Bilhetes Disponiveis:%d\n\n", filmes[i].nome, filmes[i].bilhetes_disponiveis);
	}

	do{
			printf("Qual filme deseja comprar bilhetes: ");
			scanf(" %[^\n]", escolha_filme);
for (i = 0; i < 3; i++){
			if (strcmp(escolha_filme, filmes[i].nome) == 0){
				printf("Ok\n");
				printf("Quantos bilhetes: ");
				scanf("%d", &quant_bilhetes);

pthread_mutex_lock(&mutex); // Bloqueia a seccao critica que permite cada thread executar a compra dos bilhetes de forma individual*
						   // *sem haver conflito em acessar o mesmo bloco de codigo

if(quant_bilhetes <= max_bilhete_filme){
				if ((quant_bilhetes > 0 && quant_bilhetes <= filmes[i].bilhetes_disponiveis)){
					//------------------------------------------------------------
						printf("Voce comprou %d bilhetes para o filme %s\n", quant_bilhetes, filmes[i].nome);
						filmes[i].bilhetes_disponiveis -= quant_bilhetes;
							quant_vendida_de_bilhetes+=quant_bilhetes;
				}
				else{
					printf("Os bilhetes estao esgotados ou nao tem mais do que deseja comprar\n");
				}
				 }else{
					printf("Maximo de bilhetes que voce pode comprar por filme e %d\n",max_bilhete_filme);
				 }
			}else{
				printf("Esse filme nao esta disponivel\n");
			}
}
pthread_mutex_unlock(&mutex); // Desbloqueia a seccao criticaque permite cada thread executar a compra dos bilhetes de forma individual*
							 // *sem haver conflito em acessar o mesmo bloco de codigo

			printf("\n\nDeseja comprar bilhetes para os filmes?\n");
			printf("[1]Sim [0]Nao :");
			scanf("%d", &avancar_compra);
		}
			while (avancar_compra!=0);// Executa as instrucoes se avancar_compra = 1(1-SIM),caso for diferente ou seja 0(0-NAO) nao executa nada e termina

		printf("Foram vendidos %d bilhete(s) ao Cliente N:%d\n",quant_vendida_de_bilhetes,c);
			c++;
		pthread_exit(NULL);
	}

	int main(){
		FILME filmes[3] = {{"O Hobbit:A Batalha dos 5 Exercitos",50,2014}, {"Star Wars 3",50,2005}, {"Interstellar",50,2014}};

		pthread_t thread[5]; // criacao de 5 thread <=> 5 clientes
		int j;

		pthread_mutex_init(&mutex, NULL); // inicializacao estatica da thread

		for (j = 1; j < 6; j++){
			printf("------------------------------------------------------------\n");
			printf("[Cliente Numero:%d]\n\n",j);
			pthread_create(&thread[j], NULL, comprar_filme, (void *)filmes); // cria cada uma das threads
			pthread_join(thread[j], NULL); // espera ate a thread em execucao termine para que a proxima avance
		}

		pthread_mutex_destroy(&mutex); // "finaliza" a thread que terminou a sua execucao

		return 0;
	}