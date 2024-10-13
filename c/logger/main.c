#include <stdio.h>
#include <time.h>

enum { INFO, DEBUG, ERROR };

typedef FILE * logfile;

logfile init_logger(char* filename){
  printf("Creating logger file %s", filename);
  FILE *fp = fopen(filename, "a+");
  return fp;
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

int main(int argc, char *argv[]){
  char* filename = "logger.log";
  logfile lf = init_logger(filename);
  info_log(lf, "This is a info log");
  debug_log(lf, "This is a debug log");
  error_log(lf, "This is a error log");
  fclose(lf);
  return 0;
}
