#include <stdlib.h>
#include <string.h>
#include "answer07.h"

List * List_createNode(const char * str)
{
	List *node=malloc(sizeof(List));
	node->str=strdup(str);
	node->next=NULL;
	return node;
}

void List_destroy(List * list)
{
	//Base Case
	if(list==NULL) return;
	//Recursive Case
	List_destroy(list->next);
	free(list->str);
	free(list);
}

int List_length(List * list)
{
	if(list==NULL) return 0;
	return 1 + List_length(list->next);
}

List * List_merge(List * lhs, List * rhs, int (*compar)(const char *, const char*))
{
	//Special Case
	if(lhs==NULL) return rhs;
	if(rhs==NULL) return lhs;
	
	List *head=NULL;
	List *tail=NULL;
	while(lhs !=NULL && rhs != NULL)
	{
		int cmp=compar(lhs->str,rhs->str);
		if(cmp<=0)
		{
			if(tail==NULL)
			{
				head=lhs;
				tail=lhs;
			}
			else
			{
				tail->next=lhs;
				tail=lhs;
			}
			lhs=lhs->next;
			tail->next=NULL;
		}
		else
		{
			if(tail==NULL)
			{
				head=rhs;
				tail=rhs;
			}
			else
			{
				tail->next=rhs;
				tail=rhs;
			}
			rhs=rhs->next;
			tail->next=NULL;
		}
	}
	tail->next=(lhs==NULL)?rhs:lhs;
	return head;
}



List * List_sort(List * list, int (*compar)(const char *, const char*))
{
	int length=List_length(list);
	//Base Case
	if(length<=1) return list;
	//Recursive Case
	int half_length=length/2;
	List *lhs=list;
	List *lhs_tail=list;
	while(--half_length>0) lhs_tail=lhs_tail->next;
	List *rhs=lhs_tail->next;
	lhs_tail->next=NULL;
	//Merge
	lhs=List_sort(lhs,compar);
	rhs=List_sort(rhs,compar);
	
	return List_merge(lhs,rhs,compar);
}

