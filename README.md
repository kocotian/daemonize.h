# daemonize.h
simply daemonize your program

## simple usage:
1. `#include "daemonize.h"` in your project
2. write `daemonize()` on beginning of your main with parameters:
    1. **chdir** directory, for example `"/"`
    2. **umask**, for example `0022`
    3. **signals struct**, structure of {*SIGNAL NUMBER*, *SIGNAL HANDLER*}'s

## license:
do what the fuck you want to

## example program:
program that daemonizes, exits with signal number after receiving SIGINT, SIGHUP and SIGCHLD and just goes to minute sleeping forever
```
#include "daemonize.h"

void sighandler(int signo);

static const Signals sigs[] = {
	{SIGINT, sighandler},
	{SIGHUP, sighandler},
	{SIGCHLD, sighandler},
};

void
sighandler(int signo)
{
	exit(signo);
}

void
main(void)
{
	daemonize("/", 0022, sigs);
	while(1) sleep(60);
}
```
