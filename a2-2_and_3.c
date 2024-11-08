#include<stdio.h>
#include <sys/types.h>
#include <signal.h>
#include<unistd.h>
#include<sys/wait.h>
int main(){
	int pid1,pid2,pid3,s;

	pid1=fork();
	if(pid1==0)
	{
		char *args[]={"gcc","./circle.c","-o","circle.out",NULL};//(exename,arguments)
		int err=execvp("gcc",args);//exename,args
		if(err<0)
		{
			perror("exec() failedi");
			_exit(7);
		}
		_exit(1);
	}


	/*1st step:fork create,always make args array of pointer.
step2:argu me gcc as exe namee then circle.c ,-o etc as argument
then repeat the step for all.
	 */
	pid2=fork();
	if(pid2==0)
	{
		char *args[]={"gcc","./square.c","-o","square.out",NULL};
		int err=execvp("gcc",args);
		if (err<0)
		{
			perror("failed pid2\n");
			_exit(0);
		}
		_exit(1);
	}

	pid3=fork();
	if(pid3 ==0)
	{
		char *args[]={"gcc","./rec.c","-o","rectangle.out",NULL};
		int err=execvp("gcc",args);//exename,args
		if(err<0)
		{
			perror("fail\n");
			_exit(7);

		}
		_exit(3);
	}

	waitpid(pid1,&s,0);
	if(WIFEXITED(s))
	{
		printf("circle exit\n ");
		sleep(1);
	}

	waitpid(pid2,&s,0);
	if(WIFEXITED(s))
	{
		printf("rectangle exit\n ");
		sleep(1);
	}

	waitpid(pid3,&s,0);
	if(WIFEXITED(s))
	{
		printf("square exit\n ");
		sleep(1);
	}

	int pid4,pid5,pid6;

	pid4=fork();
	if(pid4==0)
	{
		int err=execl("./circle.out","circle.out",0,NULL);
		if(err<0)
		{
			perror("failed pid 4\n");
			_exit(4);
		}

	}

	waitpid(pid4,&s,0);
	pid5=fork();
	if(pid5==0)
	{
	printf("-----------------------rectangle program-----------------------");
		int err=execl("./rectangle.out","rectangle.out",0,NULL);
		if(err<0)
		{
			perror("failed pid 5\n");
			_exit(4);
		}

	}
	waitpid(pid5,&s,0);
	
pid6=fork();
	if(pid6==0)
	{
	printf("-----------------------square program-----------------------");
		int err=execl("./square.out","square.out",0,NULL);
		if(err<0)
		{
			perror("failed pid 6\n");
			_exit(4);
		}

	}
	waitpid(pid6,&s,0);
	return 0;
}
