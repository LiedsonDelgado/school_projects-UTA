;1-a)Liedson Delgado-LEIT-2023020

;2-a)20231020d  >>>  134B36Ch
;2-b)20050827d  >>>   131F38Bh
;2-c)2005d      >>>   7d5h

org 100h
.DATA
.CODE 
 
;3- 
mov bx,2023d

;4-
mov ax,0827d

;5-
mov ax,2h
mul ax 

;6-
mov ax,2023d
mov bx,0827d
mul ax

;7-
cmp ax,2023d

jg maior

maior: 
mov ax,2023d
mov bx,0827d
sub bx,ax

jmp

menor:
mov bx,0827d
mov ax,2023d

;8-
or ax,2023d
or cx,2005d
mov cx,2005d

;9-
xor cx,05d
xor cx,20d

;10-
mov ax,31020d
mov ax,20050d
add ax,bx

;11-
;LED_DISPLAY.
cmp ax,20050d

jg par

par:
mov ax,2023d
mov bx,0827d
div ax
mov ax,2222d

impar:
mov ax,2023d
mov bx,0827d
div ax
mov ax,1111d


