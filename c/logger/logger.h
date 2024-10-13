#include "stdio.h"

typedef FILE * logfile;

enum {INFO, DEBUG, ERROR};

logfile init_log(char * filename);
void close_log(logfile lf);
void write_log(logfile lf, char * log, int mode);

extern void info_log(logfile lf, char * log);
extern void debug_log(logfile lf, char * log);
extern void error_log(logfile lf, char * log);
