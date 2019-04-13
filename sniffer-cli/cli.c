#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#include "cli.h"
#include "../common/logger.h"
#include "../common/file_manager.h"
#include "../common/arguments_parser.h"

int DAEMON_IS_RUNNING = 0;

void start_cli()
{
    open_LOG_FILE();
    char* command = malloc(sizeof (char) * 50);
    char* answer = malloc(sizeof (char) * 50);

    if(!daemon_running())
        printf("Daemon not running, but you can check statistic\n");
    else
    {
        DAEMON_IS_RUNNING = 1;
        open_pipe();
    }

    for (;;)
    {
        wait_input(command);
        process_input(command, answer);
        show_output(answer);
    }
}

void wait_input(char* command)
{
    fgets(command, 50, stdin);
}

void process_input(char* command, char* answer)
{
    enum command com;
    com = check_command(command);
    if(com == EXIT)
    {
        exit(0);
    }

    if(com == ERROR)
    {
        printf("Unknown command\n");
    }
    else {
        if(com == STAT)
        {
            printf("Showing stat from file\n");
        }
        else if(com == HELP)
        {
            printf("Go help yourself\n");
        }
        else if(com == SHOW_IP_COUNT)
        {
            printf("Showing count");
        }
        else
        {
            if(DAEMON_IS_RUNNING)
            {
                write_to_pipe(command);
                answer = read_from_pipe();
                write_log("[CL] ");
                write_log(answer);
                printf(answer);
            }
            else printf("Daemon not running, start daemon firstly.\n");
        }
    }
}

void show_output(char *answer)
{
    printf(answer);
}

int daemon_running()
{
    return check_PID_FILE();
}
