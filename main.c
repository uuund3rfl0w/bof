#include <stdio.h>
#include <string.h>

char g_buf[0x100];

void bof1() {
    char buf[0x10];
    fread(g_buf, sizeof(g_buf), 1, stdin);
    strcpy(buf, g_buf);
}

void bof2() {
    char buf[0x10];
    fread(g_buf, sizeof(g_buf), 1, stdin);
    size_t s_size = strlen(g_buf);
    strncpy(buf, g_buf, s_size);
}

int main(int argc, char **argv) {
    // use it, don't optimize
    if (argc == 1337) {
        bof1();
    } else if (argc == 1338) {
        bof2();
    }
    puts("hello world");
    return 0;
}
