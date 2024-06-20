#ifndef EXERCICIO_1_FICHA_5_H_INCLUDED
#define EXERCICIO_1_FICHA_5_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Estrutura
struct aluno{
    int numero;
    char *nome;
    struct aluno* next;
};
typedef struct aluno Aluno;
typedef Aluno *PALUNO;

//Funcoes
char* newName(char* name);
PALUNO insertStudentSorted(PALUNO head,char *name,int number);
PALUNO delete_student(PALUNO head,char *name);

int search_by_name(PALUNO head,char *nome);
int search_by_number(PALUNO head,int numero);

void show_student(PALUNO head);
void dados_Aluno(PALUNO *head);

int itemCompare(char *name,char *name2);
void imprimirLista(PALUNO head);


#endif // EXERCICIO_1_FICHA_5_H_INCLUDED
