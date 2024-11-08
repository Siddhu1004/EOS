#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
int main()
{
for(int i=1;i<=5;i++)
{
	if(fork()==0)
	{
		printf("parent=%d\n",getppid());
		for(int j=1;j<=5;j++)
		{
		printf("count: %d child id:%d\n",j,getpid());
		sleep(1);
		}
		_exit(7);//agr ye nhi lgaya to parent change horha mtlb child 1 parent ban rha
	}
else
	wait(NULL);// Wait for the child process to finish
}
return 0;
}
