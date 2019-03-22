#ifndef str_h
#define str_h

#include <stdint.h>

char *readLine();
char **split(char*);
char **nextCommand();
uint64_t stringToNum(char*);

#endif // str_h
