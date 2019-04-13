#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>


#include "file_manager.h"

void set_PID_FILE()
{
    PID_FILE = fopen(PID_FILE_PATH, "w+");

    if (PID_FILE)
    {
        fprintf(PID_FILE, "%u", getpid());
        fclose(PID_FILE);
    }
}

FILE *open_LOG_FILE()
{
    if(!LOG_FILE)
        LOG_FILE = fopen(LOG_FILE_PATH, "w+");

    if(LOG_FILE)
        return LOG_FILE;
    else return NULL;
}

void close_LOG_FILE()
{
    if(LOG_FILE)
        fclose(LOG_FILE);
}

void unlink_PID_FILE()
{
    unlink(PID_FILE_PATH);
}

FILE *open_STATISTIC_FILE()
{
    if(!STATISTIC_FILE)
        STATISTIC_FILE = fopen(STATISTIC_FILE_PATH, "w+");

    if(STATISTIC_FILE)
        return STATISTIC_FILE;

    else return NULL;
}

void close_STATISTIC_FILE()
{
    if(STATISTIC_FILE)
        fclose(STATISTIC_FILE);
}

void open_pipe()
{
    mkfifo(PIPE_PATH, 0666);
}

void write_to_pipe(char *command)
{
    int fd = open(PIPE_PATH, O_WRONLY);
    write(fd, command, strlen(command) + 1);
    close(fd);
}

char *read_from_pipe()
{
    char* arr = malloc(sizeof (char) * 10);

    int fd = open(PIPE_PATH, O_RDONLY);
    read(fd, arr, 10);
    close(fd);
    return arr;
}

int check_PID_FILE()
{
    struct stat buffer;
    int exist = stat(PID_FILE_PATH, &buffer);
    if(exist == 0)
        return 1;
    else return 0;
}
