#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE_SIZE 16
#define BUFFER_SIZE (1024 * 64 * LINE_SIZE)

void hexdump(FILE *input, FILE *output) {

    if(input == NULL || output == NULL) {
        printf("Error!");
        return;
    }

    char *bytes = (char*) malloc(BUFFER_SIZE);
    char text[LINE_SIZE + 3];
    memset(text, ' ', 2);
    text[LINE_SIZE + 2] = 0;
    unsigned int bufferCounter = 0;
    int lineNumber = 0;
    unsigned int i = 0;
    bool printRest = false;
    while((bufferCounter = fread(bytes, 1, BUFFER_SIZE, input))) {
        printRest = true;
        for(i = 0; i < bufferCounter; ++i) {
            if(i % LINE_SIZE == 0) {
                if (i != 0) {
                    fprintf(output, "%s\n", text);
                }

                fprintf(output, "%06x : ", LINE_SIZE * lineNumber++);
            }
            fprintf(output, "%02x ", (unsigned)(unsigned char)bytes[i]);
            if (bytes[i] >= 0x20 && bytes[i] <= 0x7e) {
                text[2 + i % LINE_SIZE] = bytes[i];
            } else {
                text[2 + i % LINE_SIZE] = '.';
            }
        }
    }


    if(printRest) {
        i = i % LINE_SIZE == 0 ? 16 : i % LINE_SIZE;
        text[2 + i] = 0;
        for(; i < LINE_SIZE; ++i) {
            fprintf(output, "   ");
        }
       fprintf(output, "%s\n", text);
    }

    free(bytes);  
}
