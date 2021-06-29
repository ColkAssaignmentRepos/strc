//
// Created by Manaki ITO on 2021/06/29.
//
#include <stdio.h>

#define STRING_LENGTH 25
#define STRING_CONTENT "oiibkayrrawkqiykpoasjebn"


int main(void) {
    char char_array[STRING_LENGTH] = STRING_CONTENT;

    for (int i = 0; i < STRING_LENGTH - 1; i++) {
        // その数より1大きい数が偶数なら、その数は必ず奇数である
        if ((i+1) % 2 == 0) {
            putchar(char_array[i]);
        }
    }

    putchar('\n');

    return 0;
}
