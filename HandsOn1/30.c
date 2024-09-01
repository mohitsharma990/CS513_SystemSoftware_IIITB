/*
============================================================================
Name : 30.c
Author : Mohit Sharma
Description :  Write a program to run a script at a specific time using a Daemon process.


Date: 31st Aug, 2024.
============================================================================
*/

#include <stdio.h>      // For printf()
#include <stdlib.h>     // For exit()
#include <unistd.h>     // For fork(), setsid(), sleep(), getpid()
#include <fcntl.h>      // For open()

int main(){
	int childPid = fork(); // creating a child process 
	if(childPid == -1){ //fork failed
		printf("Fork issue occurred\n");
		exit(1);
	}
	else if(childPid > 0){ //this condition means the code is running inside the parent process. 
                        // The parent prints the child process’s ID and then exits. This allows the child process to continue running in the background.
		printf("Child process ID: %d\n", childPid);
		exit(0); // parent process will return 
	}

  // The setsid() call makes the child process the leader of a new session and a new process group. 
  // It also detaches the process from any terminal, ensuring it runs independently as a background process.
	if(setsid() < 0){
		printf("Session issue occurred\n");
		exit(1);
	}
  
  // Work daemon process will be doing 
  int fd = open("logfile_30.txt", O_CREAT|O_RDWR, S_IRWXU);
	if(fd == -1){
		printf("Error opening the logfile\n");
		exit(1);
	}

  write(fd, "HI\n", sizeof("HI\n"));
	while(1){
		sleep(10);
		write(fd, "HI\n", sizeof("HI\n")); 
	}

	close(fd); // due to the infinite loop this line will be never reached
	
	return 0;
}

/*
============================================================================
Output :
./a.out
Child process ID: 76158


cat logfile_30.txt                                                                                                                                      ─╯
HI
HI
HI
HI
HI
HI
HI


kill 76158
============================================================================
*/
