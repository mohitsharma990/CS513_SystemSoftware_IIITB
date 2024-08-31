/*
============================================================================
Name : 25.c
Author : Mohit Sharma
Description :  Write a program to create three child processes. The parent should wait for a particular child (use
waitpid system call).
Date: 31st Aug, 2024.
============================================================================
*/

#include <stdio.h>     // For printf()
#include <unistd.h>    // For fork(), getpid(), getppid(), sleep(), waitpid()
#include <sys/wait.h>  // For WIFSIGNALED(), WEXITSTATUS()

int main(){
	
	int cid1, cid2, cid3;
	int status;
	printf("Main parent process ID: %d\n", getpid());
	cid1 = fork();
	if(!cid1){
		printf("Child process ID: %d and parent process ID: %d\n", getpid(), getppid());
		sleep(2);
	}
	else{
		cid2 = fork();
		if(!cid2){
			printf("Child process ID: %d and parent process ID: %d\n", getpid(), getppid());
			sleep(5);
		}
		else{
			cid3 = getpid();
			printf("Child process ID: %d and parent process ID: %d\n", getpid(), getppid());
			sleep(2);
		}
	}
	
	printf("Waiting for child....\n");
	waitpid(cid2, &status, 0);
	
	if(WIFSIGNALED(status)){
		printf("\nSignal interrupt");
	}
	else if(WEXITSTATUS(status)){
		printf("\nNormal exit");
	}
	printf("\nExiting");
	
	return 0;
}

/*
============================================================================
Output : Main parent process ID: 67906
Child process ID: 67906 and parent process ID: 48407
Child process ID: 67907 and parent process ID: 67906
Child process ID: 67908 and parent process ID: 67906
Waiting for child....

Signal interrupt
ExitingWaiting for child....
Waiting for child....

Signal interrupt
Exiting
Exiting
============================================================================
*/
