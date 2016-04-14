/*
 * Description: 
 *     Created: 2016年4月14日
 *      Author: NieYong<aofengblog@163.com>
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

extern char **environ;

/**
 * environ是一个指向数组的指针且数组的末尾元素为NULL，因此对其进行加减就可以历遍数组的内容。
 */
void iterate_env() {
    char **pe = environ;
    char *item;
    if (NULL == pe) {
        fprintf(stderr, "variable envrion is NULL");\
        exit(EXIT_FAILURE);
    }

    printf("环境变量列表：\n");
    while (NULL != (item = *pe)) {
        printf("%s\n", item);
        pe++;
    }
}

/**
 * 设置和获取指定的环境变量值。
 */
void get_put_env(char *key) {
    printf("原始数据 %s=%s\n", key, getenv(key));
    char *kv = malloc(sizeof(char[64]));
    strcat(kv, key);
    strcat(kv, "=");
    strcat(kv, "KEY_VALUE_TEST");
    putenv(kv); // 修改只影响当前进程
    printf("修改后的数据 %s=%s\n", key, getenv(key));
}

int main(int argc, char **argv) {
    get_put_env("USER1");
    iterate_env();
    get_put_env("USER2");
    iterate_env();

    return EXIT_SUCCESS;
}
