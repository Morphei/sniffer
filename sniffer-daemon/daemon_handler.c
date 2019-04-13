#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <fcntl.h>

#include<sys/wait.h>

#include "daemon_handler.h"
#include "daemon_core.h"
#include "../common/file_manager.h"
#include "../common/logger.h"

enum condition {CHILD_NEED_TERMINATE, CHILD_NEED_WORK};

int start_monitor()
{
    int      pid;
    int      status;
    int      need_start = 1;

    set_LOG_FILE(open_LOG_FILE());

    write_log("[MONITOR] Starting daemon...\n");

    for (;;)
    {
        if (need_start)
        {
            pid = fork();
        }

        need_start = 1;

        if (pid == -1)
        {
            write_log("[MONITOR] Failed to fork\n");
        }
        else if (!pid)
        {
            start_work();
            need_start = 0;
        }
        else
        {

        }

        break;
    }

    write_log("[MONITOR] Monitor terminated.\n");

    unlink_PID_FILE();
    close_LOG_FILE();

    return status;
}
