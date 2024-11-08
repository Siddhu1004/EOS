#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
	int pid1,pid2,pid3,s,i;
	pid1=fork();
	if(pid1==0)
	{
	for(i=0;i<5;i++)
	{
		printf("child1: %d,id=%d\n",i,getpid());
		sleep(1);
	}
	_exit(7);
	}

pid2=fork();
	if(pid2==0)
	{
	for(i=0;i<5;i++)
	{
		printf("child2: %d,id=%d\n",i,getpid());
		sleep(1);
	}
	_exit(7);
	}
pid3=fork();
	if(pid3==0)
	{
	for(i=0;i<5;i++)
	{
		printf("child3: %d,id=%d\n",i,getpid());
		sleep(1);
	}
	_exit(7);
	}

//parent continues

for(i=0;i<5;i++)
{
	printf("the parent (%d) =%d\n",getpid(),i);
	sleep(1);
}
	while(waitpid(-1,&s,0)>0)
		printf("exit status is %d\n",WEXITSTATUS(s));
	

return 0;
}
