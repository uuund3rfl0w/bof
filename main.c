#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

char g_buf[0x100];

void bof1() {
    char buf[0x10];
    read(0, g_buf, sizeof(g_buf));
    strcpy(buf, g_buf);
}

void bof2() {
    char buf[0x10];
    read(0, g_buf, sizeof(g_buf));
    size_t s_size = strlen(g_buf);
    strncpy(buf, g_buf, s_size);
}

int main(int argc, char **argv) {
    int num = 0;
    if (argc >= 2) {
        num = atoi(argv[1]);
    }
    if (num == 1337) {
        bof1();
    } else if (num == 1338) {
        bof2();
    }
    puts("hello world");
    return 0;
}
