/*
============================================================================
Name : 24.c
Author : Mohit Sharma
Description :  Write a program to create an orphan process.
Date: 31st Aug, 2024.
============================================================================
*/

#include <stdio.h>    // For printf()
#include <unistd.h>   // For fork(), getpid(), getppid(), sleep()

int main(int argc, char *argv[]) {
  
  int cpid = fork();
	if(cpid == 0){
		printf("Child process ID: %d and parent process ID: %d\n", getpid(), getppid());
		sleep(20);
	}
	printf("Current process ID: %d and child process ID: %d\n", getpid(), cpid);
  
  return 0;
}

/*
============================================================================
Output : Current process ID: 67586 and child process ID: 67587
Child process ID: 67587 and parent process ID: 67586
Current process ID: 67587 and child process ID: 0
============================================================================
*/
