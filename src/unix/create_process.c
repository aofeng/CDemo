/*
 * Description: 创建子进程。
 *     Created: 2016年4月6日
 *      Author: NieYong<aofengblog@163.com>
 */

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <math.h>

void create_child_process() {
    printf(">>>父进程(%d)开始处理\n", getpid());
    pid_t pid = fork(); // -1：创建失败；0：子进程；大于0：父进程获得的子进程编号
    if (-1 == pid) {
        // 创建子进程失败
        printf("创建子进程失败，原因：%s\n", strerror(errno));
        exit(EXIT_FAILURE);
    } else if (0 == pid) {
        // 子进程
        printf(">>>子进程(%d)开始处理\n", getpid());
        for (int i = 0; i < 1000000; ++i) {
            sqrt(i);
        }
        printf("子进程(%d)处理结束>>>\n", getpid());
        exit(EXIT_SUCCESS);
    } else if (0 < pid) {
        printf("父进程(%d)处理结束>>>\n", getpid());
    }
}

int main(int argc, char **argv) {
    create_child_process();

    return EXIT_SUCCESS;
}
