//
// Created by Manaki ITO on 2021/06/29.
//
#include <stdio.h>
#include <string.h>

#define STRING_LENGTH 13


int main(void) {
    char str1[STRING_LENGTH] = "ibaraki";
    char str2[STRING_LENGTH] = "kosen";

    strcat(str1, str2);

    printf("str1:\n%s\n", str1);

    return 0;
}
