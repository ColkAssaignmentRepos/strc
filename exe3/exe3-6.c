//
// Created by Manaki ITO on 2021/06/29.
//
#include <stdio.h>
#include <string.h>

#define STRING_LENGTH 13

char *mystrcat(char *s1, char *s2);

size_t mystrlen(const char *s);


int main(void) {
    char str1[STRING_LENGTH] = "ibaraki";
    char str2[STRING_LENGTH] = "kosen";

    mystrcat(str1, str2);

    printf("str1:\n%s\n", str1);

    return 0;
}


char *mystrcat(char *s1, char *s2) {
    long long int s1_terminal_char_index = mystrlen(s1);
    long long int s2_terminal_char_index = mystrlen(s2);

    memcpy(&s1[s1_terminal_char_index], s2, sizeof(char) * (s2_terminal_char_index + 1));

    return s1;
}


size_t mystrlen(const char *s) {
    size_t count = 0;

    while (s[count] != '\0') {
        count++;
    }

    return count;
}
