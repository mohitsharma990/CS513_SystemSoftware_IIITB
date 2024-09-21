/*
============================================================================
Name : 01a.c
Author : Mohit Sharma
Description : Write a separate program (for each time domain) to set a interval timer in 10sec and
              10micro second
                    a. ITIMER_REAL
                    b. ITIMER_VIRTUAL
                    c. ITIMER_PROF
Date: 12 Sept 2024
============================================================================
*/

#include <stdio.h> // for printf, perror
#include <signal.h> // for signal handling and SIGALRM
#include <sys/time.h> // for setitimer() and struct itimerval
#include <unistd.h> // for pause()

//Signal handler for SIGALRM (SIGALRM notifies a process when a timer runs out.)
void timer_handler(int signum) {
  static int count = 0;
  printf("Timer expired %d times\n", ++count);
  return;
}

int main() {
  struct itimerval timer;
  
  //Setting up the signal handler for SIGALRM
  signal(SIGALRM, timer_handler);
  
  //Configuring the timer to expire after 10 secs
  timer.it_value.tv_sec = 10;  //Intial delay
  timer.it_value.tv_usec = 10;
  
  //Configure interval between each timer expiration
  timer.it_interval.tv_sec = 10; // Periodic interval 
  timer.it_interval.tv_usec = 10;

  if(setitimer(ITIMER_REAL, &timer, NULL) == -1) {
    perror("Error setting the timer\n");
    return 1;
  }
  
  //Infinite loop to keep the program running and handle timer signals
  while(1) {
    pause(); //waiting for signals
  }

  return 0;
}


/*
============================================================================
Command line: ./a.out
Output : 
Timer expired 1 times
Timer expired 2 times
Timer expired 3 times
Timer expired 4 times
Timer expired 5 times
^C
============================================================================
*/
