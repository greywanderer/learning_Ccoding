#include <stdio.h>
int main(int argc, char *argv[])
{
	FILE *fp;
	long int start,stop,size;

   	fp = fopen(argv[1],"r");
	start = ftell(fp);
	printf("Start pointer -> %ld\n", start);
   	//fputs("0123", fp);
  
   	fseek( fp, 0, SEEK_END );
	stop = ftell(fp);
	printf("End pointer -> %ld\n", stop);
	size = stop-start+1;
   	fclose(fp);
   	fp = fopen(argv[1],"r");
	int c;
	while ((c = fgetc(fp)) != EOF) {
		printf("Character -> %d\n", c);
	}
	printf("Character EOF-> %d\n", c);

	int i=0;
	while(i++ <= 9) {
	  printf("Character -> %d\n", fgetc(fp));
	}
   	//fputs("*", fp);
   	fclose(fp);
    return 0;
}
