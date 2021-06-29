//
// Created by Manaki ITO on 2021/06/29.
//
#include <stdio.h>
#include <string.h>

#define STRING_LENGTH 8


int main(void) {
    int strcmp_result;
    char str1[STRING_LENGTH] = "ibaraki";
    char str2[STRING_LENGTH] = "kosen";

    strcmp_result = strcmp(str1, str2);

    printf("strcmp_result:\n%d\n", strcmp_result);

    return 0;
}
