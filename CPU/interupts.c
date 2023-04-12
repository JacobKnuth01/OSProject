#include "interupts.h"
#include "../k/methods.h"
#include "../devices/GPU.h"
#include "pipe.h"
void setInteruptHandeler(int n, unsigned int handler)
{
    idt[n].base_hi = high_16(handler);
    idt[n].base_lo = low_16(handler);
    idt[n].sel = 0x8;
    idt[n].always0 = 0;
    idt[n].flags = 0x8E;

}

void mapIDT()
{
    idt_pointer.base = (unsigned int) &idt;
    idt_pointer.limit = 256 * sizeof(idt) - 1;
    __asm__ __volatile__("lidtl (%0)" : : "r" (&idt_pointer));
}

void irsHandler(intData data)
{
    
    
    char* vm = (char*) 0xb8000;
    vm[0] = 'A';
    writeString("an int was called", 10, 0);
    
    writeString(intToString(data.intNum), 11, 0);
    
    
    writeString(intToString(data.errCode), 12, 0);
    while (1)
    {
        /* code */
    }
    

    
    
   
    
    

    //__asm__ __volatile__("lidtl (%0)" : : "r" (0x344));
    //__asm__ __volatile__("int $2");
    
}

void irq_handler(intData data)
{
    if (data.intNum >= 40) BOut(0xA0, 0x20);
    BOut(0x20, 0x20); /* master */

    
}
void intInterupts()
{

    setInteruptHandeler(0, (unsigned int) isr0);
    setInteruptHandeler(1, (unsigned int) isr1);
    setInteruptHandeler(2, (unsigned int) isr2);
    setInteruptHandeler(3, (unsigned int) isr3);
    setInteruptHandeler(4, (unsigned int) isr4);
    setInteruptHandeler(5, (unsigned int) isr5);
    setInteruptHandeler(6, (unsigned int) isr6);
    setInteruptHandeler(7, (unsigned int) isr7);
    setInteruptHandeler(8, (unsigned int) isr8);
    setInteruptHandeler(9, (unsigned int) isr9);
    setInteruptHandeler(10, (unsigned int) isr10);
    setInteruptHandeler(11, (unsigned int) isr11);
    setInteruptHandeler(12, (unsigned int) isr12);
    setInteruptHandeler(13, (unsigned int) isr13);
    setInteruptHandeler(14, (unsigned int) isr14);
    setInteruptHandeler(15, (unsigned int) isr15);
    setInteruptHandeler(16, (unsigned int) isr16);
    setInteruptHandeler(17, (unsigned int) isr17);
    setInteruptHandeler(18, (unsigned int) isr18);
    setInteruptHandeler(19, (unsigned int) isr19);
    setInteruptHandeler(20, (unsigned int) isr20);
    setInteruptHandeler(21, (unsigned int) isr21);
    setInteruptHandeler(22, (unsigned int) isr22);
    setInteruptHandeler(23, (unsigned int) isr23);
    setInteruptHandeler(24, (unsigned int) isr24);
    setInteruptHandeler(25, (unsigned int) isr25);
    setInteruptHandeler(26, (unsigned int) isr26);
    setInteruptHandeler(27, (unsigned int) isr27);
    setInteruptHandeler(28, (unsigned int) isr28);
    setInteruptHandeler(29, (unsigned int) isr29);
    setInteruptHandeler(30, (unsigned int) isr30);
    setInteruptHandeler(31, (unsigned int) isr31);



    BOut(0x20, 0x11);
    BOut(0xA0, 0x11);
    BOut(0x21, 0x20);
    BOut(0xA1, 0x28);
    BOut(0x21, 0x04);
    BOut(0xA1, 0x02);
    BOut(0x21, 0x01);
    BOut(0xA1, 0x01);
    BOut(0x21, 0x0);
    BOut(0xA1, 0x0);



    setInteruptHandeler(32, (unsigned int)irq0);
    setInteruptHandeler(33, (unsigned int)irq1);
    setInteruptHandeler(34, (unsigned int)irq2);
    setInteruptHandeler(35, (unsigned int)irq3);
    setInteruptHandeler(36, (unsigned int)irq4);
    setInteruptHandeler(37, (unsigned int) irq5);
    setInteruptHandeler(38, (unsigned int)irq6);
    setInteruptHandeler(39, (unsigned int)irq7);
    setInteruptHandeler(40, (unsigned int)irq8);
    setInteruptHandeler(41, (unsigned int)irq9);
    setInteruptHandeler(42, (unsigned int)irq10);
    setInteruptHandeler(43, (unsigned int)irq11);
    setInteruptHandeler(44, (unsigned int)irq12);
    setInteruptHandeler(45, (unsigned int)irq13);
    setInteruptHandeler(46, (unsigned int)irq14);
    setInteruptHandeler(47, (unsigned int)irq15);

    mapIDT();

}