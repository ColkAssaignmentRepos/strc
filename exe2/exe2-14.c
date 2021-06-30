//
// Created by Manaki ITO on 2021/06/29.
//
#include <stdio.h>
#include <stdlib.h>

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


int main(void) {
    char **char_matrix = NULL;
    char_matrix = malloc_char_matrix(STRING_NUMBER);

    char_matrix[0] = MONDAY;
    char_matrix[1] = TUESDAY;
    char_matrix[2] = WEDNESDAY;
    char_matrix[3] = THURSDAY;
    char_matrix[4] = FRIDAY;
    char_matrix[5] = SATURDAY;
    char_matrix[6] = SUNDAY;

    printf("0-月曜日 1-火曜日 2-水曜日 3-木曜日 4-金曜日 5-土曜日 6-日曜日\n");
    for (long long int i = 0; i < STRING_NUMBER; i++) {
        printf("%lld-%s", i, char_matrix[i]);

        if (i != STRING_NUMBER - 1) {
            printf(" ");
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
