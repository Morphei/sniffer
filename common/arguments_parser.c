#include <string.h>
#include <stdlib.h>

#include "arguments_parser.h"

enum command parse(char *input)
{
    return ERROR;
}

enum command check_command(char *input)
{
    char* str = malloc(sizeof (char) * 50);
    strcpy(str, input);
    char delim[] = {'\n', ' '};
    char* ptr = strtok(str, delim);
    return command_from_string(ptr);
}


enum command command_from_string(char *string)
{
    if(strcmp(string, "start") == 0)
        return START;
    else if(strcmp(string, "stop") == 0)
        return STOP;
    else if(strcmp(string, "show") == 0)
        return SHOW_IP_COUNT;
    else if(strcmp(string, "select") == 0)
        return SELECT_IFACE;
    else if(strcmp(string, "stat") == 0)
        return STAT;
    else if(strcmp(string, "terminate") == 0)
        return TERMINATE;
    else if(strcmp(string, "--help") == 0 || strcmp(string, "help") == 0)
        return HELP;
    else if(strcmp(string, "exit") == 0)
        return EXIT;
    else return ERROR;
}
