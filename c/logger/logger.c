#include "logger.h"
#include "time.h"

logfile init_log(char *filename){
  logfile lf = fopen(filename, "a+");
  return lf;
}

void write_log(logfile lf, char* log, int mode){
  char * prefix;
  time_t rawtime;
  struct tm *info;
  char timestamp[50];
  time(&rawtime);
  info = localtime(&rawtime);
  
  switch (mode) {
    case 0:
      prefix = "INFO";
    break;

    case 1:
      prefix = "DEBUG";
    break;

    case 2:
      prefix = "ERROR";
    break;
  }

  strftime(timestamp, sizeof(timestamp), "%x %H:%M:%S", info);
  fprintf(lf, "%s %s: %s\n", timestamp, prefix, log);
}

void info_log(logfile lf, char* log){
  write_log(lf, log, INFO);
}

void debug_log(logfile lf, char* log){
  write_log(lf, log, DEBUG);
}

void error_log(logfile lf, char* log){
  write_log(lf, log, ERROR);
}

void close_log(logfile lf){
fclose(lf);
}

