/**
 * 动态内存分配。
 */

#include <stdio.h>
#include <stdlib.h>

void mallocInt() {
    size_t size = sizeof(int);
    int* pi = (int*) malloc(size);
    printf("pi=%p, *pi=%d \n", pi, *pi);
    *pi = 9;
    printf("pi=%p, *pi=%d \n", pi, *pi);
    free(pi);
    pi=NULL;
}

void mallocString() {
    size_t size = sizeof(16);
    char *pc = malloc(size);
    char *pcOther = pc;
    printf("pc=%p, *pc=%s \n", pc, *pc);
    int index = 0;
    for (; index < 15; ++index) {
        *pcOther = 'a';
        pcOther++;
    }
    pcOther = '\0';
    pcOther = pc;
    printf("pc=%p, *pc=%s \n", pc, *pc);
    for (index=0; index < 16; ++index) {
        printf("pc[%d]=%c \n", index, *pcOther);
    }
    free(pc);
    pc=NULL;
}

int main(int argc, char **argv) {
    mallocInt();
    mallocString();

    return EXIT_SUCCESS;
}
