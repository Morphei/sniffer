#ifndef LOGGER_H
#define LOGGER_H

#include<stdio.h>

FILE* LOG_FILE;

void write_log(char* message);
void set_LOG_FILE(FILE* file);

#endif // LOGGER_H
