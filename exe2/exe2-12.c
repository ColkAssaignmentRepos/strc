//
// Created by Manaki ITO on 2021/06/29.
//
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>

#define STRING_NUMBER 3
#define STRING_CONTENT_1 "Hello"
#define STRING_CONTENT_2 "Goodbye"
#define STRING_CONTENT_3 "Thankyou"

#define print_error(...) {fprintf(stderr, "\x1b[31m"); fprintf(stderr, __VA_ARGS__); fprintf(stderr, "\x1b[39m\n");}
#define fatal_with_message(exit_code, ...) {print_error(__VA_ARGS__); exit(exit_code);}

char **malloc_char_matrix(long long int row_length);


int main(void) {
    char **char_matrix = NULL;
    char_matrix = malloc_char_matrix(STRING_NUMBER);

    char_matrix[0] = STRING_CONTENT_1;
    char_matrix[1] = STRING_CONTENT_2;
    char_matrix[2] = STRING_CONTENT_3;

    for (long long int i = 0; i < STRING_NUMBER; i++) {
        printf("%s", char_matrix[i]);

        if (i != STRING_NUMBER - 1) {
            printf(", ");
        }
    }
    putchar('\n');

    free(char_matrix);

    return 0;
}


char **malloc_char_matrix(long long int row_length) {
    char **result = NULL;
    result = (char **) malloc(sizeof(char *) * row_length);
    if (result == NULL) {
        fatal_with_message(1,
                           "[X] Unexpected error in %s(): Failed to allocate memory.\n",
                           __func__);
    }

    return result;
}
