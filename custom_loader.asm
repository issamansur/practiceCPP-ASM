org 7C00h
start:
 cli ;
 xor ax, ax ;
 mov ds, ax ;
 mov es, ax ;
 mov ss, ax ;
 mov sp, 07C00h ;
 sti ;
 ;
 mov ax, 3
 int 10h
 ;
 mov ah, 2h
 mov dh, 0
 mov dl, 0
 xor bh, bh
 int 10h
 ;
 mov ax, 1301h
 mov bp, message1
 mov cx, 13
 mov bl, 02h
 int 10h
 ;
 mov ah, 2h
 mov dh, 1
 mov dl, 0
 xor bh, bh
 int 10h
 ;
 mov ax, 1301h
 mov bp, message2
 mov cx, 12
 mov bl, 02h
 int 10h
 jmp $
message1 db 'Hello, World!',0
message2 db 'How are you?',0

times 510 - ($ - $$) db 0 ;
db 0x55, 0xAA ;
