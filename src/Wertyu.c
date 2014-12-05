/*
 * Description: 把手放在键盘上时，稍不注意就会往右错一位，这样的话Q会变主W，J会变K等。输入一个错位后敲出的字符串，输出打字员本来想打出的同句子。
 *              样例输入：O S，GOMR YPFSU/
 *              样例输出：I AM FINE TODAY.
 *     Created: 2014年12月5日 下午6:34:53
 *      Author: NieYong<aofengblog@163.com>
 *        Blog: http://aofengblog.blog.163.com
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
    const char *strList = "`134567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./";

    int i=0;
    int len = strlen(strList);
    printf("字符参考表:%s，长度:%d \n", strList, len);
    printf("请输入一行字符串，按回车结束输入:");
    char c = getchar();
    while (c != EOF && c != '\n') {
        if (c == ' ') { // 空格原样输出
            putchar(c);
            continue;
        }

        for (i = 0; i < len; i++) {
            if (strList[i] == c) {
                if (strList[i - 1]) {
                    putchar(strList[i - 1]);
                } else {
                    putchar(c); // 参考表最左边的字符原样输出
                }
            }
        }

        c = getchar();
    }
    putchar('\n');

    return EXIT_SUCCESS;
}
