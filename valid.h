#ifndef valid_h
#define valid_h

// Checks if input is correct command. If the command is correct it splits
// to array of words separated by single spaces ans sets it into args
// 0 - wrong line
// 1 - correct line
// 2 - ignore line
int correct(char *input, char **args);

#endif // valid_h
