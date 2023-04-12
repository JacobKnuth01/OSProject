
void BOut(unsigned short port, unsigned char data)
{
    __asm__ __volatile__("out %%al, %%dx" : : "a" (data), "d" (port));
}

unsigned char BIn(unsigned short port)
{   
    unsigned char result;
    __asm__("in %%dx, %%al" : "=a" (result) : "d" (port));
    return result;
}