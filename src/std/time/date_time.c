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
    /*
    说明符 替换为             实例
    ------------------------------------------------
    %a    缩写的星期几名称             Sun
    %A    完整的星期几名称             Sunday
    %b    缩写的月份名称               Mar
    %B    完整的月份名称               March
    %c    日期和时间表示法             Sun Aug 19 02:56:02 2012
    %d    一月中的第几天（01-31）       19
    %H    24 小时格式的小时（00-23）    14
    %I    12 小时格式的小时（01-12）    05
    %j    一年中的第几天（001-366）     231
    %m    十进制数表示的月份（01-12）    08
    %M    分（00-59）                  55
    %p    AM 或 PM 名称                PM
    %S    秒（00-61）                  02
    %U    一年中的第几周，以第一个星期日作为第一周的第一天（00-53） 33
    %w    十进制数表示的星期几，星期日表示为 0（0-6）              4
    %W    一年中的第几周，以第一个星期一作为第一周的第一天（00-53） 34
    %x    日期表示法                   08/19/12
    %X    时间表示法                   02:50:06
    %y    年份，最后两个数字（00-99）    01
    %Y    年份                         2012
    %Z    时区的名称或缩写              CDT
    %%    一个 %                       符号 %
    */

    time_t seconds = time(NULL);
    char datetime[30];
    char *format_str = "%Y-%m-%d %H:%M:%S %Z";
    strftime(datetime, 30, format_str, localtime(&seconds));
    printf("秒数%ld格式化后为%s\n", seconds, datetime);
}

int main(int argc, char **argv) {
    current_time();
    sec2struct();
    format();

    return EXIT_SUCCESS;
}
