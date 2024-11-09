org 100h

.stack

.data
msg db "Entre com um caracter:$"
carater db ?

.code
mov AH,09h
lea DX,msg
int 21h

mov ah,01h
int 21h

mov carater,AL

call NewLine

mov AH,02h
mov DL,carater
int 21h

NewLine Proc   
mov ah,02h
mov dl,0ah
int 21h

mov ah,02h
mov dl,0dh
int 21h
ret
NewLine Endp



ret