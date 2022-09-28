#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main(void)
{
    string text = get_string("Text:");

float letter = 0;
    for (int i = 0, len = strlen(text); i < len; i++)
        if (isalpha(text[i]))
        {
            letter++;
        }

float word = 1;
    for (int i = 0, len = strlen(text); i < len; i++)
    if (isspace(text[i]))
    {
        word++;
    }

float sentence = 0;
    for (int i = 0, len = strlen(text); i < len; i++)
    if ((text[i]) == '!' || (text[i]) == '?' || (text[i]) == '.')
    {
        sentence++;
    }

    float L = letter / word * 100;
    float S = sentence / word * 100;
    double index = 0.0588 * L - 0.296 * S - 15.8;
    int ind = round (index);
    if (index <= 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)
        {
            printf("Grade 16+\n");
        }
        else
        {
            printf("Grade %i\n", ind);
        }
}