//
// Created by Manaki ITO on 2021/06/29.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_LENGTH 4096
#define QUERY_CHAR 'b'

#define print_error(...) {fprintf(stderr, "\x1b[31m"); fprintf(stderr, __VA_ARGS__); fprintf(stderr, "\x1b[39m\n");}
#define fatal_with_message(exit_code, ...) {print_error(__VA_ARGS__); exit(exit_code);}

long long int count_char_in_string(char *string, char query);


int main(void) {
    char str[BUFFER_LENGTH];
    long long int number_of_founds;
    long long int *found_indexes = NULL;

    scanf("%s", str);
    number_of_founds = count_char_in_string(str, QUERY_CHAR);

    if (number_of_founds <= 0) {
        printf("No '%c' found in the string.\n", QUERY_CHAR);
    }
    else {
        printf("Found %lld '%c'(s) in the string.\n", number_of_founds, QUERY_CHAR);
    }

    return 0;
}


long long int count_char_in_string(char *string, char query) {
    long long int i = 0;
    long long int count = 0;

    while (string[i] != '\0') {
        if (string[i] == query) {
            count++;
        }

        i++;
    }

    return count;
}
