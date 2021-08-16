#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char *gets(char *);

int main(int argc, char **argv)
{
    struct
    {
        char buffer[64];
        volatile int changeme;
    } locals;

    printf("%s\n", "Welcome to PWN challenges....Level 1-");
    locals.changeme = 0;
    gets(locals.buffer);

    if (locals.changeme != 0)
    {
        system("cat flag1.txt");
    }
    else
    {
        puts(
            "Uh oh, 'changeme' has not yet been changed. Would you like to try "
            "again?");
    }

    exit(0);
}