org 100h

.stack

.data
msg db "Insira dois Digitos:$"
msg1 db "Resultado da Soma:"
soma_resultado db ?

.code
mov ah,09h
lea dx,msg
int 20h

mov ah,01h
int 21h

mov soma_resultado,al

call NewLine

mov al,09h
lea dx,msg1
int 21h

mov ah,02h
mov bl,soma_resultado
int 21h


call NewLine

mov al,09h
mov dl,bl
int 21h   

mov ah,02h
mov dx,msg1

sub soma_resultado,20h

NewLine Proc   
mov ah,02h
mov dl,0ah
add bh,bl

mov al,09h
int 21h
ret
NewLine Endp