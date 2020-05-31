#include "func.h"
#include <stdio.h>

int main(int argc, char* argv[])
{
    if (argc == 2) {
        read_file(argv[1]);
    } else {
        return -1;
    }

    char str[100] = "ssss";
    char* s = sdup(str);
    printf("%s\n", s);

    return 0;
}
