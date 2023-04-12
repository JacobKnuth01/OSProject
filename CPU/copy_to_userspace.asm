
global  copyToUserSpace
global toUserSeg
global toKernSeg




toUserSeg:
    pusha
    mov ax, 0x23
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    popa
    ret
toKernSeg:
    pusha
    mov ax, 0x10
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    popa
    ret
copyToUserSpace:

    pop ebx
    mov [return], ebx;save return address
    
    pop ebx ;source
    pop eax ;destination
    
    pop edx 
    mov [len], edx ; save length
    mov edx, 0 ;counter



    
    loop:
    call toKernSeg
    mov ecx, [ebx] ;get the data at the source 
    call toUserSeg
    mov [eax], ecx ;put that source data at the destination address
    call toKernSeg
    add ebx, 1 ;go to next address
    add eax, 1

    add edx, 1 ; increment counter
    
    cmp [len], edx
    je end


    
    jmp loop ; loop again

    end:
        jmp [return]
    
    len:
        dd 1
    return:
        dd 1

   


