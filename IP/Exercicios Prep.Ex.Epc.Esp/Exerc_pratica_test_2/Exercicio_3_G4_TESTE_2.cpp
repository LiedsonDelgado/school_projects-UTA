#include<stdio.h>
#include<stdlib.h>
#include <locale.h>

typedef struct aluno{
	char nome[100];
	float nota;
}Aluno;
//-------------------------------
float maior_nota(Aluno alunos[]){
	float maior=alunos[0].nota;
int i;
for(i=0;i<3;i++){
if(alunos[i].nota>maior){
maior=alunos[i].nota;
  }
 }
 return maior;
}

float media_nota(Aluno alunos[]){
	int i;
	float media;
	float soma=0.0;
for(i=0;i<3;i++){
	soma+=alunos[i].nota;
 }
return media=soma/3;
}
//---------------------------------
int main(){
setlocale (LC_ALL,"portuguese");//caracteres do Portugues(ex.:acentos,etc)
   int i;
   float maior,media;
   Aluno alunos[3];
printf("--DADOS DO ALUNO--\n");
//---------------------------------
for(i=0;i<3;i++){
	printf("Nome:");
	   scanf("%s",alunos[i].nome);
	printf("Nota:");
	    scanf("%f",&alunos[i].nota);
	printf("\n");
}
maior=maior_nota(alunos);
     printf("-MAIOR NOTA:%.1f\n",maior);
media=media_nota(alunos);
     printf("-A MEDIA FINAL:%.1f\n",media); 
return 0;
}
