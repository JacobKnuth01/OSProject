[bits 32]
global  copyToUserSpace
global toUserSeg
global toKernSeg
global grabByte
global grab32
global placeByte
global place32



place32:
    push ebp            
    mov ebp, esp        
    mov eax, [ebp+8]; location
    mov eax, [ebp+12] ;data
    
    call toUserSeg
    mov [eax], eax
    call toKernSeg


    mov esp, ebp        
    pop ebp             
    ret 
placeByte:
    push ebp            
    mov ebp, esp        
    mov eax, [ebp+8]; location
    mov cl, [ebp+12] ;data
    
    call toUserSeg
    mov [eax], cl
    call toKernSeg


    mov esp, ebp        
    pop ebp             
    ret 

grabByte:
    
    push ebp            
    mov ebp, esp        
    mov eax, [ebp+8]; argument 

    call toUserSeg
    mov ebx, 0
    mov bl, [eax]
    call toKernSeg
    mov eax, 0
    mov eax, ebx

    mov esp, ebp        
    pop ebp             
    ret 





grab32:
    push ebp            
    mov ebp, esp        
    mov eax, [ebp+8]; argument 
   
   
    call toUserSeg
    mov eax, [eax]
    call toKernSeg

    mov esp, ebp        
    pop ebp             
    ret 

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
    push ebp            
    mov ebp, esp        
    
    mov eax, [ebp+8]; source 
    mov ebx, [ebp+12]; destination 
    mov ecx, [ebp+16]; lenght

     
    loop:
    mov edx, [eax]
    call toUserSeg
    mov [ebx], edx
    call toKernSeg

    add eax, 1 ;next source
    add ebx, 1 ;next destination
    
    mov edx, [counter]
    add edx, 1
    mov [counter], edx

    cmp edx, ecx
    je done
    
    jmp loop


    done:
        mov esp, ebp        
        pop ebp             
        ret 

    counter:
        db 0
    
   





