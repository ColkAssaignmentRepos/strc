//
// Created by Manaki ITO on 2021/06/29.
//
#include <stdio.h>

#define STRING_LENGTH 10
#define STRING_CONTENT "ITOManaki"


int main(void) {
    char char_array[STRING_LENGTH] = STRING_CONTENT;

    for (int i = STRING_LENGTH - 1; i >= 0; i--) {
        putchar(char_array[i]);
    }

    putchar('\n');

    return 0;
}
