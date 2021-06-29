//
// Created by Manaki ITO on 2021/06/29.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define STRING_LENGTH 8

#define print_error(...) {fprintf(stderr, "\x1b[31m"); fprintf(stderr, __VA_ARGS__); fprintf(stderr, "\x1b[39m\n");}
#define fatal_with_message(exit_code, ...) {print_error(__VA_ARGS__); exit(exit_code);}

size_t mystrlen(const char *s);

char *mystrcpy(char *s1, char *s2);


int main(void) {
    char str1[STRING_LENGTH] = "ibaraki";
    char str2[STRING_LENGTH] = "kosen";

    mystrcpy(str1, str2);

    printf("str1:\n%s\n", str1);

    return 0;
}


char *mystrcpy(char *s1, char *s2) {
    long long int s1_terminal_char_index = mystrlen(s1);
    long long int s2_terminal_char_index = mystrlen(s2);

    if (s1_terminal_char_index == -1 || s2_terminal_char_index == -1) {
        fatal_with_message(1,
                           "[X] Unexpected error in %s(): No null character found in the strings.\n",
                           __func__);
    }
    if (s1_terminal_char_index < s2_terminal_char_index) {
        fatal_with_message(1,
                           "[X] Unexpected error in %s(): You tried to copy bigger length string to smaller one.\n",
                           __func__);
    }

    memcpy(s1, s2, sizeof(char) * (s2_terminal_char_index + 1));

    return s1;
}


size_t mystrlen(const char *s) {
    size_t count = 0;

    while (s[count] != '\0') {
        count++;
    }

    return count;
}
