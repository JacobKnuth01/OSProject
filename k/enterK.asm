[bits 32]
[extern initt] ; Define calling point. Must have same name as kernel.c 'main' function
call initt ; Calls the C function. The linker will know where it is placed in memory
jmp $

