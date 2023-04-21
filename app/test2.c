char* input(int row, int col);
void print(char*message, int rrow, int ccol);
int main()
{
    print("we made it ",0, 0);
    
    char* j = input(6,3);
    print(j, 8, 6);    

   while (1)
   {
    /* code */
   }
   
    
    

    return 0;
}

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
    static char saved[20];
    x = 0;
    while (pp[x] != 0)
    {
        saved[x] = pp[x];
        x = x +1;
    }
    saved[x] = 0;
    
    return &saved;

    __asm__ __volatile__ ("int $48");
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



