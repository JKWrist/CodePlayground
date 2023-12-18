#include <stdio.h>
#define LANNETINFO_RUNFILE "/var/run/lannetinfo.pid"

typedef int pid_t;
pid_t lanNetInfo_pid;

static void log_pid()
{
  FILE * f;
  char * pidfile = LANNETINFO_RUNFILE;
  
  if((f = fopen(pidfile, "w")) == NULL)
  {
    printf("%s %d create /var/run/lannetinfo.pid error\n", __func__, __LINE__);
    return;
  }

  fprintf(f, "%s\n", lanNetInfo_pid);
  fclose(f);
}

int main()
{
  log_pid();
}

