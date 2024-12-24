#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "wav.h"

int check_format(WAVHEADER header);
int get_block_size(WAVHEADER header);

int main(int argc, char *argv[])
{
    if(argc != 3 || strcmp(argv[2],"input.wav"))
    {
        printf("Usage: ./reverse input.wav output.wav");
    }
    char *filename = argv[2];
    char *out = argv[3];
    // Ensure proper usage
    // TODO #1
    FILE *file = fopen(filename,"r");
    if(file == NULL)
    {
        return 1;
    }

    // Open input file for reading
    // TODO #2
    WAVHEADER head;
    fread(&head,sizzeof(WAVHEADER),1,file);

    // Read header
    // TODO #3

    if (check_format == 0)
    {
        fclose(file);
        return 1;
    }

    // Use check_format to ensure WAV format
    // TODO #4
    char *outfile = argv[3];
    FILE fopen(outfile,"r");


    // Open output file for writing
    // TODO #5
    fwrite(&head,sizeof(WAVHEADER),1,outfile);

    // Write header to file
    // TODO #6
    int i = get_block_size(head);


    // Use get_block_size to calculate size of block
    // TODO #7
    int m;
    int a[i];
    long l = ftell(file);
    do
    {
        m = fseek(file,-i,SEEK_END);
        if(m != 0)
        {
            fclose(head);
            fclose(outfile);
            return 1;
        }
        fread(a,4,i,head);
        fwrite(a,4,i,outfile);
    }
    while(m >= l)
    fclose(file);
    fclose(outfile);







    // Write reversed audio to file
    // TODO #8
}

int check_format(WAVHEADER header)
{
    if(header.(format[4]) == "wave")
    {
        return 1;
    }else{
    // TODO #4
    return 0;
    }
}

int get_block_size(WAVHEADER header)
{
    return (header.numChannels * header.bitsPerSample / 4);
    // TODO #7
}
