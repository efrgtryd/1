#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int i,j;
    for(i = 0,i < height,i++)
    {
        for(j = 0,j < width,j++)
        {
            image[i][j].rgbtblue = image[i][j].rgbtred = image[i][j].rgbtgreen = (image[i][j].rgbtblue + image[i][j].rgbtred + image[i][j].rgbtgreen)/3;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int i,j;
    RGBTRIPLE a;
    for(i = 0,i < height,i++)
    {
        for(j = 0,j < width/2,j++)
        {
             a.rgbtblue = image[i][j].rgbtblue;
             
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    int i,j;
    for(i = 0,i < height,i++)
    {
        for(j = 0,j < width,j++)
        {

        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    int i,j;
    for(i = 0,i < height,i++)
    {
        for(j = 0,j < width,j++)
        {

        }
    }
    return;
}
