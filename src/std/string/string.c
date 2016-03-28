/*
 * Description: 字符串基础操作。
 *     Created: 2014年12月3日 下午8:20:10
 *      Author: NieYong<aofengblog@163.com>
 */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

static const char NEW_LINE = '\n';

/**
 * 比较字符串。
 */
void compare() {
    char str[] = "abcdefghi";
    char *pStr = malloc(10);
    strcpy(pStr, "abcdefghi");
    printf("str's address:%p, str's value:%s%c", str, str, NEW_LINE);
    printf("pStr's address:%p, pStr's value:%s%c", pStr, pStr, NEW_LINE);
    int result = strcmp(str, pStr);
    if (result < 0) {
        printf("%s小于%s%c", "str", "pStr", NEW_LINE);
    } else if (result == 0) {
        printf("%s等于%s%c", "str", "pStr", NEW_LINE);
    } else {
        printf("%s大于%s%c", "str", "pStr", NEW_LINE);
    }

    free(pStr);
}

/**
 * 拼接字符串。
 */
void join() {
    char *digit = "0123456789";
    char *character = "abcdefghijklmnopqrstuvwxyz";

    size_t size = strlen(digit) + strlen(character);
    char all[size+1];
    memset(all, 0, size);
    strcat(all, digit);
    strcat(all, character);
    printf("string digit:%s, string character:%s, join result:%s%c", digit, character, all, NEW_LINE);
}

/**
 * 复制字符串。
 */
void search(char *str, char c) {
    char *p = memchr(str, c, strlen(str));
    int index = p - str;
    printf("char '%c' in string \"%s\" index:%d%c", c, str, index, NEW_LINE);
}

int main(int argc, char **argv) {
    compare();
    join();
    search("abcdefghijkl", 'l');
    search("abcdefghijkl", 'a');
    search("1234567890", '4');

    return EXIT_SUCCESS;
}
