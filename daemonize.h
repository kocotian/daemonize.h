#ifndef DAEMONIZE_H
#define DAEMONIZE_H

#define _XOPEN_SOURCE 700

/*
 * daemonize.h
 * simply daemonize your program
 * version 1.2
 * creator: kocotian
 */

#include <sys/stat.h>
#include <sys/types.h>

#include <signal.h>
#include <stdlib.h>
#include <syslog.h>
#include <unistd.h>

#define LEN(x) (sizeof(x) / sizeof(*x))

typedef struct {
	int signo;
	void (*handler)(int signo);
} Signals;

static int
daemonize(char *chdir_, int umask_, const Signals sigs[])
{
	pid_t pid;
	int fd, sig = -1;

	if((pid = fork()) < 0)
		return EXIT_FAILURE;
	if(pid > 0)
		exit(EXIT_SUCCESS);

	if(setsid() < 0)
		return EXIT_FAILURE;

	while(++sig < LEN(sigs))
		signal(sigs[sig].signo, sigs[sig].handler);

	if((pid = fork()) < 0)
		return EXIT_FAILURE;
	if(pid > 0)
		exit(EXIT_SUCCESS);

	chdir(chdir_);
	umask(umask_);

	fd = sysconf(_SC_OPEN_MAX) + 1;
	while(fd-- > 0)
		close(fd);

	return EXIT_SUCCESS;
}

#endif
