#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main() {
    int fd, ret;
    char buf2[32],buf3[32];
    int a, b;
    
    fd = open("/tmp/myfifo", O_RDONLY);
    if(fd < 0) {
        perror("open() failed");
        _exit(1);
    }

    printf("p2: waiting for message...\n");
    ret = read(fd, buf2, sizeof(buf2));

    sscanf(buf2, "%d %d", &a, &b);
    int c = a + b;

    printf("c = %d\n", c);
	sprintf(buf3,"%d",c);
	//write krne ke liye fir se open ki
    fd = open("/tmp/myfifo", O_WRONLY);
    if(fd < 0) {
        perror("open() failed");
        _exit(1);
    }
	ret =write(fd,buf3,sizeof(buf3));


    close(fd);

    return 0;
}

