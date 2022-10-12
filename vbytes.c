#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: vbytes filename\n");
        return 1;
    }
    
    FILE *fp;
    if((fp = fopen(argv[1], "rb")) == NULL) {
        fprintf(stderr, "Error opening file %s.\n", argv[1]);
        return 2;
    }

    int c, i = 0, ln_break = 1;
    printf("\n");
    while ((c = fgetc(fp)) != EOF) {
        printf("%02x ", (unsigned char)c);
        if (++i % 16 == 0) {
            printf("\n\n");
            ln_break = 0;
        }
        else
            ln_break = 1;
    }
    if (ln_break)
        printf("\n\n");
    
    fclose(fp);
}