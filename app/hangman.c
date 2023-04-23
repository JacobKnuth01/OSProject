#include "stdlib.h"
void printMan(int lives);
void J();
void head();
void torso();
void arms();
void legs();

int main()
{
    int lives = 5;
    print("please enter word for opponent to guess", 5, 25);
    char* word = input(6, 25);
    clearScreen();
    int wordL = lenOfString(word);
    char* remeberGuesses = malloc(wordL);
    print("guess:",5, 35);
    int temp = wordL-1;
    int y = 0;
    while (temp > 0)
    {
        print("-", 6, 42+y);
        temp = temp -1;
        y = y + 1;
    }
    
    while (lives > 0)
    {
        char* guess;
        while (1)
        {
            /* code */
        
        
            printMan(lives);
            print("guess a letter:", 8, 29);
             guess = input(8, 45);
            if (lenOfString(guess) > 2)
            {
                print("Only one letter!", 9, 45);
                
                int temp = lenOfString(guess);
                while (temp > 0)
                {
                    print(" ", 8, 45+lenOfString(guess) - temp);
                    temp = temp -1;
                }
                

            }
            else
            {
                print("                ", 9, 45);
                break;
            }

        }
        //check to see if guess is in word
        int x = 0;
        char found = 0;
        while (word[x] != 0)
        {
            if (word[x] == guess[0])
            {
                print(guess, 5, 42+x);
                remeberGuesses[x] = guess[0];
                found = 1;
                
            }
            x = x +1;
        }

        //check for win condition
        if (strCMP(word, remeberGuesses))
        {
            print("You WON!", 4, 30);
            break;
        }
        //check if minus a point
        if (!found)
        {
            lives = lives -1;
            printMan(lives);
        }
        
        


        
    }
    input(20,30);
    clearScreen();
    main();
    

    return 0;
}

void J()
{
     print("---------", 0, 0);
        int x = 0;
        while (x < 20)
        {
            if (x <2)
            {
                print("|",x+1, 8 );
            }
            print("|",x+1, 0 );
            x =x +1;
        }
        
        print("----", x+1, 0);
}
void torso()
{
    int x = 0;
    while (x < 4)
    {
        print("|", x+7,8);
        x = x +1;
    }
       
    
}
void head()
{
    print("---",3,7 );
    print("| |",4,7 );
    print("| |",5,7 );
    print("---",6,7 );
}
void arms()
{
    print("-----",8,6);
}
void legs()
{
    print("-----", 11,6);
    print("|   |", 12,6);
    print("|   |", 13,6);
    print("|   |", 14,6);
    print("|   |", 15,6);
}


void printMan(int lives)
{

    if (lives == 5)
    {
       J();
       
    }
    else if (lives == 4)
    {
        
        head();
    }
    else if (lives == 3)
    {
        torso();
    }
    else if (lives == 2)
    {
        arms();
    }
    else if (lives == 1)
    {
        legs();
    }
    else if (lives == 0)
    {
        //lose
        print("YOU LOST :(", 3, 20);
    }

}

