/*
============================================================================
Name : 01c.c
Author : Mohit Sharma
Description : Write a separate program (for each time domain) to set a interval timer in 10sec and
              10micro second
                    a. ITIMER_REAL
                    b. ITIMER_VIRTUAL
                    c. ITIMER_PROF
Date: 17 Sept 2024
============================================================================
*/
#include <stdio.h> 
#include <signal.h> 
#include <sys/time.h> 
#include <unistd.h> 
#include <fcntl.h>

void timer_handler(int signum) {
  static int count = 0;
  printf("Prof Timer expired %d times\n", ++count);
  return;
}

int main() {
  struct itimerval timer;

  // Setting up the signal handler for SIGPROF
  signal(SIGPROF, timer_handler);

  // Configuring the timer to expire after 10 secs and 10 microseconds
  timer.it_value.tv_sec = 10;
  timer.it_value.tv_usec = 10;

  // Configure interval between each timer expiration
  timer.it_interval.tv_sec = 10;
  timer.it_interval.tv_usec = 10;

  if (setitimer(ITIMER_PROF, &timer, NULL) == -1) {
    perror("Error setting the prof timer\n");
    return 1;
  }

  // Simulate CPU load and frequent system calls to generate both user and system time activity
  int fd = open("/dev/null", O_WRONLY); // Open /dev/null to use for write system calls

  while (1) {
    // Busy loop to generate CPU activity (user mode)
    for (volatile int i = 0; i < 1000000; i++);

    // Perform system call to generate kernel mode activity
    if (fd >= 0) {
      write(fd, "test", 4);  // Writing to /dev/null generates system activity
    }
  }

  close(fd);
  return 0;
}

/*
============================================================================
Command line: ./a.out
Output : 
Prof Timer expired 1 times
Prof Timer expired 2 times
Prof Timer expired 3 times
Prof Timer expired 4 times
Prof Timer expired 5 times
Prof Timer expired 6 times
Prof Timer expired 7 times
^C
============================================================================
*/
