#include "../devices/GPU.h"
#include "../CPU/pipe.h"
#include "../CPU/interupts.h"
#include "methods.h"

idt_entry idt[256];
idt_ptr idt_pointer;
void initt()
{
   
   clearScreen();

   BOut(0x03D4, 0x0A);
   BOut(0x03D5, 0x20);
   intInterupts();
  //__asm__ __volatile__("int $2");
  switchSegments();
  
  
  // __asm__ __volatile__("jmp 0x80000");s

  
 
  
   
   
   
 

  

 

}

