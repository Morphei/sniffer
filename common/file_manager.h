#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#include<stdio.h>

static char* PID_FILE_PATH = "/tmp/sniffer.pid";
static char* LOG_FILE_PATH = "sniffer.log";
static char* STATISTIC_FILE_PATH = "statistic.log";
static char* PIPE_PATH = "/tmp/sniffer_pipe";

FILE* LOG_FILE;
FILE* STATISTIC_FILE;
FILE* PID_FILE;

void set_PID_FILE(void);
int check_PID_FILE(void);
void unlink_PID_FILE(void);

FILE* open_LOG_FILE(void);
void close_LOG_FILE(void);

FILE *open_STATISTIC_FILE(void);
void close_STATISTIC_FILE(void);
void write_STATITSTIC_FILE(char* string);

void remove_pipe(void);
void write_to_pipe(char* command);
char* read_from_pipe(void);
void open_pipe(void);


#endif // FILE_MANAGER_H
