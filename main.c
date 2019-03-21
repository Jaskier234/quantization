#define _GNU_SOURCE
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "str.h"
#include "vector.h"
#include "trie.h"
#include "list.h"

int main()
{
    Node *trie = malloc(sizeof(Node));
    *trie = trieDefault;
    while(true)
    {
        char *tab = nextCommand();
        if(tab != NULL)
        {
            // printf("%s", tab);
            char **args = split(tab);
            // args validation
            if(strcmp(args[0],"DECLARE") == 0)
            {
                insert(trie, args[1]);
                printf("OK\n");
            }
            else if(strcmp(args[0],"VALID") == 0)
            {
                if(declared(trie, args[1]))
                {
                    printf("YES\n");
                }
                else
                {
                    printf("NO\n");
                }
            }
            else if(strcmp(args[0],"REMOVE") == 0)
            {
                del(trie, args[1]);
                printf("OK\n");
            }
            else if(strcmp(args[0],"ENERGY") == 0)
            {
                if(args[2] == NULL)
                {
                    Element *elem = listElem(trie, args[1]);
                    if(elem == NULL || elem->list->energy == NULL)
                        printf("ERROR\n"); // zmienić na err
                    else
                    {
                        printf("%lld\n", *elem->list->energy);// typ
                    }
                }
                else
                {
                    Element *elem = listElem(trie, args[1]);
                    if(elem->list->energy == NULL)
                        elem->list->energy = malloc(sizeof(long long)); // poprawić
                    *elem->list->energy = atoi(args[2]); // zastąpić funkcję atoi
                    printf("OK\n");
                }
            }
            else if(strcmp(args[0],"EQUAL") == 0)
            {
                Element *elem1 = listElem(trie, args[1]);
                Element *elem2 = listElem(trie, args[2]);
                merge(elem1, elem2);
                printf("OK\n");
            }
            free(args);
            free(tab);
        }
        else
        {
            break;
        }
    }
    freeNode(trie);
    // size_t size = 1024;
    // char* input = malloc(size);
    //
    // Node *trie = malloc(sizeof(Node));
    // *trie = trieDefault;
    //
    // while(getline(&input, &size, stdin) != -1)
    // {
    //     if(input[0] == '#' || input[0] == '\n')
    //         continue;
    //     char **command = split(input);
    //     if(strcmp(command[0], "DECLARE") == 0)
    //     {
    //         insert(trie, command[1]);
    //         printf("OK\n");
    //     }
    //     else if(strcmp(command[0], "VALID") == 0)
    //     {
    //         if(declared(trie, command[1]))
    //             printf("YES\n");
    //         else
    //             printf("NO\n");
    //     }
    //     else if(strcmp(command[0],"REMOVE") == 0)
    //     {
    //         del(trie,command[1]);
    //         printf("OK\n");
    //     }
    //     // free(command[0]);
    //     free(command);
    // }
    //
    // del(trie, "0");
    // del(trie, "1");
    // del(trie, "2");
    // del(trie, "3");
    // free(trie);
    // free(input);
    // Node *trie = malloc(sizeof(Node));
    // *trie = trieDefault;
    // // char *s = "0123";
    //
    // insert(trie, "0123");
    //
    // printf("%d\n", declared(trie, "0"));
    // printf("%d\n", declared(trie, "01"));
    // printf("%d\n", declared(trie, "023"));
    // printf("%d\n", declared(trie, "0123"));
    //
    // del(trie, "");
    //
    // // free(s);

    return 0;
}
