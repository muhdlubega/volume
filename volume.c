// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Number of bytes in .wav header
const int HEADER_SIZE = 44;

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open files and determine scaling factor
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    float factor = atof(argv[3]);

    // TODO: Copy header from input file to output file
    // Create array with HEADER_SIZE bytes to store bytes from the WAV file header
    uint8_t header[HEADER_SIZE];

    // Read the input file and write into output file with the appropriate number of bytes
    fread(header, HEADER_SIZE, 1, input);
    fwrite(header, HEADER_SIZE, 1, output);

    // TODO: Read samples from input file and write updated data to output file
    // Create a buffer variable to store audio samples read from the WAV file
    int16_t buffer;

    // Initiate sequence basd of buffer variable for the input file
    while (fread(&buffer, sizeof(int16_t), 1, input))
    {
        // Multiply the buffer variable with the factor given in the argument to get the appropriate adjustment
        buffer = buffer * factor;
        // Write output file based off the adjustment given to the buffer variable
        fwrite(&buffer, sizeof(int16_t), 1, output);
    }

    // Close files
    fclose(input);
    fclose(output);
}