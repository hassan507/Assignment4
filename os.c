#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

void *MySumFunction(void *arg);

int a = 0;
int sum = 0;

int main()
{

int array[1000];

for(int i=0;i<1000;i++)
{
	array[i] = i;
}

pthread_t thread[10];

for(int j=0;j<10;j++)
{
	pthread_create(&thread[j] ,NULL ,MySumFunction, (void*) NULL);
	
	
}

for(int j=0;j<10;j++)
{
	
	pthread_join(&thread[j], NULL);
	
	
}

printf("%i",sum);
return 0;
}

void *MySumFunction(void *arg)
{
    int sta,lim;
    
	sta = a*100;
	lim = sta+100;
	for(int i=sta;i<lim;i++)
	{
	   sum = sum + i;
	   
	}
	a++;
	
}
