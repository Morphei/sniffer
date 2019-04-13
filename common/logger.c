#include "logger.h"


void set_LOG_FILE(FILE* file)
{
    LOG_FILE = file;
}

void write_log(char *message)
{
    fprintf(LOG_FILE, message);
}
