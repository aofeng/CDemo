/*
 * Description: 文件的打开，写入和关闭操作：程序展示一个菜单，菜单中说明了几个指令的作用。根据用户输入的指令执行操作，直到输入0退出程序。
 *     Created: 2016年3月29日
 *      Author: NieYong<aofengblog@163.com>
 */

#include <stdio.h>
#include <stdlib.h>

void displayMenu() {
    char *menuStr = "********** MENU **********\n"
            "0 - exit\n"
            "1 - read content from file\n"
            "2 - write content to file\n"
            "**************************\n";
    puts(menuStr);
}

/**
 * 读取文件。如果文件路径为NULL或文件不存在，返回-1。否则返回0。
 */
int readFile(char *filePath) {
    if (NULL == filePath) {
        return -1;
    }
    FILE *fp = fopen(filePath, "r");
    if (NULL == fp) {
        perror("open file fail");
        return -1;
    }

    char c;
    while (EOF != (c = fgetc(fp))) {
        putc(c, stdout);
    }
    putc('\n', stdout);
    fclose(fp);

    return 0;
}

/**
 * 写文件。如果打开文件失败或写入文件失败，返回-1；否则返回0。
 */
int writeFile(char *filePath) {
    FILE *fp = fopen(filePath, "w");
    if (NULL == fp) {
        perror("open file fail");
        return -1;
    }
    size_t num = fprintf(fp, "write something:%d", rand());
    if (num < 0) {
        fprintf(stderr, "write data to file fail");
        return -1;
    }
    fclose(fp);

    return 0;
}

void commandControl() {
    char *filePath = "/tmp/file_read_write.temp";
    do {
        char c = getchar();
        if ('0' == c) {
            puts("bye bye!");
            break;
        } else if ('1' == c) {
            readFile(filePath);
            displayMenu();
        } else if ('2' == c) {
            writeFile(filePath);
            displayMenu();
        } else if ('\n' == c || '\r' == c) { // 忽略回车符和换行符
            continue;
        } else {
            puts("invalid commander, enter again.");
            displayMenu();
        }
    } while (1);
}

int main(int argc, char **argv) {
    displayMenu();
    commandControl();

    return EXIT_SUCCESS;
}
