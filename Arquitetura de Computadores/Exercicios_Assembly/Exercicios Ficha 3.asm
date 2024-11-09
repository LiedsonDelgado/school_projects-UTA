;Exercicios Ficha 3

;1-
.model small
.stack 100h

.data
    msg db 0

.code
main:
    mov ax, @data
    mov ds, ax
    
    mov cx, 1
    
loop_start:
    mov ah, 2h
    mov dl, '0'
    add dl, cl
    int 21h
    
    inc cx
    
    cmp cx, 10
    jne loop_start
    
    mov ah, 4Ch
    int 21h
end main


;2-
.model small
.stack 100h

.data
    msg db 0

.code
main:
    mov ax, @data
    mov ds, ax
    
    mov cx, 'A'
    
loop_start:
    mov ah, 2h
    mov dl, cl
    int 21h
    
    inc cx
    
    cmp cx, 'Z' + 1
    jne loop_start
    
    mov ah, 4Ch
    int 21h
end main


;3-
;O codigo calcula operacoes matematicas.
;Inicializa os registradores DX e BX com zero.
;Define DL como 10 (0ah) e CX como 2.
;Entra em um loop (meu_loop).
;Dentro do loop, lê um caractere do teclado.
;Se o caractere lido for um retorno de carro (0dh), o loop termina (j e fim).
;Subtrai 30h do caractere lido para converter de ASCII para valor numérico.
;Multiplica o valor do caractere pelo valor em DL.
;Adiciona o resultado ao valor em BL.
;O loop continua até que um retorno de carro seja lido.
;Em seguida, termina (fim).

;4-
.model small
.stack 100h

.data
    msg1 db 13, 10, "Insira o primeiro numero: $"
    msg2 db 13, 10, "Insira o segundo numero: $"
    num1 db ?
    num2 db ?
    result db ?
    op_menu db 13, 10, "Escolha a operacao:", 13, 10, "1. Soma", 13, 10, "2. Subtracao", 13, 10, "3. Multiplicacao", 13, 10, "4. Divisao", 13, 10, "$"
    op db ?
    invalid_msg db 13, 10, "Opcao invalida! Tente novamente.$"
    zero_div_msg db 13, 10, "Erro: Divisao por zero.$"
    result_msg db 13, 10, "Resultado: $"
    newline db 13, 10, "$"

.code
main:
    mov ax, @data
    mov ds, ax
    
    ; Obter primeiro número
    mov ah, 9
    lea dx, msg1
    int 21h
    
    mov ah, 1
    int 21h
    sub al, 30h
    mov num1, al
    
    ; Obter segundo número
    mov ah, 9
    lea dx, msg2
    int 21h
    
    mov ah, 1
    int 21h
    sub al, 30h
    mov num2, al
    
    ; Mostrar menu de operações
    mov ah, 9
    lea dx, op_menu
    int 21h
    
    ; Obter a opção do usuário
get_option:
    mov ah, 1
    int 21h
    sub al, 30h
    mov op, al
    
    cmp op, 1
    je add_numbers
    cmp op, 2
    je subtract_numbers
    cmp op, 3
    je multiply_numbers
    cmp op, 4
    je divide_numbers
    
    ; Se a opção não for válida, mostrar mensagem e obter novamente
    mov ah, 9
    lea dx, invalid_msg
    int 21h
    jmp get_option
    
add_numbers:
    mov al, num1
    add al, num2
    mov result, al
    jmp print_result
    
subtract_numbers:
    mov al, num1
    sub al, num2
    mov result, al
    jmp print_result
    
multiply_numbers:
    mov al, num1
    mul num2
    mov result, al
    jmp print_result
    
divide_numbers:
    mov al, num1
    cmp num2, 0
    je division_by_zero
    mov bl, num2
    div bl
    mov result, al
    jmp print_result
    
division_by_zero:
    ; Se houver divisão por zero, mostrar mensagem de erro
    mov ah, 9
    lea dx, zero_div_msg
    int 21h
    jmp end_program
    
print_result:
    ; Imprimir o resultado
    mov ah, 9
    lea dx, result_msg
    int 21h
    
    mov dl, result
    add dl, '0'
    mov ah, 2
    int 21h
    
    ; Nova linha
    mov ah, 9
    lea dx, newline
    int 21h
    
end_program:
    mov ah, 4Ch
    int 21h
end main


;5-
.model small
.stack 100h

.data
    msg db 13, 10, "Insira um numero: $"
    num db ?
    count db 0

.code
main:
    mov ax, @data
    mov ds, ax
    
    mov ah, 9
    lea dx, msg
    int 21h
    
    mov ah, 1
    int 21h
    sub al, 30h ; converte de ASCII para número
    mov num, al
    
count_down:
    mov ah, 2
    mov dl, num
    add dl, '0' ; converte para ASCII
    int 21h
    
    dec num
    cmp num, 0
    jge count_down
    
    mov ah, 4Ch
    int 21h
end main


;6- 
.model small
.stack 100h

.data
    msg db 13, 10, "Insira um numero: $"
    num db ?
    result dw 1

.code
main:
    mov ax, @data
    mov ds, ax
    
    mov ah, 9
    lea dx, msg
    int 21h
    
    mov ah, 1
    int 21h
    sub al, 30h ; converte de ASCII para número
    mov num, al
    
    mov cx, num
calc_fact:
    mul cx
    loop calc_fact
    
    ; Resultado está em DX:AX
    ; Podemos salvá-lo em 'result' se necessário
    
    mov ah, 4Ch
    int 21h
end main

;7-
.model small
.stack 100h

.data
    msg db 13, 10, "Insira uma letra (ou 0 para sair): $"
    vowel_count db 0
    consonant_count db 0
    uppercase_count db 0
    lowercase_count db 0
    letter db ?

.code
main:
    mov ax, @data
    mov ds, ax
    
get_letter:
    mov ah, 9
    lea dx, msg
    int 21h
    
    mov ah, 1
    int 21h
    mov letter, al
    
    cmp letter, '0' ; Se for 0, sai do programa
    je end_program
    
    cmp letter, 'A'
    jl lowercase
    cmp letter, 'Z'
    jle uppercase
    cmp letter, 'a'
    jl not_letter
    cmp letter, 'z'
    jle lowercase
    
not_letter:
    jmp get_letter
    
uppercase:
    inc uppercase_count
    jmp get_letter
    
lowercase:
    inc lowercase_count
    
    cmp letter, 'a'
    je vowel
    cmp letter, 'e'
    je vowel
    cmp letter, 'i'
    je vowel
    cmp letter, 'o'
    je vowel
    cmp letter, 'u'
    je vowel
    jmp consonant
    
vowel:
    inc vowel_count
    jmp get_letter
    
consonant:
    inc consonant_count
    jmp get_letter

end_program:
    ; Aqui você pode imprimir os contadores conforme necessário
    
    mov ah, 4Ch
    int 21h
end main


;8-
.model small
.stack 100h

.data
    msg1 db 13, 10, "Insira o primeiro numero: $"
    msg2 db 13, 10, "Insira o segundo numero: $"
    num1 db ?
    num2 db ?
    temp db ?

.code
main:
    mov ax, @data
    mov ds, ax
    
    ; Obter primeiro número
    mov ah, 9
    lea dx, msg1
    int 21h
    
    mov ah, 1
    int 21h
    sub al, 30h
    mov num1, al
    
    ; Obter segundo número
    mov ah, 9
    lea dx, msg2
    int 21h
    
    mov ah, 1
    int 21h
    sub al, 30h
    mov num2, al
    
    ; Garantir que num1 < num2
    cmp num1, num2
    jg swap_numbers
    
    ; Imprimir números entre num1 e num2
print_numbers:
    mov dl, num1
    add dl, '0'
    mov ah, 2
    int 21h
    
    inc num1
    cmp num1, num2
    jle print_numbers
    
    jmp end_program
    
swap_numbers:
    ; Trocar os números se num1 > num2
    mov temp, num1
    mov num1, num2
    mov num2, temp
    jmp print_numbers

end_program:
    mov ah, 4Ch
    int 21h
end main


;9-
.model small
.stack 100h

.data
    msg1 db 13, 10, "Insira o primeiro numero: $"
    msg2 db 13, 10, "Insira o segundo numero: $"
    num1 db ?
    num2 db ?
    temp db ?

.code
main:
    mov ax, @data
    mov ds, ax
    
    ; Obter primeiro número
    mov ah, 9
    lea dx, msg1
    int 21h
    
    mov ah, 1
    int 21h
    sub al, 30h
    mov num1, al
    
    ; Obter segundo número
    mov ah, 9
    lea dx, msg2
    int 21h
    
    mov ah, 1
    int 21h
    sub al, 30h
    mov num2, al
    
    ; Garantir que num1 < num2
    cmp num1, num2
    jg swap_numbers
    
    ; Imprimir números pares entre num1 e num2
print_numbers:
    mov dl, num1
    add dl, '0'
    mov ah, 2
    int 21h
    
    inc num1
    cmp num1, num2
    jle check_even
    
    jmp end_program
    
check_even:
    ; Se num1 é ímpar, pular para próximo número
    mov ax, num1
    and ax, 1
    cmp ax, 0
    jne print_numbers
    
    jmp print_numbers
    
swap_numbers:
    ; Trocar os números se num1 > num2
    mov temp, num1
    mov num1, num2
    mov num2, temp

;10-
.model small
.stack 100h

.data
    msg db 13, 10, "Insira um numero entre 1 e 9 para a tabuada de multiplicacao: $"
    num db ?
    result_msg db 13, 10, "$"
    newline db 13, 10, "$"

.code
main:
    mov ax, @data
    mov ds, ax
    
    ; Obter o número do usuário
    mov ah, 9
    lea dx, msg
    int 21h
    
    mov ah, 1
    int 21h
    sub al, 30h
    mov num, al
    
    ; Validar se o número está entre 1 e 9
    cmp num, 1
    jl end_program
    cmp num, 9
    jg end_program
    
    ; Imprimir a tabuada de multiplicação
    mov cx, 1 ; Iniciar com o multiplicador 1
print_table:
    mov dl, num
    add dl, '0'
    mov ah, 2
    int 21h
    
    mov dl, 'x'
    mov ah, 2
    int 21h
    
    mov dl, cx
    add dl, '0'
    mov ah, 2
    int 21h
    
    mov dl, '='
    mov ah, 2
    int 21h
    
    mov al, num
    mul cx ; Multiplicar num por cx
    mov dl, al
    add dl, '0'
    mov ah, 2
    int 21h
    
    ; Nova linha
    mov dl, 13
    mov ah, 2
    int 21h
    
    mov dl, 10
    mov ah, 2
    int 21h
    
    inc cx ; Incrementar o multiplicador
    cmp cx, 10 ; Verificar se alcançou 10 (fim da tabuada)
    jne print_table ; Se não, imprimir a próxima linha
    
end_program:
    mov ah, 4Ch
    int 21h
end main


;11-
 .model small
.stack 100h

.data
    msg db 13, 10, "Insira um numero: $"
    num db ?
    is_prime db 'Primo', 13, 10, "$"
    not_prime db 'Nao primo', 13, 10, "$"
    divisor db ?

.code
main:
    mov ax, @data
    mov ds, ax
    
    ; Obter número do usuário
    mov ah, 9
    lea dx, msg
    int 21h
    
    mov ah, 1
    int 21h
    sub al, 30h
    mov num, al
    
    ; Inicializar contador de divisores
    mov divisor, 0
    
    ; Verificar se o número é primo
    mov cx, 2 ; Começar com divisor 2
check_divisor:
    mov ax, num
    xor dx, dx
    div cx ; Dividir o número por cx
    cmp dx, 0 ; Verificar se há resto
    je not_prime_label ; Se houver resto, não é primo
    inc cx ; Incrementar o divisor
    cmp cx, num ; Verificar se o divisor excedeu o próprio número
    jg prime_label ; Se sim, é primo
    jmp check_divisor ; Caso contrário, continuar a verificação

prime_label:
    mov ah, 9
    lea dx, is_prime
    int 21h
    jmp end_program

not_prime_label:
    mov ah, 9
    lea dx, not_prime
    int 21h
    jmp end_program

end_program:
    mov ah, 4Ch
    int 21h
end main

;12-
.model small
.stack 100h

.data
    msg db 13, 10, "Insira as 5 notas (separadas por espaco): $"
    notes db 5 dup (?)
    sum dw ?
    avg db ?
    result_msg db 13, 10, "Media das notas: $"
    newline db 13, 10, "$"

.code
main:
    mov ax, @data
    mov ds, ax
    
    ; Obter as 5 notas
    mov ah, 9
    lea dx, msg
    int 21h
    
    mov cx, 5
    lea si, notes
    
get_notes:
    mov ah, 1
    int 21h
    sub al, 30h ; converter de ASCII para número
    mov [si], al
    
    inc si
    loop get_notes
    
    ; Calcular a soma das notas
    mov cx, 5
    mov si, offset notes
    mov sum, 0
    
calc_sum:
    mov al, [si]
    add sum, ax
    
    inc si
    loop calc_sum
    
    ; Calcular a média
    mov ax, sum
    cwd
    mov bx, 5
    div bx
    mov avg, al
    
    ; Exibir a média
    mov ah, 9
    lea dx, result_msg
    int 21h
    
    mov dl, avg
    add dl, '0'
    mov ah, 2
    int 21h
    
    ; Nova linha
    mov ah, 9
    lea dx, newline
    int 21h
    
    mov ah, 4Ch
    int 21h
end main
