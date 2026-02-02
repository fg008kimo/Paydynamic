#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include "syscall.h"
#include "common.h"
#include "utilitys.h"
#include "gateway.h"

static void recv_alarm(int signo)
{
//DEBUGLOG(("Recv Timer Expired\n"));
	return;
}

int systemcall(char **argv, int dTimeout) {
	int iRet = PD_OK;

	Sigfunc *sigfunc;

	sigfunc = Signal(SIGALRM, recv_alarm);
	alarm(dTimeout);

	pid_t pid;
	int status;

	pid = fork();
	if (pid < 0) {
//DEBUGLOG(("fork failed\n"));
		iRet = PD_FORK_FAIL;
	} else if (pid == 0) {
		/* the child process */
		execvp(*argv, argv);
		_exit(127);
	} else {
		/* the parent process */
		if (waitpid(pid, &status, 0) > 0) {
//DEBUGLOG(("WIFEXITED(status) = %d, WEXITSTATUS(status) = %d\n", WIFEXITED(status), WEXITSTATUS(status)));
			if (WIFEXITED(status) && !WEXITSTATUS(status)) {
				/* the program terminated normally and executed successfully */
//DEBUGLOG(("child process success, execlp() success, positive result\n"));
			} else if (WIFEXITED(status) && WEXITSTATUS(status)) {
				if (WEXITSTATUS(status) == 127) {
					/* execlp() failed */
//DEBUGLOG(("child process success, execlp() failed\n"));
					iRet = WEXITSTATUS(status);
				} else {
					/* the program terminated normally, but returned a non-zero status */
//DEBUGLOG(("child process success, execlp() success, negative result\n"));
					iRet = WEXITSTATUS(status);
				}
			} else {
				/* the program didn't terminate normally */
//DEBUGLOG(("child process failed\n"));
				iRet = PD_CHILD_FAIL;
			}
		} else {
			/* waitpid() failed */
//DEBUGLOG(("child process timeout\n"));
			iRet = PD_CHILD_TIMEOUT;
		}
	}

	alarm(0);
	Signal(SIGALRM, sigfunc); //restore previous signal handler

	return iRet;
}

void execute(char **argv)
{
	pid_t  pid;
	int    status;

	if ((pid = fork()) < 0) {     /* fork a child process           */
ERRLOG("*** ERROR: execute forking child process failed\n");
		exit(1);
	}
	else if (pid == 0) {          /* for the child process:         */
		if (execvp(*argv, argv) < 0) {     /* execute the command  */
ERRLOG("*** ERROR: execute failed\n");
			exit(1);
		}
	}
	else {                                  /* for the parent:      */
		while (wait(&status) != pid)       /* wait for completion  */
		;
	}
}

