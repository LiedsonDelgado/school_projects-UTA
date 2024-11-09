 TITLE: Projeto Final
;Elaborado por:
    ;Carlos LEIT
    ;Gerson LEE
    ;Liedson Araujo LEIT

include emu8086.inc
;Incluir a biblioteca para utilizar o PRINT

org 100h
;Organizar o codigo

.stack

.data
                            ; Declaracao de variaveis  

    Menu db "----------------------- Menu Inicial -----------------------"; variavel menu do tipo db
    db 0ah, 0dh, 0ah, 0dh, 09h, "1 - Inserir notas (0 a 20)"
    db 0ah, 0dh, 09h, "2 - Numero e nota do aluno com nota mais alta"    
    db 0ah, 0dh, 09h, "3 - Numero e nota do aluno com nota mais baixa"
    db 0ah, 0dh, 09h, "4 - Quantidade de aprovados e Reprovados"
    db 0ah, 0dh, 09h, "5 - Media das notas da Turma"
    db 0ah, 0dh, 09h, "6 - Quantidade de notas acima e abaixo da media"
    db 0ah, 0dh, 09h, "7 - Tabela com numero de alunos com nota e se foi aprovado ou reprovado"
    db 0ah, 0dh, 09h, "8 - Notas em ordem decrescente"
    db 0ah, 0dh, 09h, "9 - Sair"
    db 0ah, 0dh, 0ah, 0dh, "Escolha: $"
    vetor db  10 dup <?> ;vetor que recebe as notas
    aux db 10 dup <?>   ;vetor aux para ordenar as notas
    soma db ?        ; variavel soma que recebe o valor total da soma
    maior db ?      ;variavel maior que recebe a maior nota
    menor db ?      ;variavel menor que recebe o menor nota
    pos db ?        ;variavel que guarda a posicao onde ta o maior e o menor das notas
    op db ?         ;variavel op que armazena a escolha obtida pelo utilizador
    count db ?      ;count utilizado na macro ler2digito onde controla o fluxo
    cont db ?       ;cont utilizado para imprimir na tela o numero de nota ex: "1 Nota: "
    maisS db ?      ;maisS armazena o valor mais significativo da div
    menosS db ?     ;menosS armazena o valor mais significativo da div
    Aprovados db ?  ;aprovados que conta o numero de aprovados
    Reprovados db ? ;reprovados que conta o numero de reprovados

.code 
    ;Criacao de macros para auxilhar no codigo 
     
    macro ImprimirString msg ; macro que imprima uma string
        mov ah, 09h     ; mover para ah, 09h que e a funcao de imprimir uma string 
        lea dx, msg      ;copiar para dx o endereco da var msg
        int 21h         ; realizar o int 21h que imprima na tela a mensagem
    endm  ;fechar macro
    
    macro somar soma        ;macro somar com o parametro soma
        mov si, 00d         ; Inicializa o indice do vetor
        xor ax, ax          ; Zera o registro ax
        xor bx, bx          ; Zera o registro bx, que armazenará a soma
        mov cx, 8d          ; Define o contador para o numero de elementos no vetor
    
        somarDigito:        ; Inicio do loop
            mov al, [vetor+si] ; Move o valor atual do vetor para ax
            add bl, al          ; Adiciona o valor de ax a soma em bx
            inc si              ; Incrementa o indice para o proximo elemento
        loop somarDigito    ; Repete o loop ate que cx seja zero
      
        mov soma, bl        ; Move a soma total para a variavel soma
    endm  ;fechar macro
    
    macro imprimir2Digito valor   ; macro imprimir2digito com o parametro valor
        
        xor ax, ax   ;zerar ax
        xor dx, dx   ;zerar dx
        mov al, valor  ;mover para al o valor
        mov bl, 10d    ; moveer para bl 10 em decimal para realizar uma div por 10
        div bl        ; dividir o valor de ax pelo valor do bl
        mov bl, al    ; mover para bl o valor de al que e o bit mais significativo da div
        mov bh, ah    ; mover para bh o valor de ah que e o bit menos significativo d div
        add bl, 30h   ; adicionar bl com 30h para combinar com o valor numerico na tabela ASCII
        add bh, 30h   ; adicionar bh com 30h para combinar com o valor numerico na tabela ASCII
        mov ah, 02h   ;mover para ah 02h que e uma funcao imprimir 1 carater 
        mov dl, bl    ;mover o carater a ser imprimido para dl porque o carater tem que estar em dl o valor que tiver em bl
        int 21h       ; realizar o int 21h que imprima o carater na tela
        mov dl, bh    ;mover o carater a ser imprimido para dl porque o carater tem que estar em dl o valor que tiver em bh
        int 21h       ; realizar o int 21h que imprima o carater na tela
        
    endm   ;fechar macro
    
    macro maiorE maior  ;macro maiorE com o parametro maior
        ; este macro procura o maior elemento
        mov si, 00d  ; mover para si 00h onde si e responsavel por delocar no vetor ou seja o indice do vetor
        mov al, [vetor+si] ; mover para al o valor do vetor de acordo com o si/posicao
        mov maior, al   ; mover para a variavel maior o valor em al
        mov cx, 10d     ; mover cx 10 em decimal para realizar um loop 10 vezes
        
        maiorElemento:   ; nome ou label do meu loop
           
            mov al, maior ;mover para al, o valor da variavel maior
            inc si      ; incrementar si
            mov al, [vetor+si]   ; mover para ah, o valor do vetor na posicao que se encontra o si
            cmp ah, al        ; comparar ah com al
            jg m          ; fazer jg onde salta se al maior ou seja salta se o valor de ah for maior que al
            jmp ok        ; caso o valor nao for maior e para nao executar as instrucoes abaixo fazer jmp incondicional
                m:        ; label m que so entra se al ou ah for maior
                    mov maior, ah  ;mover para maior o valor de ah
                    mov bx, si     ;mover para bx a posicao que esse elemento se encontra
              ok:      ; label do jmp incondicional
            
             
        loop maiorElemento ; meu loop com o label maiorElemento
        mov pos, bl    ; mover para pos o valor de bl ou seja a posicao onde ta o maior elemento
        
    endm  ;fechar macro
    
    macro ReceberDigito op   ; macro receber1digito com o parametro op
      
        mov ah, 01h    ; mover para ah 01h que e a funcao de ler 1 carater do teclado
        int 21h        ; realizar o int 21h para ler o carater onde guarda em al
        mov op, al     ; mover o carater para a variavel op
    
    endm  ;fechar macro
    
    macro comparar op     ; macro comparar com parametro op
        
        mov ah, op
        cmp ah, 31h
        je inserirNota
        cmp ah, 32h
        je MaiorNota
        cmp ah, 33h
        je MenorNota
        cmp ah, 34h
        je Q_Apr_Repro
        cmp ah, 35h
        je MediaTurma
        cmp ah, 36h
        je Nota_Media
        cmp ah, 37h
        je inserirNota
        cmp ah, 38h
        je inserirNota
        cmp ah, 39h
        je sair  
        
        call NewLine  ;chama o procedimento mudanca de linha
        print "Opcao errada !!!"  ; imprima na tela a mensagem "Opcao errada !!!" 
        call NewLine      ;chama o procedimento mudanca de linha
        print "Escolha novamente"   ; imprima na tela a mensagem "Escolha novamente"
        call NewLine   ;chama o procedimento mudanca de linha
        jmp infinito  ; saltar para o rotulo infinito
        
    
    endm   ;fechar macro
    
    macro le2Digito 
        
            xor dx, dx
            xor bx, bx
            mov dl, 0ah
            mov count, 2h
            
            recebe:      
            
                mov ah, 01h
                int 21h
                cmp al, 0dh
                mov ah, 0h
                sub al, 30h
                mov dh, al
                mov al, bl
                mul dl
                add al, dh
                mov bl, al   
                dec count
                
            cmp count, 0h   
            jne recebe 
    endm  ;fechar macro
    
    imprimir1digito macro valor      ;macro imprimir1digito com o parametro valor
        
        mov ah, 02h    ; mover para ah 02h que e a funcao de imprimir 1 carater
        mov dl, valor   ;mover para dl o valor a ser imprimido
        add dl, 30h   ; adicionar dl com 30h para considir com o valor na tabela ASCII
        int 21h    ;realizar a funcao
        
    endm ;fechar macro
    
    macro menorE menor      ;macro menorE como o parametro menor
        ; este macro procura qual e a menor nota
        mov si, 00d
        mov al, [vetor+si]
        mov menor, al
        mov cx, 10d
        
        menorElemento: 
           
                mov ah, menor
                inc si
                mov al, [vetor+si]
                cmp ah, al
                jb mm
                jmp nao
                    mm:
                        mov menor, ah
                        mov bx, si
                  nao:
            
             
        loop menorElemento
        mov pos, bl
        
    endm ;fechar macro
    
    macro limpar
        
        xor ax, ax
        xor bx, bx
        xor cx, cx
        xor dx, dx
        mov ah, 06h
        int 10h
        
    endm  ;fechar macro
    
    calcularMedia macro       ;zeramos ax & dx porque a divisao utiliza esses 2 registadores
        xor ax, ax  ;zerar ax
        xor dx, dx  ;zerar dx
        mov al, soma  ; mover para ah o resultado da soma armezenado na variavel soma
        mov bl, 10d   ; mover para bl 10 em decimal para calcular a media sabendo que sao 10 alunos
        div bl        ; dividir bl por valor que tiver em ax onde ah->menos significativo e al->mais significativo
        mov maisS, al ; mover para a variavel maisS o valor de al que e o bit mais significativo
        mov menosS, ah ; mover para a variavel menosS o valor de ah que e on bit menos significativo
        call NewLine   ;chama o procedimento mudanca de linha 
        Print "Media da turma: " ;imprimir no ecra "Media da turma: "
        imprimir2digito maisS    ; chamar macro imprimir2digito para imprimir o contiudo da var maisS
        mov ah, 02h      ;mover para ah 02h que e uma funcao imprimir 1 carater
        mov dl, 2ch      ;mover o carater a ser imprimido para dl porque o carater tem que estar em dl
        int 21h          ; realizar o int 21h que executa a funcao e imprima o valor na tela
        imprimir1digito menosS ; chamar macro imprimir1digito que imprima o valor da var menosS
        
    endm ;fechar macro
    
    Apro_Repro macro apro repro
        mov si, 00h
        mov cx, 10d
        percorrer:
        
            mov ah, [vetor+si]
            cmp ah, 9d
            jbe reprov
            cmp ah, 10d
            jge aprov
                
                reprov:
                    inc reprovados
                    jmp salto                
                aprov:
                    inc aprovados 
                    
                    salto:             
                                 
        loop percorrer     
        
    endm ;fechar macro
    
    macro abaAss aba aci
    
            
        
    endm ;fechar macro
            
main:
    
    infinito:     ; rotulo infinito do jmp incondicional
      
        imprimirString Menu 
        
        receberDigito op
        
        comparar op
        
        inserirNota:
            call NewLine
                    
            mov cx, 10d
            mov si, 0d
            mov cont, 01h 
            
            Print "Introduza as notas"          
            ler:  
                erro:
                      call NewLine
                      cmp cont, 09h
                      jg maior9
                      imprimir1digito cont
                      jmp saltar 
                            
                      maior9:      
                            
                            imprimir2digito cont       
                                 
                      saltar:
                      Print " Nota: "
                      le2Digito
                      cmp bl, 20d
                      jbe aceito
                      call NewLine
                      Print "ERRO: Escala de 0 a 20"
                jmp erro
                  aceito: 
                      mov [vetor+si], bl
                      inc si
                      inc cont
            loop ler 
    
    call NewLine  ;chama o procedimento mudanca de linha
    call NewLine  ;chama o procedimento mudanca de linha
    jmp infinito  ; saltar para o rotulo infinito
    
        MaiorNota:
            limpar
                
            maiorE maior
            call NewLine
            Print "Aluno: "
            add pos, 01h
            imprimir1digito pos
            Print " com a nota: "
            imprimir2digito maior       
                
    call NewLine  ;chama o procedimento mudanca de linha
    call NewLine  ;chama o procedimento mudanca de linha
    jmp infinito  ; saltar para o rotulo infinito
    
          MenorNota:
    
            menorE menor
            call NewLine
            Print "Aluno: "
            add pos, 01h
            imprimir1digito pos
            Print " com a nota: "
            imprimir2digito maior       
          
    call NewLine ;chama o procedimento mudanca de linha
    call NewLine ;chama o procedimento mudanca de linha
    jmp infinito  ; saltar para o rotulo infinito
    
          MediaTurma:
                somar soma
                calcularMedia
                
    call NewLine ;chama o procedimento mudanca de linha
    call NewLine ;chama o procedimento mudanca de linha
    jmp infinito  ; saltar para o rotulo infinito
    
          Q_Apr_Repro:
                Apro_Repro aprovados reprovados
                call NewLine
                Print "Numero de aprovados: "
                imprimir2digito aprovados
                call NewLine
                Print "Numero de reprovados: "
                imprimir2digito reprovados
          
    call NewLine ;chama o procedimento mudanca de linha
    call NewLine ;chama o procedimento mudanca de linha
    jmp infinito   ; saltar para o rotulo infinito
    
          Nota_Media:
          
          
     call NewLine ;chama o procedimento mudanca de linha
     call NewLine ;chama o procedimento mudanca de linha
     jmp infinito  ; saltar para o rotulo infinito 
    
    NewLine proc ; procedimento mudanca de linha
        
        mov ah, 02h     ; mover para ah 02h que e a funcao de imprimir 1 carater
        mov dl, 0ah     ;mover para dl o carater mudanca linha 
        int 21h         ; realizar a funcao
        mov dl, 0dh     ; mover para dl o carater cret que coloca o pusor no inicio
        int 21h         ; realizar a funcao
        
        ret             ;retornar para o endereco onde foi chamado
    NewLine endp        ; fechar o procedimento
    
    sair:        ; label sair que sai do loop infinito
    call NewLine     ;chama o procedimento mudanca de linha
    Print "Obrigado & volte sempre"     ; imprima na tela a mensagem "Obrigado & volte sempre"
      
end main      ; termina o programa