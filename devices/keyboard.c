#include "../k/methods.h"
#include"../CPU/pipe.h"
#include "keyboard.h"
#include "GPU.h"

char capture = 0;
int col = -1;
int row = -1;

int userWordLocation = 0x400008;
int x = 0;
void kHandler()
{

    
    if (capture)
    {
        //maping generated with chatGPT
        char scan_to_ascii[256] = {0};
        // Map ASCII values for keys that have a corresponding ASCII value
        scan_to_ascii[0x01] = 'x'; // Escape key
        scan_to_ascii[0x02] = '1';
        scan_to_ascii[0x03] = '2';
        scan_to_ascii[0x04] = '3';
        scan_to_ascii[0x05] = '4';
        scan_to_ascii[0x06] = '5';
        scan_to_ascii[0x07] = '6';
        scan_to_ascii[0x08] = '7';
        scan_to_ascii[0x09] = '8';
        scan_to_ascii[0x0A] = '9';
        scan_to_ascii[0x0B] = '0';
        scan_to_ascii[0x0C] = '-';
        scan_to_ascii[0x0D] = '=';
        scan_to_ascii[0x0E] = 'x'; // Backspace key
        scan_to_ascii[0x0F] = 'x'; // Tab key
        scan_to_ascii[0x10] = 'q';
        scan_to_ascii[0x11] = 'w';
        scan_to_ascii[0x12] = 'e';
        scan_to_ascii[0x13] = 'r';
        scan_to_ascii[0x14] = 't';
        scan_to_ascii[0x15] = 'y';
        scan_to_ascii[0x16] = 'u';
        scan_to_ascii[0x17] = 'i';
        scan_to_ascii[0x18] = 'o';
        scan_to_ascii[0x19] = 'p';
        scan_to_ascii[0x1A] = '[';
        scan_to_ascii[0x1B] = ']';
        scan_to_ascii[0x1C] = 15; // Enter key
        scan_to_ascii[0x1D] = 'x'; // Left control key
        scan_to_ascii[0x1E] = 'a';
        scan_to_ascii[0x1F] = 's';
        scan_to_ascii[0x20] = 'd';
        scan_to_ascii[0x21] = 'f';
        scan_to_ascii[0x22] = 'g';
        scan_to_ascii[0x23] = 'h';
        scan_to_ascii[0x24] = 'j';
        scan_to_ascii[0x25] = 'k';
        scan_to_ascii[0x26] = 'l';
        scan_to_ascii[0x27] = ';';
        scan_to_ascii[0x28] = '\'';
        scan_to_ascii[0x29] = '`';
        scan_to_ascii[0x2A] = 'x'; // Left shift key
        scan_to_ascii[0x2B] = 'x';
        scan_to_ascii[0x2C] = 'z';
        scan_to_ascii[0x2D] = 'x';
        scan_to_ascii[0x2E] = 'c';
        scan_to_ascii[0x2F] = 'v';
        scan_to_ascii[0x30] = 'b';
        scan_to_ascii[0x31] = 'n';
        scan_to_ascii[0x32] = 'm';
        scan_to_ascii[0x33] = ',';
        scan_to_ascii[0x34] = '.';
        scan_to_ascii[0x35] = '/';
        scan_to_ascii[0x36] = 'x'; //right shift
        scan_to_ascii[0x37] = '*'; //keypad
        scan_to_ascii[0x38] = 'x'; //left alt
        scan_to_ascii[0x39] = ' ';
        scan_to_ascii[0x4E] = '+';
        int scancode = BIn(0x60);

        //writeString(hexIntToString(scancode), 6, 10);
        
        
        if ( (scancode >= 0x0 && scancode <= 0x39) || scancode == 0x4e)
        {
            //convert to ascii
            char ascii = scan_to_ascii[scancode];

            //get row and col from mem
            if (row == -1)
            {
                row = grab32(0x400000);
            }
            if (col == -1)
            {
                col = grab32(0x400004);
                x = 0;
            }

            //special keys
            //backspace
            if (scancode == 0x0e)
            {
                //go back unless its to far

                if (x > 0)
                {
                    col = col -1;
                    x = x -1;
                }
                
                //set ascii to blank
                ascii = ' ';

            }
            
            



            //display
            //if it is enter (i dont want the astrisc)

            if (ascii == 15)
            {
                writeChar(' ', row, col);
            }
            else
            {
                writeChar(ascii, row, col);
            }
            
            //save
            placeByte(userWordLocation+x, ascii);
            placeByte(userWordLocation+x+1, 0x0);
            
            
            

            //increment unless backspace
            if(scancode != 0x0e)
            {
                x = x +1;
                col = col +1;
            }
            

            
            
        
            
            

            
            
        }
        



    }
    
    
    
    


    


    
}