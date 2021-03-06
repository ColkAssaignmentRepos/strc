//
// Created by Manaki ITO on 2021/06/29.
//
#include <stdio.h>

#define BUFFER_LENGTH 4096

long long int count_char_in_string(char *string, char query);


int main(void) {
    char str[BUFFER_LENGTH];
    char query_char;
    long long int number_of_founds;

    printf("Please type something:\n");
    scanf("%s", str);
    fflush(stdin);
    putchar('\n');

    printf("Please type a query character:\n");
    scanf("%s", &query_char);
    putchar('\n');

    number_of_founds = count_char_in_string(str, query_char);

    if (number_of_founds <= 0) {
        printf("No '%c' found in the string.\n", query_char);
    } else {
        printf("Found %lld '%c'(s) in the string.\n", number_of_founds, query_char);
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
