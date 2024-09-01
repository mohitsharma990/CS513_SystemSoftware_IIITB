/*
============================================================================
Name : 20.c
Author : Mohit Sharma
Description : Find out the priority of your running program. Modify the priority with nice comman
Date: 30st Aug, 2024.
============================================================================
*/

#include <stdio.h>       // For printf()
#include <unistd.h>      // For getpid() and nice()
#include <sys/resource.h>// For getpriority() and PRIO_PROCESS

int main(int argc, char *argv[]) {
  
  int pid = getpid();
	int niceVal = getpriority(PRIO_PROCESS, 0);
	
	printf("Priority of process with PID %d is %d\n", pid, niceVal);
	
	nice(10); // updating the priority(nice value) to 10 of the current process 
	niceVal = getpriority(PRIO_PROCESS, 0); //first argument : priority of the process is being queried , second argument : 0 : means we are refering to the current process

	
	printf("Modified priority of process %d\n", niceVal);

  return 0;
}

/*
============================================================================
Output : 
./a.out                                                                           ─╯
Priority of process with PID 65283 is 0
Modified priority of process 10 
============================================================================
*/
