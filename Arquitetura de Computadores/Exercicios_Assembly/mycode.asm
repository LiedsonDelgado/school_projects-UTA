mov ax,01100010b;mov destino,origem
mov al,15
mov ah,34h  

add al,01h;add destino,origem>>destino=destino+origem 
mov bx,1234h
add bx,ax

mov dl,08h;sub destino,origem>>destino=destino-origem
mov cl,02h
sub dl,cl;dl=dl-cl

mov ax,5h;mul=mult origem
mov bl,2h
mul bl;ax=ax*bl        

mov ax,0ah;div=div.int.origem
mov cl,2h
div cl;ax/cl>>al=div. inteira,ah=resto div.     

;dec destino
mov bl,6h
dec bl;dec.bl=bl-1>>05h  

;inc destino
mov dx,1234h
dec dx;inc.dx=dx+1>>05h