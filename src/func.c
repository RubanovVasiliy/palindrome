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

int min(int a, int b)
{
    if (a < b)
        return a;
    else
        return b;
}

void get_array(char* str, int p[])
{
    int n = slen(str), i;
    int c = 0, r = -1, rad;
    for (i = 0; i < n; i++) {
        if (i <= r) {
            rad = min((r - i), p[2 * c - i]);
        } else
            rad = 0;
        while (i + rad < n && i - rad >= 0 && str[i - rad] == str[i + rad])
            rad++;
        p[i] = rad - 1;
        if ((i + rad - 1) > r) {
            c = i;
            r = i + rad - 1;
        }
    }
}

int generate(char* str)
{
    int len = slen(str) * 2 + 1;
    char* mod = calloc(len, 1);
    int i = 0;
    int k = 0;
    for (i = 0; i < len; i++) {
        if (i % 2 == 0)
            mod[i] = '#';
        else {
            mod[i] = str[k];
            k++;
        }
    }

    mod[i] = '\0';
    printf("mod: %s\n", mod);
    printf("str: %s\n", str);

    int l = slen(mod);
    int p[l], temp, max = 2;
    int m = max;
    get_array(mod, p);

    for (i = 0; i < l; i++) {
        //printf(" %d %c\n", p[i], mod[i]);
        if (p[i] >= m) {
            m = p[i];
            temp = i;

            int t = temp / 2;
            char* s = sdup(str);
            s = s + t - (m / 2);
            s[m] = '\0';
            printf("%s\n", s);
            m = max;
        }
    }

    return 0;
}
