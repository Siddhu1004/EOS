#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include <fcntl.h>

//for different send receive we have to use two different pipe.:

int main()
{
	int arr[2];
	int arr1[2];
	int buff1[32];
	int buff2[32];
	pipe(arr);
	pipe(arr1);
	int pid=fork();
	if(pid==0)
	{
	//writing
	close(arr[0]);//read
	printf("ENter the num1\n");
	scanf("%d",&buff1[0]);
	printf("Enter the num2\n");
	scanf("%d",&buff1[1]);
	int fd=write(arr[1],buff1,sizeof(buff1));//1st write
	if(fd<0)
	perror("failed\n");

	read(arr1[0],buff2,sizeof(buff2));//2nd read
	printf("calc=%d\n",buff2[0]);
	}
	else
	{
	read(arr[0], buff1, sizeof(buff1));//1st read

		int a=buff1[0];
		int b=buff1[1];
		int c=a+b;
		buff2[0]=c;

write(arr1[1],buff2,sizeof(buff2));//2nd write
}
return 0;
}





