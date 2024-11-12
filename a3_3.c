#include <stdio.h>
#include <unistd.h>

int main() {
    int ret, arr[2];
    char buf1[]="a";
	ret=pipe(arr);
    if(ret < 0) {
        perror("pipe() failed");
        _exit(1);
    }
	int cnt=0;
    while(1)
	{
	//(int fd, const void *buf, size_t count);
    write(arr[1], buf1,1);
	printf("cnt=%d\n",cnt);
	cnt++;

	}

    return 0;
}
