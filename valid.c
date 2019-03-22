#include "valid.h"
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

bool correctCommand(char *command)
{
    if(command == NULL)// nie może być NULLem, ale niech zostanie
        return false;

    if((strcmp(command, "DECLARE") == 0) ||
       (strcmp(command, "VALID") == 0) ||
       (strcmp(command, "REMOVE") == 0) ||
       (strcmp(command, "EQUAL") == 0) ||
       (strcmp(command, "ENERGY") == 0) )
       return true;
    return false;
}

bool correctHistory(char *history)
{
    if(history == NULL)
        return false;

    if(strcmp(history, "") == 0)
        return false;

    while(*history != '\0')
    {
        if(*history != '0' && *history != '1' &&
           *history != '2' &&*history != '3')
           return false;
        history++;
    }
    return true;
}

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

int correct(char **words)
{
    if(words == NULL)
        return 0;
    // char **temp = words;
    // while(*temp != NULL)
    // {
    //     printf("%s\n", *temp);
    //     temp++;
    // }

    if(words[0] == NULL)
        return 2;

    if(strcmp(words[0], "") == 0) // ignore
        return 0;

    if(words[0][0] == '#') // ignore
        return 2;

    if( !correctCommand(words[0]) ) // valid zamiast correct?
        return 0;

    if( !correctHistory(words[1]) )// words[1] może być NULLem/ tu też valid jbc
        return 0;

    if( words[2] == NULL && !(strcmp(words[0],"EQUAL") == 0) )// jedno z 4 poleceń 1-argumentowych
        return 1;

    if(strcmp(words[0],"EQUAL") == 0)
    {
        if(correctHistory(words[2]) && words[3] == NULL)
            return 1;
        else
            return 0;
    }

    if(strcmp(words[0],"ENERGY") == 0)
    {
        if(correctInt(words[2]) && words[3] == NULL)
            return 1;
        else
            return 0;
    }
    return 0; // check
    //
    // if( !strcmp(words[0],"EQUAL") 0) //bardzo źle!!!
    //     return true;
}
