//
// Created by Manaki ITO on 2021/06/29.
//
#include <stdio.h>

#define STRING_LENGTH 10
#define STRING_CONTENT "ITOManaki"


int main(void) {
    char char_array[STRING_LENGTH] = STRING_CONTENT;

    int i = STRING_LENGTH - 1;
    while (i >= 0) {
        putchar(char_array[i]);
        i--;
    }

    putchar('\n');

    return 0;
}
