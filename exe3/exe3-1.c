//
// Created by Manaki ITO on 2021/06/29.
//
#include <stdio.h>
#include <string.h>

#define STRING_LENGTH 4096


int main(void) {
    char char_array[STRING_LENGTH];

    scanf("%s", char_array);
    printf("LENGTH: %ld\n", strlen(char_array));

    return 0;
}
