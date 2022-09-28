#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
        if (argc != 2)
        {
            printf("Usage:./caserar key\n");
            return 1;
        }


        for (int i = 0, len = strlen(argv[1]); i < len; i++)
        if (isdigit(argv[1][i]))
        {
        }
        else
        {
            printf("Usage:./caserar key\n");
            return 1;
        }

        int ar = atoi(argv[1]);

        string plnt = get_string("plaintext: ");
        printf ("ciphertext: ");

    for (int i = 0, ln = strlen(plnt); i < ln; i++)
        if (isalpha(plnt[i]))
        {
                    if (isupper(plnt[i]))
                  {
                        char c = (((plnt[i] - 65) + ar) % 26 + 65);
                        printf("%c", c);
                  }
                    if (islower(plnt[i]))
                    {
                        char c = (((plnt[i] - 97) + ar) % 26 + 97);
                        printf("%c", c);
                    }
        }
        else
        {
            printf("%c", plnt[i]);
        }
printf("\n");
}
