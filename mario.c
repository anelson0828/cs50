//mario half

#include <cs50.h>
#include <stdio.h>

int main(void)
//first get a value for the height

{
    int h;
    do
    {
        printf("Enter height for the pyramid (choose a number between 0 and 23)\n");
        h = get_int();
        if (h > 23)
        {
            printf("You must choose a number no more than 23\n");
        }
        if (h < 0)
        {
            printf("You must choose a number no less than 0\n");
        }
    }
    while (h < 0 || h > 23);

//now you have a valid height, make the pyramid with r number of rows, s number of spaces, and c number of

    for (int r = 0; r < h; r++)
    {
        for (int s = (h - 1); s > r; s--)
        {
            printf(" ");
        }
        {
            for (int c = 0; c < (r + 1); c++)
            {
                printf("#");
            }
        }
        {
            printf("  ");
        }
        {
            for (int c = 0; c < (r + 1); c++)
            {
                printf("#");
            }
        }
        {
            printf("\n");
        }
    }
}