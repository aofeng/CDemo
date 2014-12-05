/*
 * Description: 字符串基础操作。
 *     Created: 2014年12月3日 下午8:20:10
 *      Author: NieYong<aofengblog@163.com>
 *        Blog: http://aofengblog.blog.163.com
 */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 * 比较字符串。
 */
void equals() {
    char str[] = "abcdefghi";
    char *pStr = malloc(10);
    strcpy(pStr, "abcdefghi");
    printf("str's address:%p, str's value:%s \n", str, str);
    printf("pStr's address:%p, pStr's value:%s \n", pStr, pStr);
    int result = strcmp(str, pStr);
    if (result < 0) {
        printf("%s小于%s \n", "str", "pStr");
    } else if (result == 0) {
        printf("%s等于%s \n", "str", "pStr");
    } else {
        printf("%s大于%s \n", "str", "pStr");
    }

    free(pStr);
}



int main(int argc, char **argv) {
    equals();

    return EXIT_SUCCESS;
}
