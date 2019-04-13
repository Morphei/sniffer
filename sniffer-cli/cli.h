#ifndef CLI_H
#define CLI_H

void start_cli(void);
void wait_input(char* command);
void process_input(char *command, char* answer);
void show_output(char* answer);
int daemon_running(void);

#endif // CLI_H
