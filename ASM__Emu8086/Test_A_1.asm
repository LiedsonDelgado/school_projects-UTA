#start=led_display.exe#

;out ADRESS,ax>>put ax value ax in ADRESS adress
mov ax,6660
out 199,ax

;in ax,ADRESS
mov ax,0h
in ax,199
