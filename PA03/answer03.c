#include "answer03.h"

char * strcat_ex(char * * dest, int * n, const char * src);
{
	int dstln=strlen(*dest);
	int srcln=strlen(src);

	if(*dest=='\0' || (srcln+dstln+1)>*n)//will need to check on whether this is a 1 or 2; index
	{
		*n=1+2*(srcln+destln);
		char * buffer=malloc(*n*sizeof(char));
		*buffer='\0';
		if(*dest != NULL) strcpy(buffer,*dest);
		free(*dest);
		*dest=buffer;
	}

	strcat(*dest,src)
	
	return *dest;
}

char * * explode(const char * str, const char * delims, int * arrLen);
{
	*arrLen=1;
	const char *pos=str;
	int counter=0;
	const char *marker=str;
	int len=0;

	while(*pos != '\0')
	{
		if(strchr(delims,*pos))
			(*arrLen)++;
	}

	char * *strngs = malloc(*arrLen*sizeof(char*));
	pos=str;
	while(*pos != '\0')
	{
		if(strchr(delims,*pos))
		{
			len=pos-start;
			*(strngs+counter)=malloc((len+1)*sizeof(char*));
			memcopy(*(strngs+counter),marker,len*sizeof(char));
			*(*(strngs+counter)+len)='\0';
			counter++;
			marker=pos+1;
		}
		pos++;
	}

	len=pos-start;
	*(strngs+counter)=malloc((len+1)*sizeof(char*));
	memcopy(*(strngs+counter),marker,len*sizeof(char));
	*(*(strngs+counter)+len)='\0';	

	return strngs;
}

char * implode(char * * strArr, int len, const char * glue);
{

}

void sortStringArray(char * * arrString, int len);
{

}

void sortStringCharacters(char * str);
{

}

void destroyStringArray(char * * strArr, int len);
{

}

