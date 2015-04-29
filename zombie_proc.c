/* Feature test switches */
#define _POSIX_SOURCE 1

/* System headers */
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

/* Local headers */

/* Macros */
#define TRUE 1
#define FALSE 0
#define SIZE 256

/* File scope variables */

/* External variables */

/* External functions */

/* Structures and unions */

/* Signal catching functions */

/* Functions */

/* Main */

/* Forks a child process that becomes a zombie process.
** This process should remain in the system for at least 10 seconds.
** Check the status of
** - process registers
** - process counter
** - memory
**
*/
int main(int argc, char *argv[])
{
	pid_t pid;
	pid = fork();

	if (pid == -1) {
		printf("Failed to create new process.\n");
	}

	if (pid == 0) {
		printf("Started child process. Will exit after 1 minute.\n");
		sleep(60);
		_exit(0);
	} 
	else {
		printf("Child process %d started. Parent process exits in 10 seconds\n",pid);
		sleep(10);
		exit(0);
	}
	return 0;
}
