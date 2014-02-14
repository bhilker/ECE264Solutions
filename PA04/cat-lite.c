#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void printHelp()
{
	printf("\nUsage: cat-lite [--help] [FILE]...");
	printf("\nWith no FILE, or when FILE is -, read standard input.");
	printf("\n\nExamples:");
	printf("\n  cat-lite README   Print the file README to standard output.");
	printf("\n  cat-lite f - g    Print f's contents, then standard input,"); 
	printf("\n                    then g's contents.");
	printf("\n  cat-lite          Copy standard input to standard output.\n");
}

int catFile(const char * filename,FILE *fout)
{
	FILE *fin;
	int isStdin=(strcmp(filename,"-")==0);
	if(isStdin) 
		fin=stdin;
	else 
		fin=fopen(filename,"r");

	if(fin==NULL)
	{	
		return 0;
	}

	int ch;
	while((ch=fgetc(fin)) != EOF)
	{
	 	fputc(ch,fout);	
	}
	
	if(!isStdin) fclose(fin);
	return 1;
}

int main(int argc,char * * argv)
{
	int ind=0;

	if(argc==1)
	{
		catFile("-",stdout);
		return EXIT_SUCCESS;
	}	

	for(ind=1;ind<argc;ind++)
	{
		if(strcmp(argv[ind],"--help")==0)
		{
			printHelp();
			return EXIT_SUCCESS;
		}
	}
	for(ind=1;ind<argc;ind++)
	{
		if(catFile(argv[ind],stdout)==0)
		{
			fprintf(stderr,"cat cannot open %s\n",argv[ind]);
			return EXIT_FAILURE;
		}
	}

	
	return EXIT_SUCCESS;
}
