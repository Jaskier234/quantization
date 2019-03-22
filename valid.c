#include "valid.h"

#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

// Checks if string energy is convertable to uint64_t
bool correctInt(char *energy)
{
    if(strcmp(energy,"0") == 0)
        return false;

    int size = strlen(energy);
    if(size > 20)
        return false;

    for(int i=0; i<size; i++)
    {
        if(energy[i] - '0' < 0 || energy[i] - '0' > 9)
            return false;
    }

    if(size < 20)
        return true;

    char *maxNumber = "18446744073709551615";

    for(int i=0; i<size; i++)
    {
        if(energy[i] > maxNumber[i])
            return false;
    }


    return true; // poprawić!!!;
}

// Compares len first charachers of two strings
// if any of them is shorter than len returns false
bool cmpPref(char*line1, char* line2, int len)
{
    for(int i=0; i<len; i++)
    {
        if(line1[i] == '\0' || line2[i] == '\0')
        {
            return false;
        }

        if(line1[i] != line2[i])
        {
            return false;
        }
    }
    return true;
}

// Checks if at the beginning of string *input is correct command and returns
// pointer to string with that command
char *readCommand(char **input)
{
    char *command = *input;
    if(cmpPref(*input, "DECLARE", 7))
    {
        (*input) += 7;
        return command;
    }
    if(cmpPref(*input, "VALID", 5))
    {
        (*input) += 5;
        return command;
    }
    if(cmpPref(*input, "REMOVE", 6))
    {
        (*input) += 6;
        return command;
    }
    if(cmpPref(*input, "ENERGY", 6))
    {
        (*input) += 6;
        return command;
    }
    if(cmpPref(*input, "EQUAL", 5))
    {
        (*input) += 5;
        return command;
    }
    return NULL;
}

// works similar to readCommand but with history
char *readHistory(char **input)
{
    if(**input != ' ')
    {
        return NULL;
    }
    **input = '\0';
    (*input)++;
    char *history = *input;

    while(**input != ' ' && **input != '\n' && **input != '\0')
    {
        if(**input != '0' && **input != '1' && **input != '2' && **input != '3')
        {
            return NULL;
        }
        (*input)++;
    }

    return history;

}

// works similar to readCommand but with number
char *readInt(char **input)
{
    if(**input != ' ')
    {
        return NULL;
    }
    **input = '\0';
    (*input)++;
    char *number = *input;

    while(**input != ' ' && **input != '\n' && **input != '\0')
    {
        if(**input < '0' || **input > '9')
        {
            return NULL;
        }
        (*input)++;
    }
    return number;
}

// Checks if input is correct command. If the command is correct it splits
// to array of words separated by single spaces ans sets it into args
// 0 - wrong line
// 1 - correct line
// 2 - ignore line
int correct(char *input, char **args)
{
    // Ignored lines
    if(*input == '#' || *input == '\n')
    {
        return 2;
    }

    // If in line is a single characher diffrent than '#' or '\n' it, incorrect
    // line
    int inputSize = strlen(input);
    if(inputSize == 1)
    {
        return 0;
    }

    args[0] = readCommand(&input);
    if(args[0] == NULL)
        return 0;

    args[1] = readHistory(&input);
    if(args[1] == NULL)
        return 0;

    if(strcmp(args[0],"DECLARE") == 0 ||
    strcmp(args[0],"REMOVE") == 0 ||
    strcmp(args[0],"VALID") == 0)
    {
        if(*input == '\n')
        {
            *input = '\0';
            return 1;
        }
        else
        {
            return 0;
        }
    }

    if(strcmp(args[0],"ENERGY") == 0)
    {
        if(*input == '\n')
        {
            *input = '\0';
            return 1;
        }
        else
        {
            args[2] = readInt(&input);
            if(args[2] == NULL)
            {
                return 0;
            }
            if(*input == '\n')
            {
                *input = '\0';
                if(correctInt(args[2]))
                {
                    return 1;
                }
                else
                {
                    return 0;
                }
            }
            else
            {
                return 0;
            }
        }
    }

    if(strcmp(args[0],"EQUAL") == 0)
    {
        args[2] = readHistory(&input);
        if(args[2] == NULL)
        {
            return 0;
        }
        if(*input == '\n')
        {
            *input = '\0';
            return 1;
        }
        else
        {
            return 0;
        }
    }

    return 0;
}
