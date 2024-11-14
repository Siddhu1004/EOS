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
    int ret, serv_fd, cli_fd;
    struct sockaddr_in serv_addr, cli_addr;
    socklen_t socklen = sizeof(cli_addr);
     int arr[10];
    int arr1[10];
    //1. create server socket
    serv_fd = socket(AF_INET, SOCK_STREAM, 0);
    //2. bind the address
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(SERV_PORT);
    inet_aton(SERV_ADDR, &serv_addr.sin_addr);
    ret = bind(serv_fd, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
    //3. listen to server socket
    listen(serv_fd, 5);
    //6. accept client connection
    cli_fd = accept(serv_fd, (struct sockaddr*)&cli_addr, &socklen);
   
        //8. read data from client
        	printf("client:");
        read(cli_fd, arr, sizeof(arr));
		printf("client enter num1=%d,num2=%d\n",arr[0],arr[1]);
        int c=arr[0]+arr[1];
        arr1[0]=c;
        //9. send data to client
        printf("server: ");
   printf("server send addition %d\n",arr1[0]);
        write(cli_fd, arr1, sizeof(arr1));
    //12. close client socket
    close(cli_fd);
    //13. shutdown server socket
    shutdown(serv_fd, SHUT_RDWR);
    return 0;
}

