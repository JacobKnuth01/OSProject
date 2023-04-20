#define low_16(address) (unsigned short)((address) & 0xFFFF)
#define high_16(address) (unsigned short)(((address) >> 16) & 0xFFFF)
#define low_4(bbyte) (unsigned char) (bbyte & 0xF)
#define high_4(bbyte) (unsigned char) (bbyte >> 4)
 
extern void switchSegments();
//extern void ta();
//extern void taEnd();
extern void copyToUserSpace(unsigned int s, unsigned int d, int len);
extern void toUserSeg();
extern void toKernSeg();
extern char grabByte(int spot);
extern int grab32(int spot);

void memory_copy(unsigned char *s, unsigned char *d, int limit);
char singleHexToAcii(char hex);
char* hexToString(char hex);
char oneLetterIntLookUp(int i);
char* intToString(int i);
char* flipString(char* s, int len);
