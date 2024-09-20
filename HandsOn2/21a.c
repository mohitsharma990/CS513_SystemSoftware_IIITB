/*
============================================================================
Name : 21a.c
Author : Mohit Sharma
Description : Write two programs so that both can communicate by FIFO -Use two way communications.
Date: 20 Sept 2024
============================================================================
*/

#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main() {
	int fd = open("myFifo", O_WRONLY);
	int fd2 = open("mknodFifo", O_RDONLY);
	if(fd == -1 || fd2 == -1) {
		perror("Couldn't open");
		exit(1);
	}

	char buf[100] = "Hello how are you!!";
	write(fd, &buf, sizeof(buf));
	read(fd2, &buf, 100);
	printf("Message received in a: %s\n", buf);
	return 0;
}

/*
============================================================================
Command line: ./21a 
Output:
Message received in a: I am fine!!
============================================================================
*/
