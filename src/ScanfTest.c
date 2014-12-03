/*
 * Description: 打印一个很大的字母I。
 *     Created: 2014年8月6日 下午8:12:50
 *      Author: NieYong<aofengblog@163.com>
 *        Blog: http://aofengblog.blog.163.com
 */

#include <stdio.h>

/*
 * 用scanf读取字符。
 */
void readChar();

/*
 * 用scanf读取整数。
 */
void readInt();

/*
 * 用scanf读取字符串。
 */
void readString();

int main(int argc, char **argv) {
//    readChar();
//    readInt();
    readString();

    return 0;
}

void readChar() {
    char a, b, c;
    printf("输入三个字符：");
    scanf("%c%c%c", &a, &b, &c);
    printf("读取三个字符的结果：a=%c, b=%c, c=%c\n", a, b, c);
}

void readInt() {
    int a, b, c;
    printf("输入三个整数：");
    scanf("%d%d%d", &a, &b, &c);
    printf("读取三个整数的结果：a=%d, b=%d, c=%d\n", a, b, c);
}

void readString() {
    char a[10], b[5], c[9];
    printf("输入三个字符串：");
    scanf("%10s%5s%9s", a, b, c);
    printf("读取三个字符串的结果：a=%s, b=%s, c=%s\n", a, b, c);
}
