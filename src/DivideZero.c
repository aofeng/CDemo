/*
 * Description: 除数为零的运行时错误示例。
 *     Created: 2014年7月27日 下午10:19:00
 *      Author: NieYong<aofengblog@163.com>
 *        Blog: http://aofengblog.blog.163.com
 */

#include <stdio.h>

int main(void) {
    int x, y=0;
    x = 1 / y;
    printf("result=%d\n", x);

    return 0;
}
