#ifndef DAEMON_CORE_H
#define DAEMON_CORE_H

void start_work(void);
int start_sniffer_thread(void);
int stop_sniffer_thread(void);

void *thread_sniff(void);
void write_statistic(char *message);

#endif // DAEMON_CORE_H
