#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main() {
    int fd, ret;
    char buf1[32],buf3[32];
    char num1[16], num2[16];
    
    fd = open("/tmp/myfifo", O_WRONLY);
    if(fd < 0) {
        perror("open() failed");
        _exit(1);
    }

    printf("p1: enter num1: ");
    scanf("%s", num1);
    printf("enter num2: ");
    scanf("%s", num2);

    sprintf(buf1, "%s %s", num1, num2);//store krega num1 and num 2 ko buff me

    ret = write(fd, buf1, sizeof(buf1));
    printf("p1: message sent: %d bytes\n", ret);

//read krne ke liye fir se open kri file:
    fd = open("/tmp/myfifo", O_RDONLY);
    if(fd < 0) {
        perror("open() failed");
        _exit(1);
    }
	ret=read(fd,buf3,sizeof(buf3));
	int calc;
	sscanf(buf3,"%d",&calc);
	printf("the value calc by p2 is :%d\n",calc);
    close(fd);

    return 0;
}

