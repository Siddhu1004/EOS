#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<sys/wait.h>
#include<signal.h>

// input a command string from user, split it into multiple tokens using strtok() and
// store their addresses into array of char*.
// e.g. "ls -l -a /home" --> "ls", "-l", "-a", "/home" --> [ad1, ad2, ad3, ad4, NULL]


void sigt(int sig)
{
}
int main()
{
	int s;
	int ret;
	char cmd[512];
	char *args[32];
	char *ptr;
	signal(SIGINT,sigt);
	while(1){
		printf("cmd> ");
		gets(cmd);//gets for string
		int i=0;
		ptr=strtok(cmd," ");
		args[i]=ptr;
		i++;
		do{
			ptr=strtok(NULL," ");//next next krega andar ki value
			args[i]=ptr;//1st value is me
			i++;
			}	while(ptr!=NULL);
		if(strcmp(args[0],"exit")==0)
		_exit(0);
			ret=fork();
	if(ret==0)
			{
			int err=execvp(args[0],args);//child ke andar dala execvp kyuki
			//alg alg process create krne ke liye.
			if(err<0)
			{
			perror("failed");
			_exit(1);
			}
			}
	else
	waitpid(-1,&s,0);
		}

	return 0;
			}


