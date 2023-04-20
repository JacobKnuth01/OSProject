
void print(char*message, int rrow, int ccol);
int main()
{
    print("we made it ",0, 0);
    
    
    int* pr = 0x400000;
    int * pc = 0x400004;
    
    *pr = 4;
    *pc = 0;

    __asm__ __volatile__("int $49");
    
    
    //check to see if there has been an enter key

    char* input = 0x400008;
    char found = 0;
    input[0] = 0;
    while (!found)
    {
    

    }

    __asm__ __volatile__("int $2");
    
    

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



