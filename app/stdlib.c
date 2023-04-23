#include "stdlib.h"

char* input(int row, int col)
{
    int* pr = 0x400000;
    int * pc = 0x400004;
    
    *pr = row;
    *pc = col;

    __asm__ __volatile__("int $49");
    //print("dangerouse", 13, 0);
    
    
    
    int x = 0;
    char* p = 0x400008;
    
    while (1)
    {
        
        if (p[x] == 15)
        {   
            p[x] = 0x0;
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

char strCMP(char* x, char* y)
{
    int i = 0;
    while (x[i] != 0)
    {
        if (x[i] != y[i])
        {
            return 0;
        }
        i = i + 1;
    }
    return 1;
    
}

char* mallocSpot = 0x20000;
char* malloc(int space)
{
    char* temp = (char*) mallocSpot;
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

int stringToInt(char* word)
{
    int num = 0;
    int x = 0;
    char negative = 0;
    while (word[x] != 0)
    {
       
       if (word[x] == '0')
        {
            num = (num * 10) + 0;
        }
        else if (word[x] == '1')
        {
            num = (num * 10) + 1;
        }
        else if (word[x] == '2')
        {
            num = (num * 10) + 2;
        }
        else if (word[x] == '3')
        {
            num = (num * 10) + 3;
        }
        else if (word[x] == '4')
        {
            num = (num * 10) + 4;
        }
        else if (word[x] == '5')
        {
            num = (num * 10) + 5;
        }
        else if (word[x] == '6')
        {
            num = (num * 10) + 6;
        }
        else if (word[x] == '7')
        {
            num = (num * 10) + 7;
        }
        else if (word[x] == '8')
        {
            num = (num * 10) + 8;
        }
        else if (word[x] == '9')
        {
            num = (num * 10) + 9;
        }
        else if (word[x] == '-')
        {
            negative = 1;
        }
       
       
        x = x + 1;
    }
    if (negative)
    {
        return -1 * num;
    }
    return num;
    
}

void clearScreen()
{
    __asm__ __volatile__ ("int $51");
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

char* intToString(int i)
{   
    //negative case
    char negative = 0;
    if (i < 0)
    {
        i = i * -1;
        negative = 1;
    }
    
    char* word = malloc(lenOfInt(i)+1);
    int x = 0;
    while (i > 0)
    {
        word[x] = oneLetterIntLookUp(i % 10);
        x = x+1;
        i = i /10;
    }
    word[x] = 0;
    word = flipString(word, x);
    if (negative)
    {
        
        char* w = stringMalloc(lenOfInt(i)+2);
        w[0] = '-';
        w[lenOfInt(i)+1] = 0;
        int x = 0;

        while (word[x] != 0)
        {
            w[x+1] = word[x];
            x = x + 1;
        }
        return w;
        
    }
    return word;


}
int lenOfInt(int w)
{
    int x = 0;

    while (w > 0)
    {
        w = w /10;
        x = x + 1;
    }
    return x;
    
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
int lenOfHexInt(int w)
{
    int x = 0;

    while (w > 0)
    {
        w = w /16;
        x = x + 1;
    }
    return x;
}
char* flipString(char* s, int len)
{
    //len not including ending 0
    
    
    
    
    
    
    char* replacmentS =  malloc(len+1);
    int i;
    
    for (i =0;i < len;i++)
    {
        
        replacmentS[len-1 -i] = *(s+i);



    }
    replacmentS[len] = 0x0;
    return replacmentS;
    
}

int lenOfString(char* w)
{
    int x = 1;

    while (w[x-1] != 0)
    {
        x = x + 1;
    }
    return x;
    
    
}