#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;
    printf("What's hight of a pyramid?\n");
    do
    {
        n = get_int("Height: ");
    }
    while (n > 8 || n < 1);

    //for hight
    for (int i = 0; i < n; i++)
    {
        //for collumn (left part)
        for (int j = 0; j <= n; j++)
        {
            if (j <= n - 1 && j >= n - (i+1))
            {
                printf("#");
            }
            else
            {
                printf(" ");
            }
        }
        {
            //dots in the middle
            printf(" ");
        }
        //right part
        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }
        {
            printf("\n");
        }
    }
}