//
// Created by Manaki ITO on 2021/06/29.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_LENGTH 4096
#define CHAR_QUERIES "0123456789"
#define NUM_OF_QUERIES 10

#define print_error(...) {fprintf(stderr, "\x1b[31m"); fprintf(stderr, __VA_ARGS__); fprintf(stderr, "\x1b[39m\n");}
#define fatal_with_message(exit_code, ...) {print_error(__VA_ARGS__); exit(exit_code);}

long long int count_char_in_string(char *string, char query);


int main(void) {
    char str[BUFFER_LENGTH];
    long long int *results = NULL;

    results = (long long int *) malloc(sizeof(long long int) * NUM_OF_QUERIES);
    if (results == NULL) {
        fatal_with_message(1,
                           "[X] Unexpected error in %s(): Failed to allocate memory.\n",
                           __func__);
    }

    scanf("%s", str);
    fflush(stdin);
    putchar('\n');

    for (long long int i = 0; i < NUM_OF_QUERIES; i++) {
        results[i] = count_char_in_string(str, CHAR_QUERIES[i]);
    }

    for (long long int i = 0; i < NUM_OF_QUERIES; i++) {
        printf("Number of '%lld' in the string: %lld\n", i, results[i]);
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
