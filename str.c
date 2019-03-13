#include "srt.h"

char *readLine()
{
    int allocatedMemory = 10;
    char *str = malloc(allocatedMemory);
    int lineSize = 0;

    do
    {
        if( lineSize == allocatedMemory )
        {
            // sprawdzić czy się da
            realloc(str, allocatedMemory*2);
            allocatedMemory *= 2;
        }
        scanf("%c", str[lineSize]);
        lineSize++;
    } while(str[lineSize-1] != '\n');

    return str;
}

char **split(char *str)
{
    char **words = malloc(3);
    int iterator = 0;
    int wordCounter = 0;
    while( str[iterator] != '\n' )
}
