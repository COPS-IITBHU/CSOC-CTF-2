#include <err.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char *gets(char *);

void complete_level()
{
    system("cat flag2.txt");
    exit(0);
}

void start_level()
{
    char buffer[64];
    void *ret;

    gets(buffer);

    ret = __builtin_return_address(0);
    printf("and will be returning to %p\n", ret);
}

int main(int argc, char **argv)
{
    printf("%s\n", "Welcome to PWN challenges....level2");
    start_level();
}