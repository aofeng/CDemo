/*
 * Description: struct和union两种数据结构的使用。
 *     Created: 2016年4月5日
 *      Author: NieYong<aofengblog@163.com>
 */

#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {
    /**
     * 主要区别：
     *   struct中每个成员有自己独立的存储空间，互不影响。
     *   union中所有成员共用存储空间，修改某个成员会影响其他成员。
     */

    struct people {
        unsigned int id;
        char *name;
        char sex;
        unsigned short age;
    };

    struct people xiaomin = { 1, "小明", 'M', 9 };
    struct people mary;
    mary.id = 2;
    mary.name = "玛丽";
    mary.sex = 'F';
    mary.age = 10;

    printf("编号：%d，姓名：%s，性别：%c，年龄：%d\n", xiaomin.id, xiaomin.name, xiaomin.sex, xiaomin.age);
    printf("编号：%d，姓名：%s，性别：%c，年龄：%d\n", mary.id, mary.name, mary.sex, mary.age);
//    输出信息如下：
//    编号：1，姓名：小明，性别：M，年龄：9
//    编号：2，姓名：玛丽，性别：F，年龄：10

    union ticket {
        char src_str[11];
        struct {
            char sys_flag;
            char cluster_name[2];
            char cluster_num;
            char other[6];
        } part;
    };

    union ticket t1;
    strcpy(t1.src_str, "csh1abcde9");
    printf("src_str:%s, sys_flag:%c, cluster_name:%s, cluster_num:%c, other:%s\n",
            t1.src_str, t1.part.sys_flag, t1.part.cluster_name, t1.part.cluster_num, t1.part.other);
//    输出信息如下：
//    src_str:csh1abcde9, sys_flag:c, cluster_name:sh1abcde9, cluster_num:1, other:abcde9

    t1.part.cluster_num = '8';
    printf("src_str:%s, sys_flag:%c, cluster_name:%s, cluster_num:%c, other:%s\n",
            t1.src_str, t1.part.sys_flag, t1.part.cluster_name, t1.part.cluster_num, t1.part.other);
//    输出信息如下：
//    src_str:csh8abcde9, sys_flag:c, cluster_name:sh8abcde9, cluster_num:8, other:abcde9
}
