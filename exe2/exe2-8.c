//
// Created by Manaki ITO on 2021/06/29.
//
#include <stdio.h>

#define STRING_LENGTH 8
#define STRING_CONTENT "ibaraki"


int main(void) {
    char char_array[STRING_LENGTH] = STRING_CONTENT;

    for (int i = 0; i < STRING_LENGTH - 1; i++) {
        putchar(char_array[i]);
        putchar('/');
    }

    putchar('\n');

    return 0;
}
