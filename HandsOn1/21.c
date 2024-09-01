/*
============================================================================
Name : 21.c
Author : Mohit Sharma
Description : Write a program, call fork and print the parent and child process id.
Date: 30st Aug, 2024.
============================================================================
*/

#include <stdio.h>   // For printf()
#include <unistd.h>  // For fork(), getpid(), and getppid()

int main(int argc, char *argv[]) {
  
  int childPid = fork(); //Fork system call is used to create a new child process 
	// If fork() is successful, it returns the child’s process ID (PID) to the parent process and 0 to the child process.

  if(childPid == 0){ // checks if the process is the child process (because fork() returns 0 in the child).
    printf("Child process ID: %d and parent process ID: %d\n", getpid(), getppid());
    return 0; // child process will terminate here and then ll return back to the parent process.
  }
  printf("Current process ID: %d and child process ID: %d\n", getpid(), childPid);

  return 0;
}


/*
============================================================================
Output :
./a.out                                                                           ─╯
Current process ID: 65671 and child process ID: 65672
Child process ID: 65672 and parent process ID: 65671  
============================================================================
*/
