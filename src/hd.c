
#include <stdio.h>

void hexdump(FILE *input, FILE *output);

int main(int argc, char *argv[]) {
   for(int i = 1 ; i < argc; ++i) {
       if (i != 1) {
           fprintf(stdout, "\n");
       }
       FILE *input = fopen(argv[i], "rb");
       hexdump(input, stdout);
       fclose(input);
   }
    return 0;
}
