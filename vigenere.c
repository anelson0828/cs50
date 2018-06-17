// Vigenere

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


//first the user will use the command line to enter the key they would like to use for their cryptography

int main(int argc, string argv[])
{
    string k = argv[1];
    int i, s, plainlength, keylength;

    if (argc == 1) //Produce error
    {
        printf("Error Incorrect argument");
        return 1;
    }
    for (int c = 0, d = strlen(k); c < d; c++) //Check that each character is alpha, otherwise produce error
    {
        if (!isalpha(k[c]))
        {
            printf("Error Incorrect argument");
            return 1;
        }
    }
    //once you have your k or encryption code, get the plaintext

    string p = get_string("plaintext: ");
    printf("ciphertext: ");

    //use modulo to wraparound the key word

    for (i = 0, s = 0, plainlength = strlen(p), keylength = strlen(k); i < plainlength; i++) //iterate over number of chars in input 's'
    {
        if (isalpha(p[i])) //check if char is alpha
        {
            if (isupper(p[i])) //if char is uppercase
            {
                printf("%c", (p[i] - 'A' + toupper(k[s]) - 'A') % 26 + 'A');
            }
            if (islower(p[i])) //if char is lowercase
            {
                printf("%c", (p[i] - 'a' + toupper(k[s]) - 'A') % 26 + 'a');
            }
            s = (s + 1) % keylength; //wraparound the key
        }
        else //if char is not alpha, print as entered
        {
            printf("%c", p[i]);
        }
    }
    printf("\n");

}

