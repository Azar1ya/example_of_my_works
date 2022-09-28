#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
if (argc != 2)
{
    printf("Usage: ./recover name\n");
    return 1;
}

FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("Could not open the file");
        return 2;
    }

    unsigned char buffer[512];
    int count = 0;
    FILE *ofile = NULL;
    char *filename = malloc(8 * sizeof(char));

    while(fread(buffer, sizeof(char), 512, file))
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0 )
        {
        sprintf(filename, "%03i.jpg", count);
        ofile = fopen(filename, "w");
        count++;
        }
        if (ofile != NULL)
        {
        fwrite(buffer, sizeof(char), 512, ofile);
        }
        }
    free(filename);
    fclose(file);
    fclose(ofile);
    return 0;
}