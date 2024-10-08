/*
============================================================================
Name : 20w.c
Author : Mohit Sharma
Description : Write two programs so that both can communicate by FIFO -Use one way communication.
Date: 19 Sept 2024
============================================================================
*/

#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main() {
	int fd = open("myFifo", O_WRONLY);
	if(fd == -1) {
		perror("Couldn't open");
		exit(1);
  }

	char buf[] = "Hello how are you!!";
	printf("Write is going to send data to read file\n");
	write(fd, &buf, sizeof(buf));
	return 0;
}

/*
============================================================================
Command line: ./20w
Output: 
Write is going to send data to read file
============================================================================
*/
