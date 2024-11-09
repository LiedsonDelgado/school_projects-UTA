;divisao 8 bits
mov ax,123h
mov bl,02h
div bl;resultado>>AL,resto>>AH 

;divisao 16 bits
mov dx,1234h
xor dx,dx
mov ax,2345h
mov bx,12h
div bx;DX:AX/BX,Resultado>>AX,resto>>DX