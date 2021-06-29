//
// Created by Manaki ITO on 2021/06/29.
//
#include <stdio.h>
#include <stdlib.h>

#define STRING_NUMBER 3
#define BUFFER_LENGTH 4096

#define print_error(...) {fprintf(stderr, "\x1b[31m"); fprintf(stderr, __VA_ARGS__); fprintf(stderr, "\x1b[39m\n");}
#define fatal_with_message(exit_code, ...) {print_error(__VA_ARGS__); exit(exit_code);}

char **malloc_char_matrix(long long int row_length);

void char_matrix_free(char **target, long long int row_length);


int main(void) {
    char **char_matrix = NULL;
    char *buffer;
    char_matrix = malloc_char_matrix(STRING_NUMBER);

    for (long long int i = 0; i < STRING_NUMBER; i++) {
        printf("Please type something (%lld):\n", i + 1);
        buffer = (char *) malloc(sizeof(char) * BUFFER_LENGTH);

        scanf("%s", buffer);
        char_matrix[i] = buffer;
    }
    putchar('\n');

    for (long long int i = 0; i < STRING_NUMBER; i++) {
        printf("%s", char_matrix[i]);

        if (i != STRING_NUMBER - 1) {
            printf(", ");
        }
    }
    putchar('\n');

    char_matrix_free(char_matrix, STRING_NUMBER);

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


void char_matrix_free(char **target, long long int row_length) {
    for (long long int i = 0; i < row_length; i++) {
        free(target[i]);
    }

    free(target);
}
