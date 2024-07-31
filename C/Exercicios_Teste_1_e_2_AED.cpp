#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

//EXERCICIOS_GRUPO_III_TESTE_1_AED
//______________________________1-

//Declaracoes_Estruturas
//__________________________Estrutura_Exercicio_1_Teste_1_GIII_AED
//________________________A)
typedef struct{
	char *nome;
	char pacote;
unsigned int n_cliente; //numero de cliente(sem sinal(nesse caso considerado positivo))
}Cliente;

//________________________Estrutura_Exercicio_8_Teste_2_GII_AED
//LSL
typedef struct NoListaInt{
    int dados;
    NoListaInt *proximo; //proximo no
}NoLista;

//________________________Estrutura_Exercicio_9_Teste_2_GII_AED
//STACK
typedef struct NoPilha{
	int Numero;
	NoPilha *seguinte;
}PilhaInt;

//________________________Estrutura_Exercicio_9_Teste_2_GII_AED
//BST
typedef struct tno{
    float x;
struct tno *left;
struct tno *right;
}tree;

//Implementacao_de_Funcoes
//________________________B)
Cliente* reserva_memoria(int N){
Cliente *array_N=(Cliente*)malloc(sizeof(Cliente)*N); //Alocacao para o array_N(vetor N clientes)
                                                    //vetor N cliente que ira retornar o endereco do seu 1st elemento                                         
int i,j;

if(array_N==NULL){//Verifica se houve sucesso na Alocacao
	 printf("Erro ao Alocar Memoria\n");
	 exit(EXIT_FAILURE);
}
for(int i=0;i<N;i++){
	 array_N[i].nome=(char*)malloc(sizeof(char)*30); //Alocacao para o nome cada cliente com max.30 caracteres

if(array_N[i].nome==NULL){ //Verifica se a Alocacao teve sucesso
printf("Erro ao Alocar Memoria\n");
for(j=0;j<i;j++){
     free(array_N);
	 exit(EXIT_FAILURE);
}
}	
}

     return array_N;
}

//________________________C)
int search_name(Cliente *array_N,int N,char *nome){

int i;

for(i=0;i<N;i++){
     if(strcmp(array_N[i].nome,nome)==0){
	    return 1;
	}
}
return 0;	
}

//________________________D)
void free_memoria(Cliente *array_N,int N){
int i;
for(i=0;i<N;i++){
	free(array_N[i].nome);//Liberta a Espaço/Memoria de cada cliente	
}
free(array_N);//Liberta a Memoria do vetor de clientes	
}

//______________________________2-
int maior_elemento_N(int *V,int N){
	if(N=1){
	return V[0];
	}
	
	maior_elemento_N(V+1,N-1);//Chama a funcao de forma recursiva do subvetor e compara com o elemento atual
	return(V[0]>maior_elemento_N(V+1,N-1)?V[0]:maior_elemento_N(V+1,N-1));
}

//EXERCICIOS_GRUPO_II_TESTE_2_AED
//______________________________8-
NoLista* posicoes_lista(NoLista *L,int valor){
	NoLista *posicoes=NULL;//Lista das posicoes inicialmente esta vazia
	NoLista *ultimo=NULL;//Ultimo no da Lista de posicoes

int pos=1;//1st elemento da lista que se encontra na "POSICAO 1"

for(pos=1;L!=NULL;pos++){
	if(L->dados==valor){
      NoLista *new_No=(NoLista*)malloc(sizeof(NoLista));
         new_No->dados=pos;
         new_No->proximo=NULL;
	    
		if(posicoes==NULL){
	    	posicoes=new_No;
		}
		 else{
			ultimo->proximo=new_No;
		}
		ultimo=new_No;
}
L=L->proximo;
}
return posicoes;
}

//______________________________9-
PilhaInt* inicializar(){ //Inicializacao da Pilha como Vazia
	return NULL;
}

void stack_Push(PilhaInt **top,int valor){ //Funcao Push para inserir no elemento na Pilha
	PilhaInt* novoNo=(PilhaInt*)malloc(sizeof(PilhaInt));
	
	if(novoNo==NULL){
	   printf("Erro ao Alocar Memoria");
	   exit(EXIT_FAILURE);
}
novoNo->Numero=valor;
novoNo->seguinte= *top;
*top=novoNo;
}

//______________________________10-
float max_Element(tree *T){
	if(T==NULL){
		printf("Arvore Vazia");
		exit(EXIT_FAILURE);
	}
	while(T->right!=NULL){//O elemento max sempre estara no Nó mais a direita da Arvore
		T=T->right;
	}
	T->x;
}

main(){
	//TESTE
	printf("\n[ 0 ERROS DE EXECUCAO DAS FUNCOES!!! ]\n");
	//...
}

