#include<stdio.h>
#include <sys/types.h>
#include <signal.h>
#include<unistd.h>

int main()
{

	int b;
	int a;
	printf("Enter the process id\n ");
	scanf("%d",&b);
	printf("Enter the kill process number\n");
	scanf("%d",&a);
	int k=kill(b,a);
	if(k=0)
	{
	printf("the process is killed\n");
	}
	else
	printf("not killed\n");

return 0;
}


