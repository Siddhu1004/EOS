#include<stdio.h>
#include<unistd.h>
#include <pthread.h>


typedef struct sum{
int start;
int end;
int sumall;
}sum_t;
void* sum(void *para)
{
	sum_t *s=(sum_t*)para;
	s->sumall=0;
	for (int i=s->start;i<=s->end;i++)
	{
	    s->sumall=s->sumall+i;
	}
	return NULL;
}

int main()
{
	pthread_t th1;
	sum_t s1;
	printf("ENter the starting num1\n");
	scanf("%d",&s1.start);
	printf("Enter the end num2\n");
	scanf("%d",&s1.end);
	pthread_create(&th1,NULL,sum,&s1);
	pthread_join(th1,NULL);
	printf("the calc of %d to %d in thread is %d\n",s1.start,s1.end,s1.sumall);
	getchar();

return 0;
}


