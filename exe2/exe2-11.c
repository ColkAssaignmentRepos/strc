//
// Created by Manaki ITO on 2021/06/29.
//
#include <stdio.h>

#define BITS_IN_A_BYTE 8


int main(void) {
    size_t size_of_char = sizeof(char);

    printf("The size of the type `char` is:\n");
    printf("%ld byte(s)\n", size_of_char);
    printf("%ld bit(s)\n", size_of_char * BITS_IN_A_BYTE);

    return 0;
}
