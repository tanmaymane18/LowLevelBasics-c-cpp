#include <stdio.h>
#include "logger.h"

int main(int argc, char *argv[]){
  char* filename = "logger.log";

  logfile lf = init_log(filename);

  info_log(lf, "This is a info log");
  debug_log(lf, "This is a debug log");
  error_log(lf, "This is a error log");
  fclose(lf);

  return 0;
}
