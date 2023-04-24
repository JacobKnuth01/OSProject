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
   copyToUserSpace(0x12000, 0x0, 0x7000);
   writeString("hello world", 0, 0);
   switchSegments();

   
   
    
    
   return 0;
   
    
   

   

    

   

  
 
  
   
   
   
 

  

 

}

