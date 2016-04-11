/*
 * Description: 日期和时间操作。
 *     Created: 2016年4月11日
 *      Author: NieYong<aofengblog@163.com>
 */

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

/**
 * 获取当前时间。
 */
void current_time() {
    time_t result = time(NULL); // 输入参数为NULL
    printf("当前时间的秒数 result=%ld\n", result);

    time_t seconds;
    result = time(&seconds); // 返回值result和输入参数seconds都存储时间的秒数
    printf("当前时间的秒数 result=%ld, seconds=%ld\n", result, seconds);
}

/**
 * 把秒数转换成时间结构，然后获取年月日时分秒。
 */
void sec2struct() {
    time_t seconds = time(NULL);
    struct tm* pgmt = gmtime(&seconds);
    printf("格林威治标准时间：%d年%d月%d日%d时%d分%d秒\n", (1900 + pgmt->tm_year), (1 + pgmt->tm_mon),
            pgmt->tm_mday, pgmt->tm_hour, pgmt->tm_min, pgmt->tm_sec);

    struct tm* plmt = localtime(&seconds);
    printf("本地时间：%d年%d月%d日%d时%d分%d秒\n", (1900 + plmt->tm_year), (1 + plmt->tm_mon),
            plmt->tm_mday, plmt->tm_hour, plmt->tm_min, plmt->tm_sec);
}

/**
 * 日期时间格式化
 */
void format() {

}

int main(int argc, char **argv) {
    current_time();
    sec2struct();
    format();

    return EXIT_SUCCESS;
}
