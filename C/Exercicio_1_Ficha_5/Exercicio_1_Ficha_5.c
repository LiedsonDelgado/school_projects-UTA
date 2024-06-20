#include"exercicio_1_ficha_5.h"

char* newName(char*name){
    PALUNO name_std=(PALUNO)malloc(sizeof(Aluno));
   if(name==NULL){
        printf("Erro ao Alocar Espaco");
        exit(EXIT_FAILURE);
    }
    name_std->nome=(char*)malloc(sizeof(char)*(strlen(name)+1));
    if(name==NULL){
        printf("Erro ao Alocar Espaco");
        exit(EXIT_FAILURE);
    }
    strcpy(name_std->nome,name);
    name_std->next=NULL;
    return name_std->nome;
}
PALUNO insertStudentSorted(PALUNO head,char *name,int number){
    PALUNO new_student=(PALUNO)malloc(sizeof(Aluno));
if(new_student==NULL){
    printf("Erro ao Alocar Memoria\n");
    exit(EXIT_FAILURE);
}
new_student->numero=number;
new_student->nome=newName(name);

if(head==NULL||itemCompare(name,head->nome)<0){
    new_student->next=head;
    return new_student;
}
PALUNO atual=head;
PALUNO anterior=NULL;

while(atual!=NULL && itemCompare(name,atual->nome)<0){
    anterior=atual;
    atual=atual->next=atual;
}
anterior->next=new_student;
new_student->next=atual;
return head;
}

int search_by_name(PALUNO head,char *nome){
    PALUNO t;
    for(t=head;t!=NULL;t=t->next){
        if(strcmp(t->nome,nome)==0){
             return 1;
        }
    }
return 0;
}

int search_by_number(PALUNO head,int numero){
    PALUNO s;
    for(s=head;s!=NULL;s=s->next){
        if(s->numero==numero){
    return 1;
        }
    }
return 0;
}

PALUNO delete_student(PALUNO head,char *name){
PALUNO t=head;
if(t!=NULL && strcmp(t->nome,name)==0){
    head=t->next;
    free(t);
}
   else{
    PALUNO anterior;
    while(t!=NULL && strcmp(t->nome,name)!=0){
    anterior=t;
    t=t->next;
    }
    if(t==NULL)
        return head;
    anterior->next=t->next;
    free(t);
   }
return head;
}

void show_student(PALUNO atual){

    printf("\nAluno:%s\nNumero:%d\n",atual->nome,atual->numero);

}

int itemCompare(char *name,char *name2){

    return strcmp(name,name2);

//if(strcmp(name,name2)==0)
//    return 0;
//     else if(strcmp(name,name2)>0)
//       return 1;
//        else if(strcmp(name,name2)<0)
//          return -1;
}

void dados_Aluno(PALUNO *head) {

    PALUNO aluno = (PALUNO) malloc(sizeof(Aluno));
    char nome[50];
    int numero;

    printf("Nome do Aluno: ");
    scanf("%s",nome);
    printf("Numero do Aluno: ");
    scanf("%d",&numero);

    aluno->nome= newName(nome);
    aluno->numero= numero;
    aluno->next= *head;

    *head = aluno;

}
void imprimirLista(PALUNO head){

    printf("----------------\n");
    for(PALUNO i=head;i!=NULL;i=i->next){
        show_student(i);
        printf("----------------\n");
    }
}
