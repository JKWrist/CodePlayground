#include <iostream>
#include <signal.h>
#include <string.h>
#include <sys/time.h>

using namespace std;

volatile static long counter = 0;

static void notify( int signum )
{
	assert(signum == SIGALRM);
	++counter;
	cout << "------------counter = " << counter << endl;
}

typedef void(*ProcessHandler)(int);

class Time
{
protected:
	struct sigaction  _act;
	struct sigaction  _oldact;
	struct itimerval  _tim_ticks;
	void wait( long timeout_ms )
	{
		struct timespec spec;
		spec.tv_sec  = timeout_ms / 1000;
		spec.tv_nsec = (timeout_ms % 1000) * 1000000;
		nanosleep(&spec,NULL);
	}
public:
	Timer(int sec,int usec)
	{
		_tim_ticks.it_value.tv_sec = sec;
		_tim_ticks.it_value.tv_usec = usec;
		_tim_ticks.it_interval.tv_sec = sec;
		_tim_ticks.it_interval.tv_usec = usec;
	}

	void setHandler(ProcessHandler handler)
	{
		sigemptyset( &_act.sa_mask );
		_act.sa_flags = 0;
		_act.sa_handler = handler;
	}


	bool reset()
	{
		int res = sigaction(SIGALRM, &_act, &_oldact);
		if (res) 
		{
			perror( "Fail to install handle: " );
			return false;
		}

		res = setitimer( ITIMER_REAL, &_tim_ticks, 0 );

		if(res)
		{
			perror( "Fail to set timer: " );
			sigaction( SIGALRM, &_oldact, 0 );
			return false;
		}
		for ( ; ; )
		{
			wait(1000000);
		}
	}
};


int main( void )
{
	Timer timer(2,0);
	timer.setHandler(notify);
	timer.reset();
	return 0;
}