/*
============================================================================
Name : 13.c
Author : Mohit Sharma
Description :  Write a program to wait for a STDIN for 10 seconds using select. Write a proper print statement to
               verify whether the data is available within 10 seconds or not (check in $man 2 select).
Date: 29th Aug, 2024.
============================================================================
*/

//'select' system call is used to monitor the file descriptors and determine if they have data available within a specified timeout period

#include <stdio.h> //import perror and printf 
#include <sys/select.h> //import select system call, fd_set, FD_ZERO, FD_SET 
#include <sys/time.h> //import timeval 

int main() {
  
  fd_set fd; // file descriptor set 
  FD_ZERO(&fd); // intitialized fd set to be empty 
  FD_SET(0, &fd); // Adds the file descriptor 0 (standard input, stdin) to the set of file descriptors to be monitored
  
  struct timeval t;
  t.tv_sec = 10; // sets the timeout to 10 seconds 
  t.tv_usec = 0; // sets the timeout to 0 microseconds 
  
  int retValue = select(1, &fd, NULL, NULL, &t); //monitors 1st file descriptor in the fd set, here NULL means : No file descriptors are monitored for writing or exceptional conditions.
  
  if (retValue == -1)
    perror("error\n");
  else if (retValue)
    printf("Data available\n");
  else {
    printf("No data was available within 10 seconds.\n");
  }

  return 0;
}

/*
============================================================================
command line : ./a.out
output : No data was available within 10 seconds.

command line : ./a.out
mohitsharma
output : Data available
============================================================================
*/
