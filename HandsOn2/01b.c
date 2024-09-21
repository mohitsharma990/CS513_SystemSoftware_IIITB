/*
============================================================================
Name : 01b.c
Author : Mohit Sharma
Description : Write a separate program (for each time domain) to set a interval timer in 10sec and
              10micro second
                    a. ITIMER_REAL
                    b. ITIMER_VIRTUAL
                    c. ITIMER_PROF
Date: 17 Sept 2024
============================================================================
*/

#include <stdio.h> // for printf, perror
#include <signal.h> // for signal handling and SIGALRM
#include <sys/time.h> // for setitimer() and struct itimerval
#include <unistd.h> // for pause()

void timer_handler(int signum) {
  static int count = 0;
  printf("Virtual Timer expired %d times\n", ++count);
  return;
}

int main() {
  struct itimerval timer;

  //Setting up the signal handler for SIGVTALRM
  signal(SIGVTALRM, timer_handler);

  //Configuring the timer to expire after 10 secs and 10 microseconds
  timer.it_value.tv_sec = 10;  
  timer.it_value.tv_usec = 10;

  //Configure interval between each timer expiration
  timer.it_interval.tv_sec = 10; 
  timer.it_interval.tv_usec = 10;

  if(setitimer(ITIMER_VIRTUAL, &timer, NULL) == -1) {
    perror("Error setting the virtual timer\n");
    return 1;
  }

  // Busy loop to consume user mode CPU time
  while(1) {
    //Simulate CPU activity
  }

  return 0;
}

/*
============================================================================
Command line: ./a.out
Output : 
Virtual Timer expired 1 times
Virtual Timer expired 2 times
Virtual Timer expired 3 times
Virtual Timer expired 4 times
Virtual Timer expired 5 times
Virtual Timer expired 6 times
^C
============================================================================
*/
