/*
 * Description: 展示目录中的子目录和文件列表。
 *     Created: 2016年4月8日
 *      Author: NieYong<aofengblog@163.com>
 */

#ifndef _GNU_SOURCE
    #define _GNU_SOURCE
#endif
#ifndef __USE_XOPEN
    #define __USE_XOPEN
#endif

#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <time.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>
#include <errno.h>

/**
 * 将秒数转换成"2016-04-08 18:30:20"格式的字符串。
 * @param seconds 某个日期时间的秒数
 * @param datetimestr 存储日期时间长度为20的字符串数组
 */
void sec2datetimestr(const time_t seconds, char *datetimestr) {
    strftime(datetimestr, 20, "%Y-%m-%d %H:%M:%S", localtime(&seconds));
}

/**
 * 根据st_mode计算文件的权限访问字符串（rwxrwxrwx）。
 * @param access_str 存储权限访问字符串的数组
 * @param mode inode中的st_mode
 */
void computeAccess(char *access_str, mode_t mode) {
    static int access[] = {S_IRUSR, S_IWUSR, S_IXUSR, S_IRGRP, S_IWGRP, S_IXGRP, S_IROTH, S_IWOTH, S_IXOTH};
    static char rwx[] = {'r', 'w', 'x'};
    for (unsigned int i = 0; i < 9; ++i) {
        if (access[i] & mode) {
            access_str[i] = rwx[i%3];
        } else {
            access_str[i] = '-';
        }
    }

    access_str[9] = '\0';
}

void printDir(char *dir_path) {
    struct stat buf;
    char *ftype;
    char faccess[10];
    char ctime[20];
    char mtime[20];

    printf("%-4s %-10s %-50s %-22s %-22s\n", "type", "access", "file_name", "ctime", "mtime");
    printf("----------------------------------------------------------------------------------------------------\n");
    chdir(dir_path); // 由于opendir传入的参数是目录名，因此必须切换至该目录
    DIR *ds = opendir(dir_path);
    struct dirent *dp = readdir(ds);
    while (NULL != dp) {
        if (lstat(dp->d_name, &buf) == -1) { // 定义__USE_XOPEN才能使用lstat，否则只能使用stat
            fprintf(stderr, "get [%s] inode information fail\n", dp->d_name);
            strerror(errno);
            dp = readdir(ds);
            continue;
        }
        if (S_ISREG(buf.st_mode)) {
            ftype = "FILE";
        } else if (S_ISDIR(buf.st_mode)) {
            ftype = "DIR";
        } else if (S_ISCHR(buf.st_mode)) {
            ftype = "CHR";
        } else if (S_ISFIFO(buf.st_mode)) {
            ftype = "FIFO";
        } else if (S_ISLNK(buf.st_mode)) {
            ftype = "LINK";
        } else if (S_ISBLK(buf.st_mode)) {
            ftype = "BLK";
        } else if (S_ISSOCK(buf.st_mode)) { // 定义_GNU_SOURCE才能使用S_ISSOCK
            ftype = "SOCK";
        } else {
            ftype = "UNKO";
        }
        computeAccess(faccess, buf.st_mode);
        sec2datetimestr(buf.st_ctime, ctime);
        sec2datetimestr(buf.st_mtime, mtime);
        printf("%-4s %-10s %-50s %-22s %-22s\n", ftype, faccess, dp->d_name, ctime, mtime);

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
