[org 0x7c00];modify below offsets by this number. the bios has loaded us in at this address in memory

;set the stack 

mov bp, 0x9000
mov sp, bp

;load more disk sectors in to ram

mov ah, 0x02 ;tell bios that we are going to read from the disk

mov bx, 0x1000 ; store what is read from the disk in that memory location
mov dl, dl ; what disk should be loded. We want to load this disk, the bios has automaticallhy filled that register with the correct number
mov cl, 0x02 ;start on sector 2 (we have already loaded the 1st one, boot sector)
mov al, 54 ;load that many sectors
mov ch, 0x00 ;what cylender
mov dh, 0x00 ;head number
int 0x13 ;run the bios interupt

;load GDT and switch to 32 bit protected mode

cli ;disables interrupts
lgdt [gdt_descriptor] ; load the GDT


;tell the CPU to go in to 32 bit mode
mov eax, cr0
or eax, 0x1 ; 3. set 32-bit mode bit in cr0
mov cr0, eax

; a far jump is nessesary to force the CPU to process all instruction
jmp CODE_SEG:destination

[bits 32]
destination:
; update the segment registers
mov ax, DATA_SEG 
mov ds, ax
mov ss, ax
mov es, ax
mov fs, ax
mov gs, ax


;set the stack up
mov ebp, 0x90000
mov esp, ebp

;load TSS
mov ax, 0x28
ltr ax

;enter kernel

jmp 0x1000 ; jump over to kernel

jmp $

;tss


tss:
    dd 0x0
    dd 0x90000 ;esp0
    dd 0x10 ;ss0
    TIMES 22 dd 0x0
    dw 0x0
    dw TSS_SIZE        ;IOPB offset
;    dd 0x0            ; SSP: If not using a shadow stack (CET disabled)
                       ; this can be removed
tssend:
TSS_SIZE equ tssend - tss

;gdt table

;GDT is taken from: https://github.com/cfenollosa/os-tutorial
gdt_start:
    ;first entry is always null (each entry is 8 bytes or 64 bits)
    dd 0x0 ; 4 byte
    dd 0x0 ; 4 byte

; GDT for code segment. base = 0x00000000, length = 0xfffff
; for flags, refer to os-dev.pdf document, page 36
gdt_code: 
    dw 0xFFFF   ; segment length, bits 0-15
    dw 0x0       ; segment base, bits 0-15
    db 0x0       ; seg2ment base, bits 16-23
    db 10011010b ; flags (8 bits)
    db 11000000b ; flags (4 bits) + segment length, bits 16-19
    db 0x0       ; segment base, bits 24-31

; GDT for data segment. base and length identical to code segment
; some flags changed, again, refer to os-dev.pdf
gdt_data:
    dw 0xFFFF
    dw 0x0
    db 0x0
    db 10010010b
    db 11000000b
    db 0x0

U_code: 
    dw 0xFFFF    ; segment length, bits 0-15
    dw 0x0000  ; segment base, bits 0-15
    db 0x10     ; seg2ment base, bits 16-23
    db 11111010b ; flags (8 bits)
    db 11000000b ; flags (4 bits) + segment length, bits 16-19
    db 0x00       ; segment base, bits 24-31

; GDT for data segment. base and length identical to code segment
; some flags changed, again, refer to os-dev.pdf
U_data:
    dw 0xFFFF
    dw 0x0000
    db 0x10
    db 11110010b
    db 11000000b
    db 0x00
gdt_tss:
    dw TSS_SIZE-1      ; segment length, bits 0-15
    dw tss             ; segment base, bits 0-15
    db 0x0             ; segment base, bits 16-23
    db 10001001b       ; access flags (8 bits)
    db 00000000b       ; flags (4 bits) + segment length, bits 16-19
    db 0x0             ; segment base, bits 24-31


gdt_end:

; GDT descriptor
gdt_descriptor:
    dw gdt_end - gdt_start - 1 ; size (16 bit), always one less of its true size
    dd gdt_start ; address (32 bit)

CODE_SEG equ gdt_code - gdt_start
DATA_SEG equ gdt_data - gdt_start
U_CODE_SEG equ U_code - gdt_start
U_DATA_SEG equ U_data - gdt_start

;below informs the BIOS that this is a boot sector
times 510 - ($-$$) db 0
dw 0xaa55