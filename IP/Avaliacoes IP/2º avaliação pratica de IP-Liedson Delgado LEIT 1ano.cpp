/*Liedson Elisio Cruz Pires Delgado LEIT 1ano*/
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
float calculavalorproduto(int quantidade,int precoUnitario,int desconto)
{
 return quantidade*precoUnitario-desconto;
}
int calculatotalfatura(int nprodutos) {
   int totalFatura = 0;

    for (int i = 1; i <= nprodutos; i++)
	{
        int quantidade;
        int precoUnitario, desconto;
        printf("Introduza a quantidade, o preço unitário e desconto do produto %d:\n", i);
        scanf("%d %f %f", &quantidade, &precoUnitario, &desconto);
        totalFatura += calculavalorproduto(quantidade, precoUnitario, desconto);
    }
       return totalFatura;
}

 main() {
    int nprodutos;
    printf("Introduza o número de produtos: ");
    scanf("%d", &nprodutos);
    float total = calculatotalfatura(nprodutos);
    printf("O valor total a pagar pela fatura é: %.2f\n", total);

   return i;
}





