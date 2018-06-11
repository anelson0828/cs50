// caesar

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int k, num_of_char;

//first the user will use the command line to enter the key they would like to use for their cryptography

int main(int argc, string argv[])
{
    if (argc == 1 || argc > 2) //Produce error
    {
        printf("Error Incorrect argument");
        return 1;
    }
    k = atoi(argv[1]);
    if (k >= 0)

        //then prompt the user for what they would like to use for their plaintext

    {
        printf("plaintext: ");
    }
    string s = get_string();
    num_of_char = strlen(s);

    //check if each item inside the array is a alpha, and whether it's uppercase or lower case

    printf("ciphertext: ");

    for (int i = 0; i < num_of_char; i++) //iterate over number of chars in input 's'
    {
        if (isalpha(s[i])) //check if char is alpha
        {
            if (isupper(s[i])) //if char is uppercase
            {
                int plain_letter = (int) s[i] - 65; //convert to alphabetic
                int cipher_letter = ((plain_letter + k) % 26) + 65; //encrypt with K and change back to ASCII
                printf("%c", (char) cipher_letter);
            }

            if (islower(s[i])) //if char is lowercase
            {
                int plain_letter = (int) s[i] - 97; //convert to alphabetic
                int cipher_letter = ((plain_letter + k) % 26) + 97; //encrypt with K and change back to ASCII
                printf("%c", (char) cipher_letter);
            }
        }
        else //if char is not alpha, print as entered
        {
            printf("%c", s[i]);
        }
    }
    printf("\n");
    return 0;

}

