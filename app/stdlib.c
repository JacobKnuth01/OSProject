#include "stdlib.h"

char* input(int row, int col)
{
    int* pr = 0x400000;
    int * pc = 0x400004;
    
    *pr = row;
    *pc = col;

    __asm__ __volatile__("int $49");
    
    
    
    int x = 0;
    char* p = 0x400008;
    
    while (1)
    {
        
        if (p[x] == 15)
        {
            break;
        }
        
        x = x +1;

        if (p[x] == 0)
        {
            x = 0;
        }


        
        
        
        
        
    }
    
    

    
    
    __asm__ __volatile__("int $50");

    char* pp = 0x400008;
    return stringMalloc(pp);
    
}
void print(char*message, int rrow, int ccol)
{
    int* row = 0x400000;
    int* col = 0x400004;
    char* w = 0x400008;
    
    *row = rrow;
    *col = ccol;

    int x = 0;
    while (message[x] != 0)
    {
        
        char c = message[x];
        w[x] = c;
        x = x +1;
    }
    w[x] = 0;
    
    __asm__ __volatile__ ("int $48");
}


char* mallocSpot = 0x20000;
char* malloc(int space)
{
    char* temp = mallocSpot;
    mallocSpot = mallocSpot + space;
    return temp;
}

void copyString(char* source, char*destination)

{
    int x = 0;

    while (source[x] != 0)
    {
        destination[x] = source[x];
        x = x +1;
    }

    
}


char* stringMalloc(char* word)
{
    char x = 1;

     while (word[x-1] != 0)
     {
        x = x +1;
     }

     char* temp = malloc(x);

     copyString(word, temp);
     return temp;
     
}