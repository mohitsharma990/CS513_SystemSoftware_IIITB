/*
============================================================================
Name : 20r.c
Author : Mohit Sharma
Description : Write two programs so that both can communicate by FIFO -Use one way communication.
Date: 20 Sept 2024
============================================================================
*/

#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main() {
	int fd = open("myFifo", O_RDONLY);
	if(fd == -1) {
		perror("Couldn't open");
		exit(1);
	}

	char buf[100];
	int c = read(fd, buf, 100);
	printf("Message is %d character long and it says: %s\n", c, buf);
	return 0;
}

/*
============================================================================
Command line: ./20r 
Output: 
Message is 20 character long and it says: Hello how are you!!
============================================================================
*/
