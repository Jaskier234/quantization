#include <stdlib.h>
#include <stdio.h>
#include "str.h"

int main()
{
    char **tab = split(readLine());

    char **for_free = tab;
    while(*tab != NULL)
    {
        printf("%s\n", *tab);
        tab++;
    }

    free(*for_free);
    free(for_free);

    return 0;
}
