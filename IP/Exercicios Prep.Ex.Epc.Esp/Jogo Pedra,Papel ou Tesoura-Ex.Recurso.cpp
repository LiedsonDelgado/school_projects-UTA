#include<stdio.h>
#include<locale.h>
//------------------------------------------------------------------------------
void Jogo(){ //Função para executar o Jogo de Pedra,Papel ou Tesoura
int Escolha_J1,Escolha_J2;//Variaveis para armazenar as escolhas de cada jogador

printf("--------------------------------------------------------------------------\n");
printf("Escolha uma Opção\n");
  printf("1.PEDRA \n2.PAPEL \n3.TESOURA\n\n");
   
//Leitura de Opções Jogador 1 e Jogador 2
printf("Jogador 1: ");
     scanf("%d",&Escolha_J1);
printf("Jogador 2: ");
     scanf("%d",&Escolha_J2);   
//Escolha Jogador 1-------------
switch(Escolha_J1){
	case 1:
		printf("--Jogador 1 escolheu (Pedra)\n");
		break;
    case 2:
    	printf("--Jogador 1 escolheu (Papel)\n");
		break;
	case 3:
		printf("--Jogador 1 escolheu (Tesoura)\n");
		break;
    default:
   	    printf(">>Escolha Inválida,queira tentar novamente!\n");
}
//Escolha Jogador 2-------------
switch(Escolha_J2){
	case 1:
		printf("--Jogador 2 escolheu (Pedra)\n");
		break;
    case 2:
    	printf("--Jogador 2 escolheu (Papel)\n");
		break;
	case 3:
		printf("--Jogador 2 escolheu (Tesoura)\n");
		break;
    default:
   	    printf(">>Escolha Inválida,queira tentar novamente!\n");
}
//Comparação para determinar Vitória entre Jogador 1 e Jogador 2
if(Escolha_J1==Escolha_J2){
	 printf("Empate!!!");
}
//---
else if((Escolha_J1==2 && Escolha_J2==1)||
         (Escolha_J1==1 && Escolha_J2==3)||
		 (Escolha_J1==3 && Escolha_J2==2)){
printf("\nJogador 1 Venceu!!!\n");
}
//---
else{
     printf("\nJogador 2 Venceu!!!\n");
	}
}
//Função Principal
int main(){
	setlocale (LC_ALL,"PORTUGUESE");//caracteres do Portugues(ex:acentos,etc)
char play_again;
do{
 Jogo();
 getchar();
printf("DESEJA JOGAR NOVAMENTE??\n");
     printf("(S,s-Sim) ou (N,n-Não):");
         scanf("%c",&play_again);
}
while(play_again=='S' || play_again=='s');
return 0;
}
