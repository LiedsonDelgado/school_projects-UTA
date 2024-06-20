org 100h

.stack

.data
    
    ;declaracao dos vetores
    aluno_notas db 10 dup(?) ;vetor para nota
    aluno_numero db 10 dup(?) ;vetor para numero do aluno
    
    ;opcao 1
    msg1 db "Digite o numero do aluno(0 a 9): $"
    msg2 db "Digite a nota do aluno(0 a 20): $"
    
    ;opcao 2
    melhor db "Aluno com nota mais alta: $"
    
    ;opcao 3
    pior db "Aluno com nota mais baixa: $"
    
    ;opcao 4
    aprovado db " Aprovados: $"
    
    reprovado db " Reprovados: $"
    
    ;Uso generico
    msg_numero db " ->Aluno: $"
    msg_nota db " ->Nota: $"
    msg_estado db " ->Estado: $"
    
    ;variaveis
    num db ?
    maior db ?
    indice db ?
    ap db ?
    rp db ?
    
    
    ;menu
    menu db 0dh,0ah,"-------- MENU --------",0dh,0ah
    op1 db 0dh,0ah,"1 - Inserir notas do aluno",0dh,0ah
    op2 db 0dh,0ah,"2 - Imprimir numero e nota do aluno com nota mais alta",0dh,0ah
    op3 db 0dh,0ah,"3 - Iprimir numero e nota do aluno com nota mais baixa",0dh,0ah
    op4 db 0dh,0ah,"4 - Iprimir a quantidade de alunos aprovados e reprovados",0dh,0ah
    op5 db 0dh,0ah,"5 - Media das notas da turma",0dh,0ah
    op6 db 0dh,0ah,"6 - Quantidade de notas acima e abaixo da media da turma",0dh,0ah
    op7 db 0dh,0ah,"7 - Tabela com numero,nota e se o aluno foi aprovado ou reprovado",0dh,0ah
    op8 db 0dh,0ah,"8 - Notas em ordem decrescente",0dh,0ah
    op9 db 0dh,0ah,"9 - Sair",0dh,0ah
    
    op db "Opcao: $"
     
    opcao db ? 
     
.code
    ;macro para mudanca de linha
    macro Novalinha 
        mov ah, 02h ;move para ah 02h
        mov dl, 0ah ;move para dl o caracter de mudanca de linha
        int 21h ;realiza a funcao
        mov dl, 0dh ;move para dl o caracter que move o cursor para o inicio da linha
        int 21h ;realiza a funcao
    endm
    
    
    
    ;imprimir mensagens
    macro imprime_msg msg 
        mov ah, 09h ;funcao para imprimir uma string
        lea dx, msg ;carrega o endereco da string em dx
        int 21h  ;chama a interrupcao para imprimir a string
    endm
    
    
    
    ;digitar numero do aluno
    macro numero_aluno num 
        mov ah, 01h ;funcao para ler um caracter do teclado        
        int 21h ;le o caracter do teclado e o coloca em al           
        sub al, 30h ;converte o caracter ASCII para um valor numerico 
        mov num, al ;armazena o valor na variavel num
    endm
    
    
    
    ;diditar nota do aluno
    macro nota_aluno   
        xor dx, dx  ;zera o registrador dx
        xor bx, bx  ;zera o registrador bx
        mov dl, 0ah ;move para dl 10
        mov ch, 2h  ;move para ch 2 - contador do loop para 2 digitos
        notas:
            mov ah, 01h ;funcao para ler um caracter do teclado
            int 21h ;le o caracter do teclado e o coloca em al
            cmp al, 0dh ;compara o caracter lido com enter(0Dh)
            je final ;salta para o label final se al for igual a enter
            
            mov ah, 0h ;zera ah para para multuplicacao
            sub al, 30h ;converte o caracter ASCII para um valor numerico  
            mov ah, al ;coloca o valor numerico em ah
            mov al, bl ;move o valor de bl para al
            mul dl ;multiplica al por 10 para deslocar o disco
            
            add al, dl ;adiciona o novo digito ao acumulador
            
            mov bl, al ;atualiza bl com o novo valor do acumulador
            
        loop notas ;faz o loop de notas
        final: 
    endm
    
    
    
    ; dados para 10 aluno
    macro dados_aluno 
        mov cx, 10h ;move para cx 10
        mov si, 0h  ;move para si 0
        
        aluno:
        
        Novalinha  ;imprime uma nova linha
        
        imprime_msg msg1 ;imprime a mensagem para inserei o numero do aluno
        numero_aluno al ;le o numero do aluno e armazena em al
        mov [aluno_numero + si], al ;move para a primeira posicao do vetor o calor de al
        
        Novalinha  ;imprime uma nova linha
       
        imprime_msg msg2 ;imprime a mensagem para inserir a nota do aluno
        nota_aluno ;le a nota do aluno e armazena bl
        mov num, bl ;armazena a nota lida na variavel num
        mov [aluno_notas + si], bl ;Armazena a nota do aluno no vetor aluno_notas
        
        inc si ;incrementa o valor de si
        cmp si,10 ;compara se si > 10
        je saltar_fora ;se si > 10 salta para o rotulo salta_fora
        
        
        Novalinha ;imprime uma nova linha
        
        loop  aluno ;decrementa cx e repete o loop se cx nao for zero
        saltar_fora:  
    endm
    
    macro imprime2Digitos 
        xor ax, ax   
        xor dx, dx   
        mov al, bl 
        mov ah, 0h
        mov bh, 0ah
        div bh
        mov dl, al
        mov bh, ah
        mov ah, 02h 
        add dl, 30h
        int 21h    
        mov dl, bh
        add dl, 30h
        int 21h
    endm            
    
    
    macro melhor_aluno
        mov si, 00h  ;inicializa o indice de aluno com 0
        mov al, [aluno_notas + si]  ;bl toma o valor que esta na primeira posicao do vetor
        mov maior, al ;move para maior aluno_notas[si]       
        mov cx, 10h  ;loop para percorrer 10 alunos

    
    procura:    
        inc si ;incrementa o indice
        mov al, maior ;move para al o valor que esta na variavel maior 
        mov ah, [aluno_notas + si]  ;move para ah aluno_notas[si]
        cmp ah, al ;compara se ah > al
        jg proximo ;salta para proximo se ah > al
        jmp continua ;salta para continua se nao for
        
    proximo:
        mov maior, ah ;move para maior o valor de ah->aluno_notas[si]
        mov bx, si ;move para bx o valor de si
        
    continua:
        loop procura ;faz loop do label procura
        mov  indice, bl ;move para indice o valor de bl  
    endm
    
    macro aprovado_reprovado a b
        mov si, 00h
        mov cx, 10h
        
        contar:
            mov ah, [aluno_notas + si]
            cmp ah, 9d
            jbe reprovou
            cmp ah, 10d
            jge passou
            
            reprovou:
            inc rp
            jmp fora
                
            passou:
                inc ap
            
        fora:
        
        loop contar
    endm
    
main:

    M_menu:
        Novalinha
        mov ah, 09h ;funcao para imprimir uma string
        lea dx, menu ;carrega o endereco da string   
        int 21h ;imprime o menu
        
        mov ah, 01h ;funcao para ler uma caracter do teclado
        int 21h  ;interrompe para chamar a funcao 01h       
        mov opcao, al ;armazena o valor de al na variavel opcao
        
        Novalinha  ;imprime uma nova linha
        
      
        cmp opcao, '1'  ;compara opcao com 1
        je opcao_1  ;se for opcao for igual a 1 salta para opcao_1
        
        cmp opcao, '2' ;compara opcao com 2
        je opcao_2 ;se for opcao for igual a 1 salta para opcao_2
        
        cmp opcao, '3' ;compara opcao com 3
        je opcao_3 ;se for opcao for igual a 1 salta para opcao_3  
        
        cmp opcao, '4' ;compara opcao com 4
        je opcao_4  ;se for opcao for igual a 1 salta para opcao_4 
        
        cmp opcao, '5' ;compara opcao com 5
        je opcao_5 ;se for opcao for igual a 1 salta para opcao_5  
        
        cmp opcao, '6' ;compara opcao com 6
        je opcao_6 ;se for opcao for igual a 1 salta para opcao_6  
        
        cmp opcao, '7' ;compara opcao com 7
        je opcao_7 ;se for opcao for igual a 1 salta para opcao_7  
        
        cmp opcao, '8' ;compara opcao com 8
        je opcao_8 ;se for opcao for igual a 1 salta para opcao_8  
        
        cmp opcao, '9' ;compara opcao com 9
        je opcao_9 ;se for opcao for igual a 1 salta para opcao_9
    
    
        
    opcao_1:
        dados_aluno ;invoca a macro dados_aluno para digitar o numero e a nota de 10 alunos  
        jmp M_menu ;salta para o rotulo M_menu 
        
    opcao_2:
        Novalinha
        
        melhor_aluno
        
        imprime_msg melhor
        Novalinha
        
        
        imprime_msg msg_numero
        ;imcompleto: falta imprimir o numero
        Novalinha
        
        imprime_msg msg_nota 
        ;imcompleto: falta imprimir a nota
        Novalinha
        
        jmp M_menu
        
    opcao_3:
        jmp M_menu
        
    opcao_4: ;esta com erros mas esta funcionando
        aprovado_reprovado ap rp
        Novalinha
        
        imprime_msg aprovado
        mov bl, ap
        imprime2Digitos 
        Novalinha
        
        imprime_msg reprovado
        xor bx, bx
        mov bl, rp
        imprime2Digitos 
        Novalinha
        jmp M_menu
        
    opcao_5:
        jmp M_menu    
        
    opcao_6:
        jmp M_menu    
        
    opcao_7:
        jmp M_menu
        
    opcao_8:
        jmp M_menu
        
    opcao_9:
        jmp Fim ;salta para o label Fim
        
    
    
    
    
    
Fim:

end main   