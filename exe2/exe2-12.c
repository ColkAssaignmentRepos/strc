//
// Created by Manaki ITO on 2021/06/29.
//
#include <stdio.h>

#define STRING_LENGTH 9
#define STRING_CONTENT_1 "Hello"
#define STRING_CONTENT_2 "Goodbye"
#define STRING_CONTENT_3 "Thankyou"


int main(void) {
    char string1[] = STRING_CONTENT_1;
    char string2[] = STRING_CONTENT_2;
    char string3[] = STRING_CONTENT_3;

    printf("%s, %s, %s\n", string1, string2, string3);

    return 0;
}
