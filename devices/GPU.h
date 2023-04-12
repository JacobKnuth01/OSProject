#ifndef GPUH
#define GPUH


#define va 0xb8000
#define maxR 24
#define maxC 79


void writeChar(char l, int row, int col);
void writeString(char* string, int row, int col);
void clearScreen();
void blank();

#endif