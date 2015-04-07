/* Feature test switches */
#define _POSIX_SOURCE 1

/* System headers */
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

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
int file_size(FILE *file)
{
  int start,stop;
  fseek(file,0L,SEEK_END);
  stop	= ftell(file);
  fseek(file,0L,SEEK_SET);
  start	= ftell(file);
  return(stop-start+1);
}

void nl_to_eos(char *name)
{
  size_t ln = strlen(name)-1;
  if (name[ln] == '\n')
	name[ln] = '\0';
}

/* Main */

/* Copies contents of one file to another
** Prompts user for name of source and destination
** Use POSIX API
** Include necessary error checking.
** - if no newline character in string then add more memory to filename
** - check if source exists.
** - check if destination has enough memory
** Use "strace" to trace system calls
*/

int main()
{
	char *source = malloc(SIZE);
	char *destination = malloc(SIZE);
	int filesize;
	FILE *fp;
	FILE *tmp;
	errno = 0;

	(void) printf("Path of the source file -> ");
	(void) fgets(source,SIZE,stdin);

	(void) printf("Path of the destination file -> ");
	(void) fgets(destination,SIZE,stdin);

	nl_to_eos(source);
	nl_to_eos(destination);
	
	(void) printf("Source File -> %s, Name Length -> %zd\n", source, strlen(source));
	(void) printf("Destination File -> %s, Name Length -> %zd\n", destination, strlen(destination));

	/*Check if source exists and its size*/
	if ((fp = fopen(source, "rb"))==NULL) {
	  printf("File, %s, does not exist. Error -> %d\n", source, errno);
	  //fclose(fp);
	  exit(0);
	}
	else {
	  filesize = file_size(fp);
	  printf("Source file is %d Bytes\n", filesize);
	}

	tmp = fp;
  	fseek(tmp,0L,SEEK_SET);
	/*Check if enough memory available in destination*/
	free(source);
	free(destination);
	return 0;
}
