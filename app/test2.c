
void print(char*message, int rrow, int ccol);
int main()
{
    print("we made it ",0, 0);
    
    
    int* pr = 0x400000;
    int * pc = 0x400004;
    
    *pr = 4;
    *pc = 0;

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

    //__asm__ __volatile__ ("int $48");

   
    
    

    return 0;
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



