#include <stdio.h>
#include <unistd.h>

int err_printf(const char *format, ...)
{
    int out = dup(1);
    dup2(2, 1);
    printf(format);
    dup2(out, 1);
}

int main(void) {
    err_printf("hello %s\n", "world");
}