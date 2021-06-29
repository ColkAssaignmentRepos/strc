//
// Created by Manaki ITO on 2021/06/29.
//
#include <stdio.h>

#define STRING_LENGTH 4096

size_t mystrlen(const char *s);


int main(void) {
    char char_array[STRING_LENGTH];

    scanf("%s", char_array);
    printf("LENGTH: %ld\n", mystrlen(char_array));

    return 0;
}


size_t mystrlen(const char *s) {
    size_t count = 0;

    while (s[count] != '\0') {
        count++;
    }

    return count;
}
