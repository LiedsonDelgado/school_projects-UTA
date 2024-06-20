org 100h

.stack

.data
msg db "Minuscula:$"
msg1 db "Maiuscula:"
carater db ?

.code
mov ah,09h
lea dx,msg
int 20h

mov ah,01h
int 21h

mov carater,al

call NewLine

mov ah,09h
lea dx,msg1
int 21h

sub carater,20h

mov ah,02h
mov dl,carater
int 21h


call NewLine

mov al,09h
mov dl,carater
int 21h

NewLine Proc   
mov al,02h
mov dl,0ah

mov al,09h
int 21h
ret
NewLine Endp