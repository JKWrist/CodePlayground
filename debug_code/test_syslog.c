#include <syslog.h>

int main(int argc, char **argv)
{
	openlog("Test", LOG_CONS | LOG_PID, LOG_USER );
	syslog(LOG_INFO,"This is a massage just for test");
	closelog();
	return 0;
}