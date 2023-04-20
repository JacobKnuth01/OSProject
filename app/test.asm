[bits 32]










mov eax, 4
mov [0x400000], eax
mov eax, 10
mov [0x400004], eax

mov al, 't'
mov [0x400008], al
mov al, 'e'
mov [0x400009], al
mov al, 's'
mov [0x40000A], al
mov al, 't'
mov [0x40000B], al
mov al, 't'
mov [0x40000C], al
mov al, 0x0
mov [0x40000D], al
int 48




jmp $
