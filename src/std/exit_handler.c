/*
 * Description: 退出处理器注册和执行。
 *     Created: 2016年4月14日
 *      Author: NieYong<aofengblog@163.com>
 */

#include <stdio.h>
#include <stdlib.h>

void exit_handler1() {
    printf("退出处理器1\n");
}

void exit_handler2() {
    printf("退出处理器2\n");
}

int main(int argc, char **argv) {
    printf("hello\n");

    /**
     * 退出处理器的执行与注册的顺序相反：先注册的反而后执行。输出结果如下：
     * hello
     * end
     * 退出处理器2
     * 退出处理器1
     */
    atexit(exit_handler1);
    atexit(exit_handler2());

    printf("end\n");

    return EXIT_SUCCESS;
}
