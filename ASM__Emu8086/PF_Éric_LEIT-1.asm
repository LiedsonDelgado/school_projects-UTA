org 100h

.stack

.data
menu db 0dh,0ah, "Menu",0dh,0ah
op1 db "1 - Insira a nota entre 0 a 20: $"
op2 db "2 - Numero e nota do aluno mais alta: $"
op3 db "3 - Numero e nota do aluno mais baixa: $"
op4 db "4 - Quantidade de estudantes aprovados e reprovados: $",0dh,0ah 
op5 db "5 - Media das notas da turma: $",0dh,0ah
op6 db "6 - Quantidade de notas acima e abaixo da media: $",0dh,0ah
op7 db "7 - Tabela com numero de aluno, nota e se foi aprovado ou reprovado $",0dh,0ah
op8 db "8 - Notas em ordem decrescente: $",0dh,0ah
op9 db "9 - Sair $",0dh,0ah
msg_entrada db "Escolha uma opcao: $"
msg_notas db "Por favor, insira a nota do aluno $",0dh,0ah
msg_nota_MaisAlta db "Nota mais alta: Aluno $",0dh,0ah
msg_nota_MaisBaixa db "Nota mais baixa: Aluno $",0dh,0ah
msg_aprovados db "Aprovados: $",0dh,0ah
msg_reprovados db "Reprovados: $",0dh,0ah
msg_media db "Media das notas: $",0dh,0ah
msg_acima_media db "Notas acima da media: $",0dh,0ah
opcao db ?
invalida db 0dh,0ah,"Opcao Invalida!!",0dh,0ah,"$"
newline db 0dh, 0ah, "$" 
array_alunos db (1,2,3,4,5,6,7,8,9,10)

.code

meu_menu:

    mov ah, 09h
    lea dx, menu
    int 21h
    
    mov ah, 09h
    lea dx, msg_entrada
    int 21h
    
    mov ah, 01h
    int 21h
    sub al, dl
    
    mov [opcao], al  
    
    cmp [opcao], 01h 
    je inserir_notas
    
    cmp [opcao], 02h
    je nota_mais_alta
    
    cmp [opcao], 03h
    je nota_mais_baixa
    
    cmp [opcao], 04h
    je qtd_aprov_reprov
    
    cmp [opcao], 05h
    je media_notas 
    
    cmp [opcao], 06h
    je notas_acima_abaixo_media 
    
    cmp [opcao], 07h
    je tabela_notas
    
    cmp [opcao], 08h
    je notas_ordem_decrescente  
    
    cmp [opcao], 09h
    je sair

    jmp start 

inserir_notas:
    
    mov cx, 010h          
    mov si, 0h           
 
     
usar_loop:
     
    mov ah, 09h
    lea dx, msg_notas
    int 21h
        
    mov ah, 0ah      
    lea dx, alunos + si
    int 21h
        
    mov si, [alunos + si] 
    inc si
    loop usar_loop
        
    jmp start 
    
    
nota_mais_alta:

    