/*
 * 除数为零的运行时错误示例。
 */

#include <stdio.h>

int main(void) {
    int x, y=0;
    x = 1 / y;
    printf("result=%d\n", x);

    return 0;
}
