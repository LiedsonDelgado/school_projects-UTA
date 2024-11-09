;TP_2_Liedson Delgado-LEIT 1Ano

org 100h
.stack

.data

   ;Variaveis para Opcoes
   L db "Digite (L) para Imprimir a seu Nome:$"
   i db "Digite (i) para Imprima a minha Idade:$"
   e db "Digite (e) para Imprima 0<=Numeros<=Idade:$"
   d db "Digite (d) para Calcular a Soma e Divisao:$"
   
   ;Variaveis para Mensagens
   s db "Digite (s) para sair$"
   sair db "Encerrando o Programa...$"
   msg db "(-MENU-)Introduza suas Opcoes:$"
   nm db "Liedson Elisio Cruz Pires Delgado$"
   
   ;Variaveis para guardar Valores
   idd db "Tenho 19 anos$"
   aa db "Digite o ano atual$"
   an db "Digite o ano de nascimento$"
   
.code
;Inicio do programa

mov ah, 09h
lea dx, L
int 21h

call NovaLinha 

mov ah, 09h
lea dx, i
int 21h 

call NovaLinha

mov ah, 09h
lea dx, e
int 21h 
         
call NovaLinha

mov ah, 09h
lea dx, d
int 21h 

call NovaLinha

mov ah, 09h
lea dx, s
int 21h

call NovaLinha
call NovaLinha

mov ah, 09h
lea dx, msg
int 21h

mov ah, 01h;Ler opcao escolhida
int 21h

cmp al,'L';Verificar a opcao escolhida(L)
je Nome

cmp al,'i';Verificar a opcao escolhida(i)
je Idade:

cmp al,'e';Verificar a opcao escolhida(e)
je ImprimirNumeros:

cmp al,'d';Verificar a opcao escolhida(d)
je CalcularValores:

cmp al,'s';Verificar a opcao escolhida(s)
je Encerrar:  

mov ah, 09h
lea dx, idd
int 21h
 
call NovaLinha
cmp al, 4Ch
jp Nome

mov ax, 2024h
mov bx, 2005h
sub ax, bx
mov cx, bx

mov ah, 09h
lea dx, cx
int 21h

Nome:
mov ah, 09h
lea dx, nm
int 21h

jmp Encerrar

Idade:

;Calcular a idade (2024-2005=19)

mov ax, 2024h
sub ax, 2005h
mov cx, ax
mov ah, 09h
lea dx, cx ;cx guarda a idade calculada
int 21h

jmp Encerrar

ImprimirNumeros:
;ImprimirNumeros(0 a 19)
;{        
mov cx, 19d
mov ah, 00h
mov al, 19h
xor dx, dx

call NovaLinha
call NovaLinha

jmp Ciclo

Ciclo:
mov ah,09h
lea dx,e
int 21h 
        
mov ah, 09h
lea dx, d
int 21h
;}

CalcularValores:
;->(terminar dps...)

NovaLinha proc
    mov ah, 02h
    mov dl, 0ah
    int 21h
    
    mov ah, 02h
    mov dl, 0dh
    int 21h
    ret
    
NovaLinha endp 

Encerrar:
mov ah,09h
lea dx,sair
int 21h

end 