#include "helpers.h"

void colorize(int height, int width, RGBTRIPLE image[height][width])
{
    // Change all black pixels to a color of your choosing
    int c = 0;
    for(int i = 0;i < height;i++)
    {
        for(c = 0;c < width;c++)
        {
            while(image[c][i].rgbtBlue == 0)
            {
                image[c][i].rgbtBlue = 100;
                image[c][i].rgbtRed = 100;
                image[c][i].rgbtGreen = 100;
            }
        }
    }
}
