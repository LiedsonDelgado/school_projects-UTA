; Conversoes hexadecimais de datas e numeros:
; 27d -> 1Bh
; 08d -> 08h
; 2005d -> 7D5h
; 2000d -> 7D0h
; 2024d -> 7E8h

mov ax, 7D5h  ; Move o valor hexadecimal 7D5 para o registrador AX.
mov bx, 08h   ; Move o valor hexadecimal 08 para o registrador BX.

mul bx        ; Multiplica AX por AX

mov cx, 7D5h  ; Move o valor hexadecimal 7D5 para o registrador CX.
xor dx, dx    ; Zera DX antes da divisão para evitar overflow.
div dx        ; Divide DX:AX por DX

mov dx, 7E8h  ; Move o valor hexadecimal 7E8 para o registrador DX.
mov ax, 7D5h  ; Move o valor hexadecimal 7D5 para o registrador AX.
sub dx, ax    ; Subtrai AX de DX. Resultado: DX = 7E8h - 7D5h.

xor bl, 08h   ; Aplica XOR entre BL e 08h, modificando BL.
xor cl, 7Dh   ; Aplica XOR entre CL e 7Dh, modificando CL.
mov cl, bh    ; Move o valor de BH para CL.

inc dx        ; Incrementa DX por 1.
dec ax        ; Decrementa AX por 1.

and dx, ax    ; Aplica operação AND entre DX e AX, armazenando o resultado em DX.
mov ax, dx    ; Move o valor de DX para AX.


.data
LED_DISPLAY dw ?  ; Define o 'LED_DISPLAY' como uma palavra (16 bits) de memoria.

.code
main PROC
    ; Suponhamos que o ano de nascimento está no registrador AX.
    mov ax, 2005  ; Ano de nascimento exemplo.

    cmp ax, 2000  ; Compara o ano de nascimento com 2000.
    jg year_above ; Se ano > 2000, pula para 'year_above'.
    jl year_below ; Se ano < 2000, pula para 'year_below'.
    
    ; Se o ano for exatamente 2000, você pode escolher uma das condições ou adicionar outro tratamento aqui.

year_above:
    mov dx, 1111d ; Define o valor 1111 decimal.
    mov [LED_DISPLAY], dx  ; Armazena 1111 no 'LED_DISPLAY'.
    jmp end_program  ; Pula para o fim do programa para evitar execução da próxima seção.

year_below:
    mov dx, 9999d ; Define o valor 9999 decimal.
    mov [LED_DISPLAY], dx  ; Armazena 9999 no 'LED_DISPLAY'.

end_program:
    ; Aqui você pode terminar o programa ou retornar ao sistema operacional.
    ; Por exemplo, em ambientes DOS, seria `int 21h` para terminar o programa.
    ; Em outros ambientes, você ajustaria conforme necessário.

    ret  ; Retorna do procedimento.

main ENDP

