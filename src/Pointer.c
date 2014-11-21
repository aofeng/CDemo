/* C语言指针 */

#include <stdio.h>
#include <stdint.h>

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

    // ＊＊＊＊＊＊＊＊＊＊ 把一个变量的地址赋予相同类型的指针变量 ＊＊＊＊＊＊＊＊＊＊
    int a, *pa;
    a = 5;
    pa = &a;
    printf("a=%d, a's address=%p, pa=%p, *pa=%d, pa's address=%p \n", a, &a,  pa,  (*pa), &pa);
//    输出结果：
//    a=5, a's address=1993307092, pa=1993307092, *pa=5, pa's address=1993307080

    // ＊＊＊＊＊＊＊＊＊＊ 把一个指针变量的值赋予另一个指针变量 ＊＊＊＊＊＊＊＊＊＊
    int *pb = pa;
    printf("*pb=%d, pb's address=%p, pb=%p \n", (*pb), &pb, pb );
    printf("pa==pb的结果:%d \n", (pa==pb) );
//    输出结果：
//    *pb=5, pb's address=1993307072, pb=1993307092
//     pa==pb的结果:1

    // ＊＊＊＊＊＊＊＊＊＊ 把数组首地址赋予指针变量 ＊＊＊＊＊＊＊＊＊＊
    long c[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    long *pc = c;
    printf("*c=%ld, c's address=%p, c=%p, pc=%p, *pc=%ld, pc's address=%p \n", *c, &c, c, pc,  (*pc), &pc );
//    输出结果：
//    *c=1, c's address=206007712, c=206007712, pc=206007712, *pc=1, pc's address=206007704

    // ＊＊＊＊＊＊＊＊＊＊ 把字符串的首地址赋予指针变量 ＊＊＊＊＊＊＊＊＊＊
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
    printf("c=%p, *c=%2ld \n", c,  *c );
    long *pc = c;  // 不能直接对c进行加减运算，否则编译时会报错"自增运算中的左值无效"
    int var = 0;
    for (; var < 8; ++var) {
        printf("pc=%p, *pc=%2ld,  c=%p, *c=%2ld  \n", pc, *pc, c, *c );
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
        printf("str=%p, *str=%c \n", str, *str);
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

/**
 * 指针与常量。
 */
void pointerAndConst() {
    printfTitle("指针与常量");

    // ＊＊＊＊＊＊＊＊＊＊ 指向常量的指针（不能通过解引修改指针指向地址的值，但可以把指针指向另一个地址） ＊＊＊＊＊＊＊＊＊＊
    const int num = 9;
    int otherNum = 909;
    const int *pnum = &num;
    printf("num%d, otherNum=%d, *pnum=%d \n", num, otherNum, *pnum);
//    num = 10;   // 编译时提示“向只读变量 ‘num’ 赋值"
//    *pnum = 10;   // 编译时提示“向只读位置赋值"
    pnum = &otherNum;
    printf("执行pnum = &otherNum;, *pnum=%d \n", *pnum);
//    输出结果：
//    num9, otherNum=909, *pnum=9
//    执行pnum = &otherNum;, *pnum=909

    // ＊＊＊＊＊＊＊＊＊＊ 指向非常量的常量指针（可以通过解引修改指针指向地址的值，但不可以把指针指向另一个地址） ＊＊＊＊＊＊＊＊＊＊
    int a = 10;
    int *const pa = &a;
    printf("\na=%d, pa's address=%p, *pa=%d \n", a, pa, *pa);
    *pa = 11;
//    pa = &otherNum;   //  编译时提示“向只读变量 ‘pa’ 赋值"
    printf("执行*pa=11后，a=%d, pa's address=%p, *pa=%d \n", a, pa, *pa);
//    输出结果：
//    a=10, pa's address=0x7fff714da5b4, *pa=10
//    执行*pa=11后，a=11, pa's address=0x7fff714da5b4, *pa=11

    // ＊＊＊＊＊＊＊＊＊＊ 指向常量的常量指针（不可以通过解引修改指针指向地址的值，不可以把指针指向另一个地址） ＊＊＊＊＊＊＊＊＊＊
    int b = 100;
    const int *const pb = &b;
    printf("\nb=%d, pb's address=%p, *pb=%d \n", b, pb, *pb);
//    pb = &otherNum;   // 编译时提示“向只读变量 ‘pb’ 赋值"
//    *pb = 199;   // 编译时提示“向只读位置赋值"
//    输出结果：
//    b=100, pb's address=0x7fff4f947cd8, *pb=100
}

int main(int argc, char **argv) {
    assign();
    arrayPointer();
    stringPointer();
    pointerAndConst();

    return 0;
}
