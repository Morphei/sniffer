#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/file.h>

#include "daemon_handler.h"

//DEBUG
//#include "../common/logger.h"
//#include "../common/file_manager.h"

int main(int argc, char** argv)
{
    //set_LOG_FILE(open_LOG_FILE());
    //write_log("dsfa");
    int pid;

    pid = fork();

    if (pid == -1)
    {
        printf("Error: Start Daemon failed (%s)\n", strerror(errno));

        return -1;
    }
    else if (!pid)
    {
        umask(0);
        setsid();
        //chdir("/");

        close(STDIN_FILENO);
        close(STDOUT_FILENO);
        close(STDERR_FILENO);

        start_monitor();
    }
    else
    {
        return 0;
    }
}
