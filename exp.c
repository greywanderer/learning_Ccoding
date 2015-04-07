#include <stdio.h>
int main()
{
	FILE *fp;

   	fp = fopen("junk1.txt","w+");
	printf("Start pointer -> %ld\n", ftell(fp));
   	fputs("0123", fp);
  
   	fseek( fp, 0, SEEK_END );
	printf("End pointer -> %ld\n", ftell(fp));
   	fputs("*", fp);
   	fclose(fp);
    return 0;
}
