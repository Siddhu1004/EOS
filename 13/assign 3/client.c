#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <string.h>

#define SOCK_FILE   "/tmp/mysock"

int main() {
    int ret, cli_fd;
    struct sockaddr_un serv_addr;
    int arr[10];
	int arr1[10];
    //4. create client socket
    cli_fd = socket(AF_UNIX, SOCK_STREAM, 0);
    //5. connect to server socket
    serv_addr.sun_family = AF_UNIX;
    strcpy(serv_addr.sun_path, SOCK_FILE);
    ret = connect(cli_fd, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
        //7. send data to server

    	printf("ENter the num 1 and 2\n");
		scanf("%d %d",&arr[0],&arr[1]);
		write(cli_fd, arr, sizeof(arr));
		//10. read data from server
	printf("server:");
		read(cli_fd,arr1, sizeof(arr1));
		printf("addition from server is:%d\n", arr1[0]);
	
	    //11. close client socket
    close(cli_fd);

    return 0;
}

