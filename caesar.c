#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

//check the number of arg
int main(int argc, string argv[])
{
    int strLenghth = strlen(argv[1]);
    int key = atoi(argv[1]);
    int n = 0;
    //if the number of arg is not 2, show instruction
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    //check if the 2nd arg contains only digits
    else
    {
        for (int i = 0; i < strLenghth; i++)
        {
            if (isdigit(argv[1][i]))
            {
                n++;
            }
        }
        
        if (n == strLenghth)
        {   
            string plainText = get_string("plaintext: "); //prompt for plaintext as string
            for(int i = 0, j = strlen(plainText); i < j; i++) 
            {
                if (isupper(plainText[i])) //cipher uppercase
                {
                    printf("%i", (plainText[i] + key - 'A') % 26 + 'A');
                }
                else if (islower(plainText[i])) //cipher lowercase
                {
                    printf("%i", (plainText[i] + key - 'a') % 26 + 'a'); 
                }
                else //print out everything else
                {
                    printf("%i", plainText[i]); 
                }
            }
            printf("\n");
            return 0;
        }
        //if the 2nd arg contains other things than digits, show instruction
        else 
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
    
}
