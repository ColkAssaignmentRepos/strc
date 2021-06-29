//
// Created by Manaki ITO on 2021/06/29.
//
#include <stdio.h>


int main(void) {
    char inputted_char;

    scanf("%c", &inputted_char);

    if (inputted_char == 'A') {
        printf("正解です\n");
    } else {
        printf("誤りです\n");
    }

    return 0;
}
