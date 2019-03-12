#include <stdlib.h>
#include <stdio.h>

char *read()
{
    char *str = malloc(10);
    int l = -1;
    do
    {
        l++;
        scanf("%c", str+l);
    }
    while(str[l] != '\n');
    str[l] = 0;
    return str;
}

int main()
{
    struct num n;
    n.a = 10;
    n.inc();
    printf("%d", n.a);
    return 0;
}
