//
// Created by Manaki ITO on 2021/06/29.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRING_NUMBER 7
#define BUFFER_LENGTH 64

#define MONDAY "Monday"
#define TUESDAY "Tuesday"
#define WEDNESDAY "Wednesday"
#define THURSDAY "Thursday"
#define FRIDAY "Friday"
#define SATURDAY "Saturday"
#define SUNDAY "Sunday"

#define print_error(...) {fprintf(stderr, "\x1b[31m"); fprintf(stderr, __VA_ARGS__); fprintf(stderr, "\x1b[39m\n");}
#define fatal_with_message(exit_code, ...) {print_error(__VA_ARGS__); exit(exit_code);}

char **malloc_char_matrix(long long int row_length);

void char_matrix_free(char **target, long long int row_length);


int main(void) {
    char **char_matrix = NULL;
    char *buffer;
    char_matrix = malloc_char_matrix(STRING_NUMBER);

    for (long long int i = 0; i < STRING_NUMBER; i++) {
        buffer = (char *) malloc(sizeof(char) * BUFFER_LENGTH);
        char_matrix[i] = buffer;
    }

    strcpy(char_matrix[0], MONDAY);
    strcpy(char_matrix[1], TUESDAY);
    strcpy(char_matrix[2], WEDNESDAY);
    strcpy(char_matrix[3], THURSDAY);
    strcpy(char_matrix[4], FRIDAY);
    strcpy(char_matrix[5], SATURDAY);
    strcpy(char_matrix[6], SUNDAY);

    printf("0-月曜日 1-火曜日 2-水曜日 3-木曜日 4-金曜日 5-土曜日 6-日曜日\n");
    for (long long int i = 0; i < STRING_NUMBER; i++) {
        printf("%lld-%s", i, char_matrix[i]);

        if (i != STRING_NUMBER - 1) {
            printf(" ");
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
