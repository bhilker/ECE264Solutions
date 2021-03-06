#include <math.h>
#include<stdlib.h>
#include<stdio.h>
#include<pthread.h>
#include<string.h>

#include "answer12.h"

typedef struct{
	uint128 n;
	uint128 start_n;
	uint128 stop_n;
	int *is_prime;
}Task;


int my_isspace(int ch)
{
	return ch==' '||ch=='\n'||ch=='\t'||ch=='\r';
}

uint128 alphaTou128(const char * str)
{
	while(*str && my_isspace(*str)) str++;
	uint128 value=0;
	while(*str>='0'&& *str<='9'){
		value *=10;
		value +=(*str-'0');
		str++;
	}
	return value;
}

char * u128ToString(uint128 value)
{
	char buffer[sizeof(uint128)*8+1];
	int write_index=sizeof(buffer)-1;
	buffer[write_index]='\0';
	if(value==0) buffer[--write_index]='0';
	else {
		while(value>0){
			buffer[--write_index]=(value%10)+'0';
			value /=10;
		}
	}
	char *str=malloc(sizeof(char)*(sizeof(buffer)-write_index));
	strcpy(str,buffer+write_index);
	return str;	
}

//will not be using this function initially
void *check_prime_range(void *arg)
{
	Task *task=(Task*)arg;
	uint128 n=task->n;
	
	if(task->start_n<3)task->start_n=3;
	if(task->start_n%2==0)task->start_n+=1;
	if(n%2==0 && n!=2) *(task->is_prime)=0;
	if(n>2 && task->start_n<n && *(task->is_prime)){
		uint128 i;
		for(i=task->start_n;i<task->stop_n && *(task->is_prime) && i<n;i+=2){
			if(n%i==0) *(task->is_prime)=0;
		}
	}
	if(n==2) *(task->is_prime)=1;
	pthread_exit(0);
}

//here is a test function with the same logic
void check_prime_range_test(Task *task)
{
	uint128 n=task->n;
	
	if(task->start_n<3)task->start_n=3;
	if(task->start_n%2==0)task->start_n+=1;

	if(n>2 && task->start_n<n){
		uint128 i;
		for(i=task->start_n;i<task->stop_n && *(task->is_prime);i+=2){
			if(n%i==0) *(task->is_prime)=0;
		}
	}
}

int primalityTestParallel(uint128 value, int n_threads)
{
	Task **task_list=malloc(sizeof(Task*)*n_threads);
	int i;
	int flag=TRUE;
	uint128 value2=sqrt(value)+1;
	for(i=0;i<n_threads;i++){
		task_list[i]=malloc(sizeof(Task));
		task_list[i]->n=value;
		task_list[i]->start_n=i*(value2/n_threads)+1;
		task_list[i]->stop_n=(i+1)*(value2/n_threads);
		if(task_list[i]->stop_n==0) task_list[i]->stop_n=value2;
		if(task_list[i]->stop_n==task_list[i]->start_n) task_list[i]->stop_n+=1;
		task_list[i]->is_prime=&flag;
		//printf("\nTask: %d\nn: %s\nstart_n: %s\nstop_n: %s\n\n",i,u128ToString(task_list[i]->n),u128ToString(task_list[i]->start_n),u128ToString(task_list[i]->stop_n));		
	}


	if(task_list[i-1]->stop_n<value2)task_list[i-1]->stop_n=value2;

	pthread_t *thread_list=malloc(sizeof(pthread_t)*n_threads);
	
	for(i=0;i<n_threads;i++)
	{
		int err=pthread_create(&thread_list[i],NULL,check_prime_range,task_list[i]);
		if(err) fprintf(stderr,"\nERROR: Problem with thread usage\n");
	}
	
	for(i=0;i<n_threads;i++)
	{
		pthread_join(thread_list[i],NULL);
	}

	for(i=0;i<n_threads;i++)
	{
		free(task_list[i]);	
	}
		
	free(task_list);
	free(thread_list);	

	return flag;
}
