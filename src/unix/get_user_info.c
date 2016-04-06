/*
 * Description: 进程相关API调用。
 *     Created: 2016年4月6日
 *      Author: NieYong<aofengblog@163.com>
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <pwd.h>

int main(int argc, char **argv) {
    // 进程信息
    pid_t pid = getpid();
    pid_t ppid = getppid();
    printf("Process Id:%d, Parent Process Id:%d\n", pid, ppid);

    // 用户及组信息
    uid_t uid = getuid();
    gid_t gid = getgid();
    uid_t euid = geteuid();
    gid_t egid = getegid();
    printf("User Id:%d, Group Id:%d, Effective User Id:%d, Effective Group Id:%d\n", uid, gid, euid, egid);

    // 用户详细信息
    struct passwd *user_info = getpwuid(uid);
    printf("Login Name:%s, Login Password:%s, Real Name:%s, Home Dir:%s, Work Shell:%s\n",
            user_info->pw_name, user_info->pw_passwd, user_info->pw_gecos, user_info->pw_dir, user_info->pw_shell);

    return EXIT_SUCCESS;
}
