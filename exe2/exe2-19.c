//
// Created by Manaki ITO on 2021/06/29.
//
#include <stdio.h>

#define BUFFER_LENGTH 4096
#define CHAR_EXCEPTIONS "0123456789"
#define NUM_OF_EXCEPTIONS 10

int is_char_in_query(char character, char query);


int main(void) {
    char str[BUFFER_LENGTH];

    scanf("%s", str);

    long long int i = 0;
    int is_exception_char;
    while (str[i] != '\0') {
        is_exception_char = 0;

        for (long long int j = 0; j < NUM_OF_EXCEPTIONS; j++) {
            if (is_char_in_query(str[i], CHAR_EXCEPTIONS[j])) {
                is_exception_char = 1;
                break;
            }
        }

        if (is_exception_char == 0) {
            printf("%c", str[i]);
        }

        i++;
    }

    putchar('\n');
    return 0;
}


int is_char_in_query(char character, char query) {
    if (character == query) {
        return 1;
    }

    return 0;
}
