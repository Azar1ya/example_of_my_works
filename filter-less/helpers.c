#include "helpers.h"
#include "math.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float Red = image[i][j].rgbtRed;
            float Green = image[i][j].rgbtGreen;
            float Blue = image[i][j].rgbtBlue;

            int average = round((Red + Green + Blue) / 3);
            image[i][j].rgbtRed = image[i][j].rgbtGreen = image[i][j].rgbtBlue = average;
        }
    }

    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float oRed = image[i][j].rgbtRed;
            float oGreen = image[i][j].rgbtGreen;
            float oBlue = image[i][j].rgbtBlue;

            int sepRed = round(0.393 * oRed + 0.769 * oGreen + 0.189 * oBlue);
            int sepGreen = round(0.349 * oRed + 0.686 * oGreen + 0.168 * oBlue);
            int sepBlue = round(0.272 * oRed + 0.534 * oGreen + 0.131 * oBlue);

            if (sepRed > 255)
            {
                sepRed = 255;
            }
            if (sepGreen > 255)
            {
                sepGreen = 255;
            }
            if(sepBlue > 255)
            {
                sepBlue = 255;
            }
            image[i][j].rgbtRed = sepRed;
            image[i][j].rgbtGreen = sepGreen;
            image[i][j].rgbtBlue = sepBlue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - (j + 1)];
            image[i][width - (j+1)] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
        for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j];
        }
    }

        for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int TG, TB, TR;
            TG = TB = TR = 0;
            float counter = 0.00;

        for (int x = -1; x < 2; x++)
          {
        for (int y = -1; y < 2; y++)
        {
            int currX = i + x;
            int currY = j + y;

            if (currX < 0 || currY < 0 || currX > (height - 1) || currY > (width - 1))
            {
                continue;
            }
            TR += image[currX][currY].rgbtRed;
            TG += image[currX][currY].rgbtGreen;
            TB += image[currX][currY].rgbtBlue;

            counter++;
        }
    temp[i][j].rgbtRed = round(TR / counter);
    temp[i][j].rgbtGreen = round(TG / counter);
    temp[i][j].rgbtBlue = round(TB / counter);
            }
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
    image[i][j].rgbtRed = temp[i][j].rgbtRed;
    image[i][j].rgbtGreen = temp[i][j].rgbtGreen;
    image[i][j].rgbtBlue = temp[i][j].rgbtBlue;
        }
    }
    return;
}