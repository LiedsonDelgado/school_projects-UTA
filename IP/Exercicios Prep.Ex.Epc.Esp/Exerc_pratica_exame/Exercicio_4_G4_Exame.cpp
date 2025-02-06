#include<stdio.h>
#include<string.h>
#include<locale.h>

#define TAM 50
struct aluno{
char nome[100];
char curso[100];
int numero; //Numero ou Codigo do Aluno
int cadeiras_feitas; //Numero de cadeiras feitas pelo aluno
int ano; //Ano de entrada
};
typedef struct aluno Aluno;
//------------------------------------------------------------
void LerDados(Aluno alunos[TAM]){//Nesse caso "alunos"é um vetor
int i;
for(i=0;i<TAM;i++){
printf("Nome: ");
	scanf("%s",alunos[i].nome);
printf("Curso: ");
    scanf("%s",alunos[i].curso);
printf("Numero do Aluno: ");
    scanf("%d",&alunos[i].numero);
printf("Numero de cadeiras feitas: ");
    scanf("%d",&alunos[i].cadeiras_feitas);
printf("Ano de Entrada: ");
    scanf("%d",&alunos[i].ano);    
}	
}
//------------------------------------------------------------
int contaAlunos(int ano,Aluno alunos[]){
	int cont=0;
	int i;
for(i=0;i<TAM;i++){
	if(alunos[i].ano==ano){
		if(alunos[i].cadeiras_feitas<=10){
		cont++;
		}
	}
}
return cont;
}
//------------------------------------------------------------
int main()
{
setlocale(LC_ALL,"PORTUGUESE");
    Aluno alunos[TAM];
    int ano;
    int total;
LerDados(alunos);
 printf("\nDigite o ano para consultar: ");
     scanf("%d", &ano);
total=contaAlunos(ano, alunos);    
    printf("\nTotal de alunos do ano %d que fizeram 10 ou menos cadeiras: %d\n", ano, total);
}
