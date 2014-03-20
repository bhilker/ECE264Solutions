#include "answer03.h"
#include <string.h>
#include <stdio.h>

int comparShrt(const void *chr1,const void *chr2)
{
	const char *a=chr1;
	const char *b=chr2;

	return -(int)(*b)+(int)(*a);
}

int comparLng(const void *chr1,const void *chr2)
{
	const char **a=chr1;
	const char **b=chr2;

	return strcmp(*a,*b);
}

char * strcat_ex(char * * dest, int * n, const char * src)
{
	int dstln=(*dest==NULL ||dest==NULL)? 0:strlen(*dest);
	int srcln=src==NULL? 0:strlen(src);

	//printf("\nHello there");

	if(*dest==NULL || (srcln+dstln+1)>*n)//will need to check on whether this is a 1 or 2; index
	{
		//printf("\nMade it 1\n");
		*n=1+2*(srcln+dstln);
		char * buffer=malloc(*n*sizeof(char));
		*buffer='\0';
		//printf("\nMade it 2\n");
		if(*dest != NULL)
		{ 
			strcpy(buffer,*dest);
			//printf("\nMade it 2.5\n");			
		}
		free(*dest);		
		//printf("\nMade it 3\n");		
		*dest=buffer;
	}

	//printf("\nHome Stretch\n");

	strcat(*dest,src);
	
	return *dest;
}

char * * explode(const char * str, const char * delims, int * arrLen)
{
	*arrLen=1;
	const char *pos=str;
	int counter=0;
	const char *marker=str;
	int len=0;
	int watcher=0;

	//printf("\nSpongebob\n");

	while(*(pos+watcher) != '\0')
	{
		if(strchr(delims,*(pos+watcher))) *arrLen=*arrLen+1;
		watcher++;
	}

	//printf("\nWatcher: %d\n",watcher);

	char * *strngs = malloc(*arrLen*sizeof(char*));
	pos=str;
	while(*pos != '\0')
	{
		if(strchr(delims,*pos))
		{
			len=pos-marker;
			*(strngs+counter)=malloc((len+1)*sizeof(char*));
			memcpy(*(strngs+counter),marker,len*sizeof(char));
			*(*(strngs+counter)+len)='\0';
			counter++;
			marker=pos+1;
		}
		pos++;
	}

	len=pos-marker;
	*(strngs+counter)=malloc((len+1)*sizeof(char*));
	memcpy(*(strngs+counter),marker,len*sizeof(char));
	*(*(strngs+counter)+len)='\0';	

	//printf("\nFinished Explode\n");

	return strngs;
}

char * implode(char * * strArr, int len, const char * glue)
{
	int counter=0;
	char *builder=malloc(sizeof(char));
	*builder='\0';
	int en=0;

	//printf("\nBegan Implode, counter: %d len: %d",counter,len);
	
	while(counter<len)
	{
		//printf("\nCounter: %d",counter);
		en=strlen(builder)+1;
		strcat_ex(&builder,&en,*(strArr+counter));
		counter++;
		if(counter != len)
		{
			strcat_ex(&builder,&en,glue);
		}
	}

	return builder;
}

void sortStringArray(char * * arrString, int len)
{
	qsort(arrString,len,sizeof(char *),comparLng);
}

void sortStringCharacters(char * str)
{
	qsort(str,(size_t)strlen(str),(size_t)(sizeof(char)),comparShrt);
}

void destroyStringArray(char * * strArr, int len)
{
	int counter=0;

	if(strArr !=NULL)
	{
		while(counter<len)
		{
			free(*(strArr+counter));
			counter++;
		}
	}

	free(strArr);
}

