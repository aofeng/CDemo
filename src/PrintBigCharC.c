/*
 * 打印一个很大的字母C。
 */

#include <stdio.h>

#define OFFSET 20
#define WIDTH  5
#define CHAR    'C'

/*
 * 横着打印指定数量的指定字符。
 */
void printChar(char c, int num);

/*
 * 横着打印指定数量的空格。
 */
void printBlank(int num);

/*
 * 横着打印指定数量的空格并换行。
 */
void printBlankAndNewLine(int num);

/*
 * 打印顶部或底部的横线。
 */
void printLine();

int main(void) {
    int i;

    // 打印顶部横线部分
    printLine();

    // 打印左上角
    for (i= 1; i < WIDTH; ++i) {
        printBlank(OFFSET + (WIDTH - i));
        putchar(CHAR);
        putchar('\n');
    }

    // 打印竖线部分
    for (i = 0; i < WIDTH; ++i) {
        printBlank(OFFSET);
        putchar(CHAR);
        putchar('\n');
    }

    // 打印左下角
    for (i= 1; i < WIDTH; ++i) {
        printBlank(OFFSET + i);
        putchar(CHAR);
        putchar('\n');
    }

    // 打印底部横线
    printLine();

    return 0;
}

void printChar(char c, int num) {
    int var;
    for (var = 0; var < num; ++var) {
        putchar(c);
    }
}

void printBlank(int num) {
    printChar(' ', num);
}

void printBlankAndNewLine(int num) {
    printChar(' ', num);
    putchar('\n');
}

void printLine() {
    printBlank(OFFSET + WIDTH);
    printChar(CHAR, WIDTH+2);
    putchar('\n');
}
