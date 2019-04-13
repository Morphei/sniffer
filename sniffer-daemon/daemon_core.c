#include "daemon_core.h"
#include <unistd.h>
#include <pcap.h>

#include "../common/logger.h"
#include "../common/file_manager.h"
#include "../common/arguments_parser.h"

//enum condition {CHILD_NEED_TERMINATE, CHILD_NEED_WORK};
//enum command {START, STOP, SHOW_IP_COUNT, SELECT_IFACE, STAT};

int stop_work = 0;
FILE* STATISTIC_FILE;
int run = 1;

void start_work()
{
    set_PID_FILE();
    open_pipe();
    int status;
    write_log("[DAEMON] Started\n");
    STATISTIC_FILE = open_STATISTIC_FILE();

    status = start_sniffer_thread();

    if (status)
    {
        enum command com;
        for (;;)
        {
            char* command = read_from_pipe();
            com = check_command(command);

            if(com == TERMINATE)
                break;
            else if(com == START)
            {
                if(!run)
                    run = 1;
            }
            else if(com == STOP)
            {
                if(run)
                    run = 0;
            }
            else if(com == SELECT_IFACE)
            {

            }
            else
            {
                break;
            }
//            write_log("[DAEMON] ");
//            write_log(command);
//            write_to_pipe("ACCEPTED");
        }

        // остановим все рабочеи потоки и корректно закроем всё что надо
        status = stop_sniffer_thread();
    }
    else
    {
        write_log("[DAEMON] Create work thread failed\n");
    }

    if(!status)
        write_log("[DAEMON] Work terminated unsuccesfuly");

    write_log("[DAEMON] Stopped\n");
}


int start_sniffer_thread()
{
    char *device; /* Name of device (e.g. eth0, wlan0) */
    char error_buffer[PCAP_ERRBUF_SIZE]; /* Size defined in pcap.h */

    /* Find a device */
    device = pcap_lookupdev(error_buffer);
    if (device == NULL) {
        printf("Error finding device: %s\n", error_buffer);
        return 1;
    }

    printf("Network device found: %s\n", device);
    return 1;
}

int stop_sniffer_thread()
{
    return 1;
}

void *thread_sniff()
{
    for (;;)
    {
       if(stop_work)
       {
           break;
       }

       write_statistic("sniff sniff \n");
       sleep(1);
       write_statistic("sniff sniff \n");
       sleep(1);
       write_statistic("sniff sniff \n");
       sleep(1);
       break;
    }
}

void write_statistic(char *message)
{
    fprintf(STATISTIC_FILE, message);
}

