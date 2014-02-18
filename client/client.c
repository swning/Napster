#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <Linux/in.h>


#define PORK 8888
#define IP_ADDR "192.186.23.4"

int main()
{
	int server_sock,client_sock;
	struct socketaddr_in server_addr; // not server it should be local
	struct sockeraddr_in client_addr;
 	int err;
	char buff[1000];
	pid_t pid;

	server_sock = socket(AF_INET,SOCK_DGRAM,0);
	if(server_sock < 0)
	{
		printf("socket error \n");
		return 0;
	}
	bzero(&server_addr,sizeof(sockaddr_in));
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = htonl(IP_ADDR);
	server_addr.sin_port = htons(PORT);
	 
	err = bind(server_sock,(struct sockaddr*)&server_addr,sizeof(struct sockaddr));
	if(err < 0)
	{
		printf("bind error \n");
		return 0;
	}

	pid = fork();

	if(pid == 0)
	{
		close(server_sock);
		process_server(server_sock);
	}
	else
	{
		// here need its IP and PORT
		
	}
}
