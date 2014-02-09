#include <stdio.h>
#include "answer02.h"

size_t my_strlen(const char * str)
{
	size_t count=0;

	while(*(str++))
		count++;
	
	return count;
}


int my_countchar(const char * str, char ch)
{
	int count=0;
	int index=0;
	while(*(str + index))
	{
		if(*(str+index)==ch)
			count++;
		index++;
	}
	return count;
}


char * my_strchr(const char * str, int ch)
{
	int index=0;
	int slen=my_strlen(str);
	while(*(str+index))
	{
		if(*(str+index)==ch)
			return (char*) (str+index);
		index++;
	}

	if(index==slen && ch=='\0')
		return (char*) (str+index);

	return NULL;
}


char * my_strrchr(const char * str, int ch)
{
	int count=0;
	while(*(str + count))
	{
		count++;
	}


	while(count>=0)
	{
		if(*(str + count)==ch)
			return (char*)(str + count);
		count--;		
	}
	
	return NULL;
}


char * my_strstr(const char * haystack, const char * needle)
{
	if(*needle=='\0')
		return (char*)haystack;

	int nlen=my_strlen(needle);
	int counter=0;
	int index=0;
	int match=0;
	

	while(*(haystack+index))
	{		
		match=1;
		for(counter=0;counter<nlen && match == 1;counter++)
			if(*(haystack+counter+index)!=*(needle+counter))
				match=0;
		
		if(match)
			return (char*) (haystack+index);
		index++;
	}	
	return NULL;
}


char * my_strcpy(char * dest, const char * src)
{
	int count=0;
	while(*(src+count))
	{
		*(dest+count)=*(src+count);
		count++;
	}
	*(dest+count)='\0';

	return (char*) dest;
}


char * my_strcat(char * dest, const char * src)
{
	int count=0;
	int index=0;
	while(*(dest+count))
		count++;

	while(*(src+index))
	{
		*(dest+count+index)=*(src+index);
		index++;
	}
	*(dest+count+index)='\0';
	return (char*) dest;
}


int my_isspace(int ch)
{
	if((ch==9)||(ch==11)||(ch==12)||(ch==13)||(ch==32)||(ch==10))
		return 1;
	return 0;
}


int my_atoi(const char * str)
{
	int index=0;
	int negative=1;
	int ret=0;
	while(my_isspace(*(str+index)))
	{
		index++;
	}
	if(*(str+index)=='-')
	{
		negative=-1;
		index++;
	}

	while(*(str+index)>='0'&&*(str+index)<='9')
	{
		ret=(ret*10)+(int)(*(str+index))-48;
		index++;
	}

	return ret*negative;
}

