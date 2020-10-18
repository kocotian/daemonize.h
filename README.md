# daemonize.h
simply daemonize your program

## simple usage:
1. `#include "daemonize.h"` in your project
2. write `daemonize()` on beginning of your main with parameters:
    1. **chdir** directory, for example `"/"`
    2. **umask**, for example `0022`
    3. **signalize**, function that will add signal catching

## license:
do what the fuck you want to

## example program:
program that daemonizes, exits with signal number after receiving SIGINT, SIGHUP and SIGCHLD and just goes to minute sleeping forever
```c
#include "daemonize.h"

void
sighandler(int signo)
{
	exit(signo);
}

void
signalize(void)
{
	signal(SIGINT, sighandler);
	signal(SIGHUP, sighandler);
	signal(SIGCHLD, sighandler);
}

void
main(void)
{
	daemonize("/", 0000, signalize);
	while(1) sleep(60);
}
```
