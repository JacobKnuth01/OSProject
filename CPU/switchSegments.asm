[bits 32]


global switchSegments


switchSegments:

    cli
    mov ax, 0x23
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax

    

    mov eax, esp
    push dword 0x23
    push dword eax
    pushf
    
    pop eax ; Get EFLAGS back into EAX. The only way to read EFLAGS is to pushf then pop.
   or eax, 0x200 ; Set the IF flag.
    push eax
    
    push dword 0x1B
    push dword 0x0
    
    iret


