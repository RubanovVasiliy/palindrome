#include "strings.h"
#include <stdio.h>
#include <stdlib.h>

int check_sym(char sym, char* incorrect)
{
    for (int i = 0; i < slen(incorrect); i++) {
        if (sym == incorrect[i]) {
            return -1;
        }
    }
    return 0;
}

int read_file(const char* in_file_name)
{
    FILE* in = fopen(in_file_name, "r");
    if (!in) {
        printf("Error %s\n", in_file_name);
        return -1;
    }

    unsigned long size = 0;
    fseek(in, 0, SEEK_END);
    size = ftell(in);

    char* input = calloc(size, 1);
    fseek(in, 0, SEEK_SET);
    int s = 0;

    for (int i = 0; i < size; i++) {
        char c = fgetc(in);
        if (!check_sym(c, incorrect_sym)) {
            input[s] = c;
            s++;
        }
    }

    input[s] = '\0';
    input = (char*)realloc(input, slen(input));

    printf("%s\nlen:%ld\n", input, slen(input));

    return 0;
}
