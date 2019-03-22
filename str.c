#define _GNU_SOURCE
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include "str.h"
#include "vector.h"
#include "valid.h"


// char *readLine()
// {
//     Vector strChar = vectorDefault;
//
//     char c;
//     do
//     {
//         scanf("%c", &c);
//         pushChar(&strChar, c);
//     } while(c != '\n');
//
//     return (char*)strChar.c;
// }

char **split(char *str)
{
    Vector words = vectorDefault;

    int size = strlen(str);

    // if(size > 0 && str[0] == '#')
    //     return (char**)words.c;

    if(size < 1 || str[size-1] != '\n')
        return NULL;

    if(size >= 2 && str[size-2] == ' ')
        return NULL;

    // printf("split: %s\n", str);
    if(strcmp(str,"") == 0 || str == NULL)// do przemyślenia
        return (char**)words.c;

    char *lastWordStart = str;
    while(*str != '\n')
    {
        if(*str == ' ')
        {
            pushCharPtr(&words, lastWordStart);
            lastWordStart = str+1;
            *str = '\0';
        }
        str++;
    }

    *str = '\0';

    if(lastWordStart != str)
    {
        pushCharPtr(&words, lastWordStart);
    }
    pushCharPtr(&words, NULL);

    return (char**)words.c;
}

// bool correct(char *command)// być może do oddzielnego modułu
// {
//     return (command[0] != '\n' && command[0] != '#');// do poprawienia
// }

char **nextCommand() // zwraca następną poprawną komendę
{
    size_t size = 16;
    char *input = malloc(size);
    int result;
    char **splittedInput = NULL;
    int isCorrect;
    do
    {
        free(splittedInput);
        result = getline(&input, &size, stdin);
        if(result != -1)
        {
            splittedInput = split(input);
            isCorrect = correct(splittedInput);
            if(isCorrect == 0)
                fprintf( stderr, "ERROR\n");
        }
    } while(result != -1 && isCorrect != 1);

    if(result == -1)
    {
        free(input);
        return NULL;
    }
    else
        return splittedInput;
}

uint64_t stringToNum(char *string)
{
    uint64_t number = 0;
    int size = strlen(string);
    for(int i=0; i<size; i++)
    {
        number *= 10;
        number += string[i] - '0';
    }
    return number;
}
