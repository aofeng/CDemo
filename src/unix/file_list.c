/*
 * Description: 展示目录中的子目录和文件列表。
 *     Created: 2016年4月8日
 *      Author: NieYong<aofengblog@163.com>
 */

#ifndef __USE_BSD
    #define __USE_BSD
#endif

#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <time.h>
#include <unistd.h>
#include <sys/stat.h>

/**
 * 将秒数转换成"2016-04-08 18:30:20"格式的字符串。
 * @param seconds 某个日期时间的秒数
 * @param datetimestr 存储日期时间长度为20的字符串数组
 */
void sec2datetimestr(const time_t seconds, char *datetimestr) {
    strftime(datetimestr, 20, "%Y-%m-%d %H:%M:%S", localtime(&seconds));
}

void printDir(char *dir_path) {
    struct stat fp;
    char *ftype;
    char ctime[20];
    char mtime[20];

    DIR *ds = opendir(dir_path);
    struct dirent *dp = readdir(ds);
    printf("%-4s %-20s %-22s %-22s\n", "type", "file_name", "ctime", "mtime");
    printf("----------------------------------------------------------------------\n");
    while (NULL != dp) {
        stat(dp->d_name, &fp);
        if (S_ISREG(fp.st_mode)) {
            ftype = "FILE";
        } else if (S_ISCHR(fp.st_mode)) {
            ftype = "CHR";
        } else if (S_ISFIFO(fp.st_mode)) {
            ftype = "FIFO";
        } else if (S_ISLNK(fp.st_mode)) {
            ftype = "LINK";
        } else if (S_ISBLK(fp.st_mode)) {
            ftype = "BLK";
        } else if (S_ISDIR(fp.st_mode)) {
            ftype = "DIR";
        } else {
            ftype = "UNKO";
        }
        sec2datetimestr(fp.st_ctime, ctime);
        sec2datetimestr(fp.st_mtime, mtime);
        printf("%-4s %-20s %-22s %-22s\n", ftype, dp->d_name, ctime, mtime);
        dp = readdir(ds);
    }
    closedir(ds);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "无效参数。使用说明：file_list <目录路径>\n");
        exit(EXIT_FAILURE);
    }

    printDir(argv[1]);

    return EXIT_SUCCESS;
}
