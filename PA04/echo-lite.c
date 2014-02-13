#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc; char **argv)
{
	int index=0;
	for(index=1;i<argc;index++)
	{
		printf("%s",argv[index]);
		if(index != (argc-1)) printf(" ");
	}
	printf("\n");
	return EXIT_SUCCESS;
}
