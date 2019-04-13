#ifndef ARGUMENTS_PARSER_H
#define ARGUMENTS_PARSER_H

enum command {START, STOP, SHOW_IP_COUNT, SELECT_IFACE, HELP, STAT, EXIT, TERMINATE, ERROR = -1};

enum command parse(char* input);
enum command check_command(char* input);
enum command command_from_string(char* string);
#endif // ARGUMENTS_PARSER_H
