#include <stdio.h>
#include <unistd.h>
#include<sys/wait.h>

int main() {
    int ret, cnt = 0,s;
    while(1) {
        ret = fork();
        if(ret == -1) { // parent
            printf("fork() failed.\n");
            _exit(0);
        }
        else if(ret == 0) {
            // child process
			sleep(5);
            _exit(0);
        }
        else {
            // parent process
            cnt++;
            printf("child count: %d\n", cnt);
			 while (waitpid(-1, &s, WNOHANG) > 0)
			 {

			printf("exit status %d \n",WEXITSTATUS(s));
        }
    }
	}
    // cleanup all child processes
    //  hint: read about return value of wait()/waitpid() syscall.
    return 0;
}
