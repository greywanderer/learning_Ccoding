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
  int size;
  fseek(file,0L,SEEK_END);
  size = ftell(file);
  fseek(file,0L,SEEK_SET);
  return(size);
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

int main(int argc, char *argv[])
{
	int filesize;
	FILE *fps;
	FILE *fpd;
	errno = 0;

	/*Check if source exists and its size*/
	if ((fps = fopen(argv[1], "rb"))==NULL) {
	  printf("File, %s, does not exist. Error -> %d\n", argv[1], errno);
	  //fclose(fps);
	  exit(0);
	}
	else {
	  filesize = file_size(fps);
	  printf("Source file is %d Bytes\n", filesize);
	}

	/*Check if enough memory available in destination*/
	char *buffer = malloc(filesize * sizeof *buffer);
	fread(buffer,1,filesize,fps);

	printf("Buffer read is -> %s\n", buffer);
	fpd = fopen(argv[2], "w+b");
	size_t dsize = fwrite(buffer,1,filesize,fpd);

	if (dsize != filesize) {
	  printf("No of bytes written %zd not equal to No of bytes read %d. Incorrect copy!\n",dsize,filesize);
	}

	fclose(fps);
	fclose(fpd);
	return 0;
}
