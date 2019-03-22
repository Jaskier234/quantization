#include <stdlib.h>
#include <string.h>

#include "str.h"
#include "trie.h"
#include "history.h"

int main()
{
    Node *trie = malloc(sizeof(Node));
    if(trie == NULL)
    {
        return 0;
    }
    *trie = trieDefault;
    while(true)
    {
        char **args = nextCommand();
        if(args != NULL)
        {
            if(strcmp(args[0],"DECLARE") == 0)
            {
                declare(trie, args[1]);
            }
            else if(strcmp(args[0],"VALID") == 0)
            {
                valid(trie, args[1]);
            }
            else if(strcmp(args[0],"REMOVE") == 0)
            {
                delete(trie, args[1]);
            }
            else if(strcmp(args[0],"ENERGY") == 0)
            {
                if(args[2] == NULL)
                {
                    getEnergy(trie, args[1]);
                }
                else
                {
                    setEnergy(trie, args[1], args[2]);
                }
            }
            else if(strcmp(args[0],"EQUAL") == 0)
            {
                equal(trie, args[1], args[2]);
            }
            free(args[0]);
            free(args);
        }
        else
        {
            break;
        }
    }
    freeNode(trie);

    return 0;
}
