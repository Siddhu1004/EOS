#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <string.h>

#define SERV_ADDR   "192.168.138.86 "
#define SERV_PORT   2809

int main() {
    int ret, cli_fd;
    struct sockaddr_in serv_addr;
    int arr[10];
	int arr1[10];
    //4. create client socket
    cli_fd = socket(AF_INET, SOCK_STREAM, 0);
    //5. connect to server socket
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(SERV_PORT);
    inet_aton(SERV_ADDR, &serv_addr.sin_addr);
    ret = connect(cli_fd, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
 
        //7. send data to server
        printf("client: ");
        printf("ENter the num 1 and 2\n");
		scanf("%d %d",&arr[0],&arr[1]);
		write(cli_fd, arr, sizeof(arr));
        //10. read data from server
        read(cli_fd,arr1, sizeof(arr1));
		printf("addition from server is:%d\n", arr1[0]);
   
    //11. close client socket
    close(cli_fd);
    return 0;
}

