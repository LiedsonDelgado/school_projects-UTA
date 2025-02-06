#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//aprovar requisicao
void aprovar_requisicao(requisicao*req)
{
    req.estado=1;
    printf("a requisicao de %s foi aprovada\n",req.nome_usuario);
}


//rejeitar  requisição
void rejeitarRequisicao(struct Requisicao *req)
 {
    req->estado = 2;
    printf("a requisicao de %s foi rejeitada\n",req.nome_usuario);
}

// Função para listar requisições com base no status
void listarRequisicoesPorStatus(struct requisicao requisicoes[], int totalRequisicoes, int estado) {
    printf("Listagem de Requisicoes:\n");
    for (int i = 0; i < totalRequisicoes; i++) {
        if (requisicoes[i].estado == estado) {
            printf("Nome do Usuario: %s\n", requisicoes[i].nome_usuario);
            printf("Equipamento Solicitado: %s\n", requisicoes[i].equipamento);
            printf("estado da Requisicao: %s\n", (estado == 0) ? "Pendente" : (estado == 1) ? "Aprovada" : "Rejeitada");
            printf("Equipamento Devolvido: %s\n", (requisicoes[i].equipamentoDevolvido == 1) ? "Sim" : "Não");
            printf("\n");
        }
        main(){
		}
