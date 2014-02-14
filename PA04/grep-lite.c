#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FALSE 0
#define TRUE 1
#define ERROR_RET 2
#define MAX_BUFF 2048

void printHelp()
{

	printf("\n\nUsage: grep-lite [OPTION]... PATTERN");
	printf("\nSearch for PATTERN in standard input. PATTERN is a");
	printf("\nstring. grep-lite will search standard input line by");
	printf("\nline, and (by default) print out those lines which");
	printf("\ncontain pattern as a substring.");
	printf("\n\n  -v, --invert-match     print non-matching lines");
	printf("\n  -n, --line-number      print line number with output");
	printf("\n  -q, --quiet            suppress all output");
	printf("\n\nExit status is 0 if any line is selected, 1 otherwise;");
	printf("\nif any error occurs, then the exit status is 2.\n");

}

int main(int argc, char **argv)
{
	int ind;
	const char *pattern=argv[argc-1];
	int showHelp=FALSE,invertMatch=FALSE,lineNumber=FALSE,quiet=FALSE;

	for(ind=1;ind<argc-1;ind++)
	{
		#define ARGCMP(C) (strcmp(argv[ind],C)==0)
		if(ARGCMP("--help")) showHelp=TRUE;
		else if(ARGCMP("-v") || ARGCMP("--invert-match")) invertMatch=TRUE;
		else if(ARGCMP("-n") || ARGCMP("--line-number")) lineNumber=TRUE;
		else if(ARGCMP("-q") || ARGCMP("--quiet")) quiet=TRUE;
		else
		{
			fprintf(stderr,"error message...");
			return ERROR_RET;
		}
		#undef ARGCMP
	}

	if(showHelp || strcmp(pattern,"--help")==0)
	{
		printHelp();
		return EXIT_SUCCESS;
	}
	if(argc==1)
	{
		fprintf(stderr,"error!\n");
		return ERROR_RET;
	}

	char buffer[MAX_BUFF];
	int found=FALSE;
	int currLine=0;
	int matches=0;

	while(fgets(buffer,MAX_BUFF,stdin) != NULL)
	{
		currLine++;
		matches=(strstr(buffer,pattern) != NULL);
		if((matches && !invertMatch) || (!matches && invertMatch))
		{
			found=TRUE;
			if(!quiet)
			{
				if(lineNumber) printf("%d: ",currLine);
				printf("%s ",buffer);
			}
		}
	}

	return found ? 0:1;
}


