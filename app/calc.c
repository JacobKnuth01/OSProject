
#include "stdlib.h"
int main()
{   
    
    
  
    
    while (1)
    {
        /* code */
    
    
        print("Calculator",0, 0);
        print("num 1",1,0);
        char* num1 = input(1,6);
        print("num 2",2,0);
        char* num2 = input(2,6);
        print("operator (+, -, *, /):",3,0 );
        char* op = input(3,24);
        print("=",4,0);

        
        if (strCMP("-", op))
        {
            int num3 = stringToInt(num1);
            int num4 = stringToInt(num2);

            int r = num3 - num4;

            char* finalR = intToString(r);
            print(finalR, 4,2);
            

            
        }
        else if (strCMP("+", op))
        {
            int num3 = stringToInt(num1);
            int num4 = stringToInt(num2);

            int r = num3 + num4;

            char* finalR = intToString(r);
            print(finalR, 4,2);
        }
        else if (strCMP("*", op))
        {
            int num3 = stringToInt(num1);
            int num4 = stringToInt(num2);

            int r = num3 * num4;

            char* finalR = intToString(r);
            print(finalR, 4,2);
        }

        else if (strCMP("/", op))
    {
        int num3 = stringToInt(num1);
        int num4 = stringToInt(num2);

        int r = num3 / num4;

        char* finalR = intToString(r);
        print(finalR, 4,2);
    }
        input(5,0);
        clearScreen();
    }




    



    
    
    


    
    

    

    




    

   
   
    
    

    return 0;
}




