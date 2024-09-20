/*
============================================================================
Name : 34a_client.c
Author : Mohit Sharma
Description : Write a program to create a concurrent server.
                  a. use fork
                  b. use pthread_create
Date: 21 Sept 2024
============================================================================
*/

/*
    1. socket() -> create an endpoint for the communication
        sockfetfd = socket(AF_INET, SOCK_STREAM, 0);
    2. connect() -> initiate a connection to a socket
        connectionStatus = connect(socketfd, &socketaddr, sizeof(socketaddr));
    3. Start communicating -> `write` to and `read` from socketfd
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
#include<sys/time.h>
#include<sys/resource.h>
#include<sys/ipc.h>
#include<sys/sem.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>

int main(){
	struct sockaddr_in serv, cli;
	
	int sd = socket(AF_INET, SOCK_STREAM, 0);
	if(sd < 0){
		perror("Unable to create socket. \n");
		exit(0);
	}
	
	bzero(&serv, sizeof(serv));
	
	serv.sin_family = AF_INET;
	serv.sin_addr.s_addr = inet_addr("127.0.0.1");
	//serv.sin_addr.s_addr = INADDR_ANY;
	serv.sin_port = htons(7229);
	
	if(connect(sd, (struct sockaddr*) &serv, sizeof(serv)) < 0)
		printf("Unable to connect to server\n");
	else
		printf("Connected to server. \n");
	
	char buf[1024];
	int len = sizeof(cli);
	while(strcmp(buf, "end") != 0){
		bzero(&buf, sizeof(buf));
		read(sd, buf, sizeof(buf));
		printf("Message from server: %s\n", buf);
		bzero(buf, sizeof(buf));
		printf("\nEnter the message: ");scanf(" %[^\n]", buf);
		write(sd, buf, sizeof(buf));
	}
	
	close(sd);
	return 0;
}

/*
============================================================================
Command line: ./a_client 
Output: 
Connected to server. 
Message from server: Connection established

Enter the message: Hello, how are you?
Message from server: I am good!

Enter the message: Okay nice
Message from server: yeah

Enter the message: ^C
============================================================================
*/
