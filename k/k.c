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
   
   char* word = stringMalloc("test, i hope this works");
   char* word2 = stringMalloc("yes it will");

   writeString(word, 0, 0);
   //writeString(word2, 1, 0);

   //copyToUserSpace(0x5000, 0x0, 0x2000);
   //switchSegments();
    
   

   

    

   

  
 
  
   
   
   
 

  

 

}

