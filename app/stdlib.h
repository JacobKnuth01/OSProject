char* input(int row, int col);
void print(char*message, int rrow, int ccol);


extern char* mallocSpot;
char* malloc(int space);
void copyString(char* source, char*destination);
char* stringMalloc(char* word);
int stringToInt(char* word);

char strCMP(char* x, char* y);
char* flipString(char* s, int len);
int lenOfHexInt(int w);
char oneLetterIntLookUp(int i);
int lenOfInt(int w);
char* intToString(int i);
void clearScreen();
int lenOfString(char* w);