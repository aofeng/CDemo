/* C语言指针 */

#include <stdio.h>

/**
 * 打印标题。标题格式：第一行空行，第二行为标题，第三行为20个"="
 */
void printfTitle(char *title) {
    printf("\n%s\n====================\n", title);
}

/**
 * 赋值运算。
 */
void assign() {
    printfTitle("指针赋值运算");

    // 把一个变量的地址赋予相同类型的指针变量
    int a, *pa;
    a = 5;
    pa = &a;
    printf("a=%d, *pa=%d \n", a,  (*pa));

    // 把一个指针变量的值赋予另一个指针变量
    int *pb = pa;
    printf("*pb=%d \n", (*pb) );
    printf("pa==pb的结果:%d \n", (pa==pb) );

    // 把数组首地址赋予指针变量
    long c[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    long *pc = c;
    printf("*c=%ld, *pc=%ld \n", *c, (*pc));

    // 把字符串的首地址赋予指针变量
    char *str = "abcdefghijklmnopqrstuvwxyz";
    printf("*str=%c \n", (*str));
}

/**
 * 指向数组的指针变量进行加减运算。
 */
void arrayPointer() {
    printfTitle("指向数组的指针变量进行加减运算");

    long c[9] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    printf("c[9] = {9, 8, 7, 6, 5, 4, 3, 2, 1} \n");
    printf("*c=%ld \n", (*c) );
    long *pc = c;  // 不能直接对c进行加减运算，否则编译时会报错"自增运算中的左值无效"
    pc += 2;
    printf("执行运算long *pc = c; pc+=2后, *pc=%ld \n", (*pc));
    printf("执行运算long *pc = c; pc+=2后, *c=%ld \n", (*c));
}

/**
 * 指向字符串的指针变量进行加减运算。
 */
void stringPointer() {
    printfTitle("指向字符串的指针变量进行加减运算");

    char *str = "abcdefghijklmnopqrstuvwxyz";
    printf("char *str = \"abcdefghijklmnopqrstuvwxyz\" \n");
    printf("*str=%c \n", (*str) );

    char *pstr = str;
    str++;
    printf("执行运算str++后, *str=%c \n", (*str));
}

int main(int argc, char **argv) {
    assign();
    arrayPointer();
    stringPointer();

    return 0;
}
