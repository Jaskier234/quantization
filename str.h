#ifndef str_h
#define str_h

#include <inttypes.h>

// Returns next correct command or NULL when there is no more commands
char **nextCommand();

// Converts string to uint64_t
uint64_t stringToNum(char *string);

#endif // str_h
