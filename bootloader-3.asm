CODE_SEG equ gdt_code - gdt_start
use16
org 0x7c00

boot:
    mov ax, 0x2401
    int 0x15
    mov ax, 0x3
    int 0x10
    cli
    lgdt [gdt_pointer]
    mov eax, cr0
    or eax, 0x1
    mov cr0, eax
    jmp dword CODE_SEG:boot2

gdt_start:
gdt_null:
    dq 0x0

gdt_code:
    dw 0xFFFF
    dw 0x0
    db 0x0
    db 10011010b
    db 11001111b
    db 0x0

gdt_data:
    dw 0xFFFF
    dw 0x0
    db 0x0
    db 10010010b
    db 11001111b
    db 0x0

gdt_end:
gdt_pointer:
    dw gdt_end - gdt_start
    dd gdt_start

DATA_SEG equ gdt_data - gdt_start

use32
boot2:
    mov ax, DATA_SEG
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    mov ss, ax
    mov ebx, 0xb8000
    mov ecx, 0

    mov esi, hello
    call print

    call newline

    mov esi, hello2
    call print

    jmp halt

print:
    mov ecx, 80
.loop:
    lodsb
    or al, al
    jz .done
    or eax, 0x0100
    mov word [ebx], ax
    add ebx, 2

    sub ecx, 1

    jmp .loop
.done:
    ret

newline:
.loop2:
    mov word [ebx], 0x0000
    add ebx, 2
    loop .loop2
    ret

halt:
    cli
    hlt

hello db "Hello, World!", 0

hello2 db "How are you?", 0

times 510 - ($-$$) db 0
dw 0xaa55
