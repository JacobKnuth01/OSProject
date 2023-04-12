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

char singleHexToAcii(char hex)
{
    if (hex == 0x0)
    {
        return '0';
    }
    else if (hex == 0x1)
    {
        return '1';
    }
    else if (hex == 0x2)
    {
        return '2';
    }
    else if (hex == 0x3)
    {
        return '3';
    }
    else if (hex == 0x4)
    {
        return '4';
    }
    else if (hex == 0x5)
    {
        return '5';
    }
    else if (hex == 0x6)
    {
        return '6';
    }
    else if (hex == 0x7)
    {
        return '7';
    }
    else if (hex == 0x8)
    {
        return '8';
    }
    else if (hex == 0x9)
    {
        return '9';
    }
    else if (hex == 0xA)
    {
        return 'A';
    }
    else if (hex == 0xB)
    {
        return 'B';
    }
    else if (hex == 0xC)
    {
        return 'C';
    }
    else if (hex == 0xD)
    {
        return 'D';
    }
    else if (hex == 0xE)
    {
        return 'E';
    }
    else if (hex == 0xF)
    {
        return 'F';
    }
    else
    {
        return 'N';
    }

}


char* hexToString(char hex)
{
    char one = singleHexToAcii(high_4(hex));
    char two = singleHexToAcii(low_4(hex));

   
    static char final[3] = {0x0, 0x0, 0x0};

    memory_copy(&one, &final[0], 1);
    memory_copy(&two, &final[1], 1);

    

    
    return final; 

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