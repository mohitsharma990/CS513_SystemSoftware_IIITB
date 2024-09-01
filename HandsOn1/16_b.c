/*
============================================================================
Name : 16_b.c
Author : Mohit Sharma
Description : Write a program to perform mandatory locking.
              b. Implement read lock
Date: 30st Aug, 2024.
============================================================================
*/

#include <stdio.h> //import printf and getchar, perror
#include <fcntl.h> //import fcntl function, open system call, struct flock structure
#include <stdlib.h> //import exit defination
#include <unistd.h> //import getpid function, which retrives the process id

/*
 In file locking, a read lock (also known as a shared lock) allows multiple processes to read from the file simultaneously, 
 but it prevents any process from writing to the file while the lock is held
*/

int main(int argc, char *argv[]) {
  
  int fd = open(argv[1], O_RDWR);
  if(fd == -1) {
    perror("error in opening the file\n");
    exit(EXIT_FAILURE);
  }

  struct flock mylock;
  mylock.l_type = F_RDLCK;
  mylock.l_whence = SEEK_SET;
  mylock.l_start = 0;
  mylock.l_len = 0;
  mylock.l_pid = getpid();
  
  printf("Before Critical section\n");
  fcntl(fd, F_SETLKW, &mylock);

  printf("Inside CS\n");
  printf("Press enter to exit from the CS\n");
  getchar();

  mylock.l_type = F_UNLCK;
  fcntl(fd, F_SETLK, &mylock);
  printf("Done with the CS. Exiting it\n");
  
  return 0;
}

/*
============================================================================
command line : ./a.out file.txt
output : 
Before the critical section
Inside the CS
Press enter to exit the CS 
============================================================================
*/

/*
============================================================================
another terminal : 
command line : ./a.out file.txt
output : Before the critical section
Inside the CS 
Press enter to exit from the CS
============================================================================
*/
