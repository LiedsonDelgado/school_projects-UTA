;Projeto_Final_Arquitetura_de_Computadores

;Elementos_do_Grupo(LEIT_1_ano):
;-Eric_Reis
;-Liedson_Delgado
;-Tiago_Dongo

org 100h

.stack

.data

;-VARIAVEIS-

;variaveis de mensagens de texto
menu db 0dh,0ah,"---MENU---";0Dh-CarriageReturn(CR)-move o cursor para o inicio da linha
                            ;0Ah-Line Feed(LF)-avanca para a proxima linha
msg1 db "Digite o Numero do Aluno(0 a 9): $"
msg2 db "Digite a Nota do aluno(0 a 20): $"
msg3 db "Aluno com a maior Nota: $"
msg4 db "Aluno com a menor Nota: $"
msg5 db "Aprovados: $"
msg6 db "Reprovados: $"

msg_numero db ">>Aprovado: $"
msg_nota db ">>Nota: $"
msg_estado db ">>Estado: $"

;variaveis Array
a_nota_aluno db 10 dup(?);array definido com tamanho 10
                       ;<=> array_aluno[10]
                       
a_numero_aluno db 10 dup(?);array definido com tamanho 10
                         ;<=> array_aluno[10]

;variaveis para opcoes do menu
op1 db 0dh,0ah,"1-Insira as Notas$";$ usado delimitar o fim da string
op2 db 0dh,0ah,"2-Numero e nota do aluno com a nota mais alta"
op3 db 0dh,0ah,"3-Numero e nota do aluno com a nota mais baixa"
op4 db 0dh,0ah,"4-Quantidade de estudantes aprovados (>=10) e reprovados (nota<10)"
op5 db 0dh,0ah,"5-Media das notas da turma"
op6 db 0dh,0ah,"6-Quantidade de notas acima e abaixo da media (Tabela)"
op7 db 0dh,0ah,"7-Tabela com numero de aluno, nota e se foi aprovado ou reprovado"
op8 db 0dh,0ah,"8-Notas em ordem decrescente"
op9 db 0dh,0ah,"9-Sair"

;opcoes adicionais
opcao db ?;variavel usada para receber um valor
          ;ou seja o valor inicial nao esta definido
opc db "Opcoes: $"
op_inv db "<OPCAO INVALIDA,tente novamente!>",0dh,0ah,"$"

;variaveis adicionais
num db ?
maior db ?
menor db ?

indice db ?
indice_2 db ?

aprov db ?
reprov db ?

.code

;Macros
 
endm

macro nova_linha;macro para inserir uma nova linha
    mov ah,02h;move para ah,02h
    mov dl,0ah;move para dl,carater que coloca o cursor no inicio da linha 
    int 21h;realiza a funcao
    mov dl,0dh;move para dl,carater que coloca o cursor no inicio da linha
    int 21h
    endm

macro imprimir_msg msg;macro para imprimir mensagens na tela
    mov ah,09h;coloca o valor da string em dx
    lea dx,msg;carrega o endereco da string em dx
    int 21h;executa uma interrupcao para imprimir a string
    endm

macro numero_aluno num;macro para introduzir
    mov ah,01h;le um carater
    int 21h;coloca o carater lido em al
    sub al,30h;converte o carater ASCII de um valor
    mov num,al;armazena o valor na variavel num
endm

macro nota_aluno;macro para ler e converter
                ;a nota do aluno ate 2 digitos
    xor dx,dx;dx passa a ser 0
    xor bx,bx; ax passa tambem ser 0
    mov dl,0ah;move para dl 10
    mov ch,2h;move para ch 2-contador loop para 2 digitos
    
Notas:
    mov ah,01h;funcao para ler um caracter do teclado
    int 21h;le o caracter do teclado e o coloca em al
    cmp al;compara o caracter lido com enter(0Dh)
    je final;salta para o label final se al for igual a enter
    
    mov ah,0h;zera ah para para multuplicacao
    sub al,30h;converte o caracter ASCII para um valor numerico
    mov ah,al;coloca o valor numerico em ah
    mov al,bl;move o valor de bl para al
    mul dl;multiplica al por 10 para deslocar o disco
    
    add al,dl;adiciona o novo digito ao acumulador
    mov bl,al;atualiza bl com o novo valor do acumulador
             
    loop Notas;faz o loop de notas
Final:
endm

macro dados_aluno;macro para colocar
                 ;dados dos 10 aluno
    mov cx,10h;coloca em cx 10h
    mov si,0h;o indice do vetor comeca a 0
      
aluno:
    nova_linha;imprime uma nova linha
      
    imprimir_msg msg1;exibe a mensagem da variavel msg1
    a_nota_aluno,al;le o numero do aluno e guarda em al
    mov [a_aluno_numero+si],al;move para a primeira posicao do vetor para al
     
    nova_linha
     
    imprime_msg msg2;exibe a mensagem da variavel msg2
    a_numero_aluno;le o numero do aluno e guarda em bl
    mov num, bl;armazena a nota lida na variavel num
    mov [a_nota_aluno + si], bl;armazena a nota do aluno no vetor nota_aluno
        
    inc si;incrementa o valor de si
    cmp si,10h;compara se si maior 10
    je sair_fora;se si for maior que 10 salta para o label sair_fora
        
    nova_linha
         
    loop  aluno;decrementa cx e repete o loop se cx nao for 0
sair_fora:
    endm

macro imprime_2_digitos
    xor ax,ax
    xor dx,dx
    mov al,bl
    mov ah,0h
    mov bh,0ah
    div bh
    mov dl,al
    mov bh,ah
    mov ah,02h
    add dl,30h
    
    int 21h
    mov dl,bh
    add dl,30h
    int 21h
    endm

macro melhor_aluno
    mov si,00h  ;inicializa o indice de aluno com 0
    mov al,[a_nota_aluno+si]  ;bl toma o valor que esta na primeira posicao do vetor
    mov maior, al ;move para maior aluno_notas[si]       
    mov cx,10h  ;loop para percorrer 10 alunos

    
procura_melhor:    
    inc si;incrementa o indice
    mov al,maior ;move para al o valor que esta na variavel maior 
    mov ah,[a_nota_aluno + si];move para ah aluno_notas[si]
    cmp ah,al;compara se ah > al
    jg proximo;salta para proximo se ah > al
    jmp continua;salta para continua se nao for
        
proximo_melhor:
    mov maior,ah ;move para maior o valor de ah->aluno_notas[si]
    mov bx,si;move para bx o valor de si
continua:
    loop procura;executa loop do label procura
    mov indice,bl;move para indice o valor de bl  
    endm

macro pior_aluno
    mov si,00h
    mov al,[a_nota_aluno+si]
    mov menor, al
    mov cx,10h
procura_pior:    
    inc si
    mov al,menor
    mov ah,[a_nota_aluno + si]
    cmp ah,al
    jl proximo_pior
    jmp continua_pior
proximo_pior:
    mov menor,ah
    mov bx,si
continua_pior:
    loop procura_pior
    mov indice_menor,bl
endm
    
macro aprovacao_reprovacao_aluno
    mov si,00h;inicia o indice do vetor a 0
    mov cx,10h;coloca em cx 10
contar:;label que funciona como um contador para repetir istrucoes de comparacao
    mov ah,[ler_nota_aluno+si];;move para ah aluno_notas[si]
    cmp ah,9d;compara se a nota do aluno com 9
    jbe reprovado;se o valor o for menor ou igual pula para o label reprovado 
    
    cmp ah,10d;compara se a nota do aluno com 90
    jge aprovado;se o valor o for menor ou igual pula para o label aprovado
reprovado:
    inc reprov;incrementa a o array reprov
    jmp fora;sai fora do label aprovado e pula para o label fora
aprovado:
    inc aprov;incrementa a o array reprov
    jmp fora;sai fora do label aprovado e pula para o label fora
fora:
        
loop contar;executa o loop do contar a ate tiver as 10 notas inseridas
endm

macro tabela_alunos
    mov si, 0;Inicia o indice do vetor a 0
    mov cx, 10;Define o loop para 10 alunos

exibir_tabela:
    nova_linha
    imprimir_msg msg_numero;Exibe o número do aluno

    mov al, [a_numero_aluno + si];Carrega o numero do aluno em AL
    mov bl, al
    imprime_2_digitos;Imprime o numero do aluno

    nova_linha
    imprimir_msg msg_nota;Exibe a nota do aluno

    mov al, [a_nota_aluno + si];Carrega a nota do aluno em AL
    mov bl, al
    imprime_2_digitos;Imprime a nota do aluno

    nova_linha
    imprimir_msg msg_estado;Exibe o estado (aprovado/reprovado)

    mov al, [a_nota_aluno + si];Carrega a nota do aluno em AL
    cmp al, 10
    jl reprovado
    imprimir_msg msg_numero_aprovado
    jmp proximo_aluno

reprovado:
    imprimir_msg msg_numero_reprovado

proximo_aluno:
    inc si
    loop exibir_tabela ;Decrementa CX e repete o loop se CX nao for 0
endm


Main:

m_MENU:

nova_linha
mov ah, 09h
lea dx,menu;exibe o menu principal
int 21h;;le a selecionada do opcao do menu e guarda o valor em opcao 

mov ah,01h
int 21h

mov opcao,al
cmp opcao,"1";compara se opcao for (1)
  je Opcao_1:;pula para o rotulo Opcao_1

cmp opcao,"2";compara se opcao for (2)
  je Opcao_2:;pula para o rotulo Opcao_2

cmp opcao,"3";compara se opcao for (3)
  je Opcao_3:;pula para o rotulo Opcao_3

cmp opcao,"4";compara se opcao for (4)
  je Opcao_4:;pula para o rotulo Opcao_4

cmp opcao,"5";compara se opcao for (5)
  je Opcao_5;pula para o rotulo Opcao_5

cmp opcao,"6";compara se opcao for (6)
  je Opcao_6;pula para o rotulo Opcao_6

cmp opcao,"7";compara se opcao for (7)
  je Opcao_7;pula para o rotulo Opcao_7
                                      
cmp opcao,"8";compara se opcao for (8)
  je Opcao_8;pula para o rotulo Opcao_8

cmp opcao,"9";compara se opcao for (9)
  je Opcao_9;pula para o rotulo Opcao_9

mov ah,09h ;se a opcao nao for nenhuma das validas
  lea dx,op_inv;faz uma copia do deslocamento(offset)do endereco da posicao para memoria
             ;na fonte no registrador destino
int 21h
  jmp m_MENU;volta e executa novamente o Menu       

Opcao_1:
  nova_linha
  dados_aluno;chama a macro dados_aluno e executa suas instrucoes
  jmp m_MENU;Termina o programa depois de sua executar as instrucoes acima 

Opcao_2:
 nova_linha
 melhor_aluno;chama a macro melhor_aluno e executa suas instrucoes
  
 imprime_msg msg3
 nova_linha
  
 imprime_msg msg_nota
  ;...
  
 nova_linha
 jmp m_MENU

Opcao_3: 
 nova_linha
 pior_aluno
 imprimir_msg msg4
 
 nova_linha
 imprimir_msg msg_numero
 
 mov bl,indice_2
 imprime_2_digitos
 imprimir_msg msg_nota
 
 mov bl,menor
 imprime_2_digitos
 nova_linha
 jmp m_MENU

Opcao_4:
 aprovacao_reprovacao_aluno
 nova_linha
 imprime_msg msg5
 
 mov bl,aprov
 imprime_2_digitos 
 nova_linha                            
        
 imprime_msg msg6
 xor bx, bx
 mov bl,reprov
 
 imprime_2_digitos  
 nova_linha
 jmp m_MENU
 
Opcao_5:

 jmp m_MENU

Opcao_6:

 jmp m_MENU

Opcao_7:
 nova_linha
 tabela_alunos ;chama a macro para exibir a tabela com os dados dos alunos
 jmp m_MENU
 
Opcao_8:

 jmp m_MENU
 
Opcao_9:
  jmp Fim;pula para o rotulo Fim para encerrar o programa    

Fim:
mov ah, 4Ch;Termina o programa
int 21h

endp
