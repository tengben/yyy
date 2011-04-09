#include <stdio.h>

int main(int argc, const char *argv[])
{
    int array[4][5];
    int *p = array[0];
    int (*s)[];
    char **ptr;
    int *x[10];
    int i = 0;

    ptr = argv;

    for (i = 0; i < argc; i++) 
    {
        printf("%s\n",*(ptr+i));
    }
    return 0;

}
