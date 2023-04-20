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
   asm volatile("sti");

   //asm volatile("jmp 0x5000");
   copyToUserSpace(0x5000, 0, 0x2000);

   
    switchSegments();
    switchSegments();
    switchSegments();
    switchSegments();
    switchSegments();
    switchSegments();
    switchSegments();
    switchSegments();
    
   

   

    

   

  
 
  
   
   
   
 

  

 

}

