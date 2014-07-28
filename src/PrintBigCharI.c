/*
 * 打印一个很大的字母I。
 */

#include <stdio.h>

#define BOTTOM_SPACE "\n\n"
#define HEIGHT                10
#define OFFSET                 "                 "
#define TOP_SPACE          "\n\n"

int main(void) {
    int i;

    printf(TOP_SPACE);
    printf(OFFSET "IIIIIIIII\n");
    for (i = 0; i < HEIGHT; ++i) {
        printf(OFFSET "   III\n");
    }
    printf(OFFSET "IIIIIIIII\n");
    printf(BOTTOM_SPACE);

    return 0;
}
