/*
============================================================================
Name : 23.c
Author : Mohit Sharma
Description :  Write a program to create a Zombie state of the running program.
Date: 30st Aug, 2024.
============================================================================
*/

#include <stdio.h> // for printf()
#include <stdlib.h> // for exit()
#include <unistd.h> // for sleep(), getpid(), getppid(), fork()

int main(int argc, char *argv[]) {
  
  int cpid = fork();
  //child process execution ie if cpid = 0 ie the code is running in the child process 
	if(cpid == 0){
		printf("Child process ID: %d and parent process ID: %d\n", getpid(), getppid());
		exit(0); //exits immediately
	}
  //back to parent process 
	printf("Current process ID: %d and child process ID: %d\n", getpid(), cpid);
	sleep(20);

  return 0;
}

//info : 
//A zombie state is when a completed child process still has an entry in the process table because the parent hasn’t yet retrieved its exit status.

/*
============================================================================
Output :

./a.out                                                                           ─╯
Current process ID: 67027 and child process ID: 67031
Child process ID: 67031 and parent process ID: 67027

============================================================================
*/
