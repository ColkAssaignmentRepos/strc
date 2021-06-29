//
// Created by Manaki ITO on 2021/06/29.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_LENGTH 4096
#define QUERY_CHAR 'a'

#define print_error(...) {fprintf(stderr, "\x1b[31m"); fprintf(stderr, __VA_ARGS__); fprintf(stderr, "\x1b[39m\n");}
#define fatal_with_message(exit_code, ...) {print_error(__VA_ARGS__); exit(exit_code);}

long long int count_char_in_string(char *string, char query);

long long int find_char(char *string, char query, long long int start_lookup_from_index);


int main(void) {
    char str[BUFFER_LENGTH];
    long long int number_of_founds;
    long long int *found_indexes = NULL;

    scanf("%s", str);
    number_of_founds = count_char_in_string(str, QUERY_CHAR);

    found_indexes = (long long int *) malloc(sizeof(long long int) * number_of_founds);
    if (found_indexes == NULL) {
        fatal_with_message(1,
                           "[X] Unexpected error in %s(): Failed to allocate memory.\n",
                           __func__);
    }

    for (long long int i = 0; i < number_of_founds; i++) {
        if (i == 0) {
            found_indexes[i] = find_char(str, QUERY_CHAR, 0);
            continue;
        }

        found_indexes[i] = find_char(str, QUERY_CHAR, found_indexes[i - 1] + 1);
    }

    int is_found_index;
    for (long long int i = 0; i < strlen(str); i++) {
        is_found_index = 0;

        for (long long int j = 0; j < number_of_founds; j++) {
            if (i == found_indexes[j]) {
                is_found_index = 1;
                break;
            }
        }

        if (is_found_index) {
            putchar('^');
        } else {
            putchar(' ');
        }
    }
    putchar('\n');

    printf("Found '%c' at index:\n", QUERY_CHAR);
    for (long long int i = 0; i < number_of_founds; i++) {
        printf("%lld", found_indexes[i]);

        if (i != number_of_founds - 1) {
            printf(", ");
        }
    }

    putchar('\n');

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


long long int find_char(char *string, char query, long long int start_lookup_from_index) {
    long long int i = start_lookup_from_index;

    while (string[i] != '\0') {
        if (string[i] == query) {
            return i;
        }

        i++;
    }

    return -1;
}
