#include <stdlib.h>
#include "answer01.h"

int arraySum(int * array, int len)
{
    int sum=0;
    int mark;
    for(mark=0;mark<len;mark++)
    {
	sum+=array[mark];
    }        
    return sum;
}

int arrayCountNegative(int * array, int len)
{
    int count=0;
    int mark;
    for(mark=0;mark<len;mark++)
    {
        if(array[mark]<0)
            count++;
    }
    return count;
}

int arrayIsIncreasing(int * array, int len)
{    
    int mark;
    for(mark=1;mark<len;mark++)
    {
        if(array[mark-1]>array[mark])
            return 0;
    }
    return 1;
}

int arrayIndexRFind(int needle, const int * haystack, int len)
{
    while(len>0)
    {
        if(haystack[len-1]==needle)
            return (len-1);
        len--;
    }
    return -1;
}

int arrayFindSmallest(int * array, int len)
{
    int index=len;
    int mark;
    int smallest;

    if(len<=1)
        return 0;
    else
    {
        smallest=array[len-1];
    }

    for(mark=len-1;mark>=0;mark--)
    {
        if(array[mark]<=smallest)
        {
            smallest=array[mark];
            index=mark;
        }
    }
    return index;
}
