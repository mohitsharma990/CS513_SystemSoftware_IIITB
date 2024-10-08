/*
============================================================================
Name : 23.c
Author : Mohit Sharma
Description : Write a program to print the maximum number of files can be opened within a process and
size of a pipe (circular buffer).
Date: 20 Sept 2024
============================================================================
*/

#include<unistd.h>
#include<stdio.h>

int main() {
	long maxOpen, size;
	size = pathconf("myFifo", _PC_PIPE_BUF);
	maxOpen = sysconf(_SC_OPEN_MAX);

	printf("Max size of pipe is: %ld and max number of files which can be opened in a process is: %ld\n", size, maxOpen);

	return 0;
}

/*
============================================================================
Command line: ./a.out 
Output: 
Max size of pipe is: 512 and max number of files which can be opened in a process is: 256
============================================================================
*/
