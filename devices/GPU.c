#include "GPU.h"

void writeChar(char l, int row, int col)
{
    char* vm = (char*) va;
    int offset = 2*((row * (maxC+1)) +col);
    vm[offset] = l;
}

void writeString(char* string, int row, int col)
{
    int i = 0;
    
    while (string[i] != 0)
    {
        writeChar(string[i], row, col);

        i++;
        col++;
        
        if (col == 80)
        {
            row++;
            col = 0;
        }
    }
}

void clearScreen()
{
    char* vm = (char*) va;
    int i = 0;
    while (i <= maxC*maxR)
    {
        vm[i*2] = ' ';
        i = i + 1;
    }
    
}
void blank()
{
    
}