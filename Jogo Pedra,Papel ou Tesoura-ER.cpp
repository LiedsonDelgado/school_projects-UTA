#include<stdlib.h>  //>Nao e necessario no codigo
#include <string.h> //>Nao e necessario no codigo
#include<math.h>    //>Nao e necessario no codigo
//------------------
#include <locale.h>
#include<stdio.h>
//-------------------------------------------------------------------------------------------------------
void jogo(){
int escolha_j1,escolha_j2;	

printf("\n--Escolha uma Opção--\n");
printf("---1.Pedra--- \n---2.Papel--- \n---3.Tesoura---\n");
printf("(Digite o numero de cada Opção)\n");

printf("\nJogador 1: ");
scanf("%d",&escolha_j1);

printf("Jogador 2: ");
scanf("%d",&escolha_j2);

//-------------------------------------
//Escolha Opcao Jogador 1
switch(escolha_j1){
case 1:
printf("--Jogador 1 escolheu PEDRA\n");
   break;

case 2:
printf("--Jogador 1 escolheu PAPEL\n");
   break;
   
case 3:
printf("--Jogador 1 escolheu TESOURA\n");
   break;
   
default:
	printf("<Escolha Inválida>\n");
}

//-------------------------------------
//Escolha Opcao Jogador 2
switch(escolha_j2){
case 1:
printf("--Jogador 2 escolheu PEDRA\n");
   break;
   
case 2:
printf("--Jogador 2 escolheu PAPEL\n");
   break;
   
case 3:
printf("--Jogador 2 escolheu TESOURA\n");
   break;

default:
    printf("<Escolha Inválida>\n");

}
//-------------------------------------------------------------------------------------------------------
//Comparar as Escolhas(Jogador 1 e Jogador 2)
if(escolha_j1==escolha_j2){
printf("\n>>>>Empate");
}
  else if((escolha_j1==1 && escolha_j2==3)||
          (escolha_j1==2 && escolha_j2==1)||
          (escolha_j1==3 && escolha_j2==2)){
     printf("\n>>>>Jogador 1 Venceu,Jogador 2 Perdeu!!!\n");
}
else{
  printf("\n>>>>Jogador 2 Venceu,Jogador 1 Perdeu!!!\n");}
}
//-------------------------------------------------------------------------------------------------------
int main()
{
setlocale (LC_ALL,"portuguese");//caracteres do Portugues(ex.:acentos,etc)
char play_again;

do{
jogo();

getchar();
printf("\nVc deseja jogar novamente??\n");
printf("(S,s-SIM)  (N,n-NAO):");
scanf("%c",&play_again);

}
while(play_again=='S'|| play_again=='s');

return 0;
}
