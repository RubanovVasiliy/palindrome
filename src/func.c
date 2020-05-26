#include <stdio.h>

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
    printf("%ld\n", size);

    return 0;
}
