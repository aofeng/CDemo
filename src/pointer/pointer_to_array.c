/*
 * Description: 指向数据的指针。
 *     Created: 2016年3月26日
 *      Author: NieYong<aofengblog@163.com>
 */

#include <stdio.h>

const char NEW_LINE = '\n';

int main(int argc, char **argv) {
    int SIZE = 5;

    double balance[5] = {99.001, 66.00, 33.03, 9.9, 100.00};

    // 变量名balance是一个指针数组第1个元素（99.001）的指针，而且是常量，不可修改
    double *p1 = balance;
    int i = 0;
    while (i < SIZE) {
        printf("balance[%d] = %f address = %p%c", i, *p1, p1, NEW_LINE);
        i++;
        p1++;
    }

    // 直接提取数组中第1个元素的地址
    double *p2 = &balance[1];
    i = 0;
    while (i < SIZE) {
        printf("balance[%d] = %f address = %p%c", i, *p2, p2, NEW_LINE);
        i ++;
        p2++;
    }

    return 0;
}
