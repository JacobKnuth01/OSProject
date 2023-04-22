#include "methods.h"
#include "../devices/GPU.h"


void memory_copy(unsigned char *s, unsigned char *d, int limit)
{
    int i;

    for (i =0;i < limit; i++ )
    {
        
        *d = *s;
        d = d + 1;
        s = s + 1;
        

    }
}






char* intToString(int i)
{
    int x;
    static char s[20];
    int index = 0;

    while (i > 0)
    {
        x = i % 10;
        i = i /10;

        s[index] = oneLetterIntLookUp(x);
        index = index + 1;
        
    }
    s[index] = 0x0;

    
    return flipString(s, index);


}


char oneLetterIntLookUp(int i)
{
    if (i == 0)
    {
        return '0';
    }
    else if (i ==1)
    {
        return '1';
    }
    else if (i ==2)
    {
        return '2';
    }

    else if (i ==3)
    {
        return '3';
    }
    else if (i ==4)
    {
        return '4';
    }
    else if (i ==5)
    {
        return '5';
    }
    else if (i ==6)
    {
        return '6';
    }
    else if (i ==7)
    {
        return '7';
    }
    else if (i ==8)
    {
        return '8';
    }
    else if (i ==9)
    {
        return '9';
    }
}
char oneLetterHexIntLookUp(int i)
{
    if (i == 0)
    {
        return '0';
    }
    else if (i ==1)
    {
        return '1';
    }
    else if (i ==2)
    {
        return '2';
    }

    else if (i ==3)
    {
        return '3';
    }
    else if (i ==4)
    {
        return '4';
    }
    else if (i ==5)
    {
        return '5';
    }
    else if (i ==6)
    {
        return '6';
    }
    else if (i ==7)
    {
        return '7';
    }
    else if (i ==8)
    {
        return '8';
    }
    else if (i ==9)
    {
        return '9';
    }
    else if (i == 0xA)
    {
        return 'A';
    }
    else if (i == 0xB)
    {
        return 'B';
    }
    else if (i == 0xc)
    {
        return 'C';
    }
    else if (i == 0xd)
    {
        return 'D';
    }
    else if (i == 0xe)
    {
        return 'E';
    }
    else if (i == 0xf)
    {
        return 'F';
    }
    
}   


char* hexIntToString(int i)
{
    int x;
    static char s[20];
    int index = 0;

    while (i > 0)
    {
        x = i % 0x10;
        i = i /0x10;

        s[index] = oneLetterHexIntLookUp(x);
        index = index + 1;
        
    }
    s[index] = 0x0;

    
    return flipString(s, index);


}

char* flipString(char* s, int len)
{
    //len not including ending 0
    
    
    
    
    
    //this will need to be changed
    static char replacmentS[50+1];
    int i;
    
    for (i =0;i < len;i++)
    {
        
        replacmentS[len-1 -i] = *(s+i);



    }
    replacmentS[len] = 0x0;
    return replacmentS;
    
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