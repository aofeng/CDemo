/* C语言指针 */

#include <stdio.h>

/**
 * 打印标题。标题格式：第一行空行，第二行为标题，第三行为20个"="
 */
void printfTitle(char *title) {
    printf("\n%s\n====================\n", title);
}

/**
 * 赋值运算。
 */
void assign() {
    printfTitle("指针赋值运算");

    // 把一个变量的地址赋予相同类型的指针变量
    int a, *pa;
    a = 5;
    pa = &a;
    printf("a=%d, a's address=%d, pa=%d, *pa=%d, pa's address=%d \n", a, &a,  pa,  (*pa), &pa);
//    输出结果：
//    a=5, a's address=1993307092, pa=1993307092, *pa=5, pa's address=1993307080

    // 把一个指针变量的值赋予另一个指针变量
    int *pb = pa;
    printf("*pb=%d, pb's address=%d, pb=%d \n", (*pb), &pb, pb );
    printf("pa==pb的结果:%d \n", (pa==pb) );
//    输出结果：
//    *pb=5, pb's address=1993307072, pb=1993307092
//     pa==pb的结果:1

    // 把数组首地址赋予指针变量
    long c[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    long *pc = c;
    printf("*c=%ld, c's address=%d, c=%d, pc=%d, *pc=%ld, pc's address=%d \n", *c, &c, c, pc,  (*pc), &pc );
//    输出结果：
//    *c=1, c's address=206007712, c=206007712, pc=206007712, *pc=1, pc's address=206007704

    // 把字符串的首地址赋予指针变量
    char *str = "abcdefghijklmnopqrstuvwxyz";
    printf("*str=%c \n", (*str));
//    输出结果：
//    *str=a
}

/**
 * 指向数组的指针变量进行加减运算。
 */
void arrayPointer() {
    printfTitle("指向数组的指针变量进行加减运算");

    long c[8] = {10, 9, 8, 7, 6, 5, 4, 3};
    printf("c[8] = {10, 9, 8, 7, 6, 5, 4, 3} \n");
    printf("c=%d, *c=%2d \n", c,  *c );
    long *pc = c;  // 不能直接对c进行加减运算，否则编译时会报错"自增运算中的左值无效"
    int var = 0;
    for (; var < 8; ++var) {
        printf("pc=%d, *pc=%2d,  c=%d, *c=%2d  \n", pc, *pc, c, *c );
        pc += 1;
    }
//    输出结果：
//    c[8] = {10, 9, 8, 7, 6, 5, 4, 3}
//    c=205738608, *c=10
//    pc=410368432, *pc=10,  c=410368432, *c=10
//    pc=410368440, *pc= 9,  c=410368432, *c=10
//    pc=410368448, *pc= 8,  c=410368432, *c=10
//    pc=410368456, *pc= 7,  c=410368432, *c=10
//    pc=410368464, *pc= 6,  c=410368432, *c=10
//    pc=410368472, *pc= 5,  c=410368432, *c=10
//    pc=410368480, *pc= 4,  c=410368432, *c=10
//    pc=410368488, *pc= 3,  c=410368432, *c=10
}

/**
 * 指向字符串的指针变量进行加减运算。
 */
void stringPointer() {
    printfTitle("指向字符串的指针变量进行加减运算");

    char *str = "abcdefghijklmnopqrstuvwxyz";
    printf("char *str = \"abcdefghijklmnopqrstuvwxyz\" \n");
    printf("*str=%c \n", (*str) );

    int index = 0;
    for (; index < 26; ++index) {
        printf("str=%d, *str=%c \n", str, *str);
        str++;
    }
//    输出结果：
//    char *str = "abcdefghijklmnopqrstuvwxyz"
//    *str=a
//    str=4196744, *str=a
//    str=4196745, *str=b
//    str=4196746, *str=c
//    str=4196747, *str=d
//    str=4196748, *str=e
//    str=4196749, *str=f
//    str=4196750, *str=g
//    str=4196751, *str=h
//    str=4196752, *str=i
//    str=4196753, *str=j
//    str=4196754, *str=k
//    str=4196755, *str=l
//    str=4196756, *str=m
//    str=4196757, *str=n
//    str=4196758, *str=o
//    str=4196759, *str=p
//    str=4196760, *str=q
//    str=4196761, *str=r
//    str=4196762, *str=s
//    str=4196763, *str=t
//    str=4196764, *str=u
//    str=4196765, *str=v
//    str=4196766, *str=w
//    str=4196767, *str=x
//    str=4196768, *str=y
//    str=4196769, *str=z
}

int main(int argc, char **argv) {
    assign();
    arrayPointer();
    stringPointer();

    return 0;
}
