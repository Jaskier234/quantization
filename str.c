#define _GNU_SOURCE
#include "str.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <inttypes.h>

#include "valid.h"

// Returns next correct command or NULL when there is no more commands
char **nextCommand()
{
    // Memory for getline
    size_t size = 16;
    char *input = malloc(size);

    // Pointer passed to correct witch contains array of command parameters
    // splitted into separate words
    char **splittedInput = malloc(5 * sizeof(char*));
    int isCorrect;
    int result;

    if(input == NULL || splittedInput == NULL)
        exit(1);

    do
    {
        for(int i=0; i<5; i++)
            splittedInput[i] = NULL;
        result = getline(&input, &size, stdin);
        if(result != -1)
        {
            isCorrect = correct(input, splittedInput);
            if(isCorrect == 0)
                fprintf( stderr, "ERROR\n");
        }
    } while(result != -1 && isCorrect != 1);

    if(result == -1)
    {
        free(input);
        free(splittedInput);
        return NULL;
    }
    else
        return splittedInput;
}

// Converts string to uint64_t
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
