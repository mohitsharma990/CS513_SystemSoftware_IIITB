/*
Write a program to perform mandatory locking.
a. Implement write lock
*/

//Name : Mohit Sharma
//Roll no : MT2024091

#include <stdio.h> //import printf and getchar
#include <fcntl.h> //import fcntl function, open system call, struct flock structure
#include <stdlib.h> //import exit defination 
#include <unistd.h> //import getpid function, which retrives the process id 

int main(int argc, char *argv[]) {
  
  if(argc != 2) {
    printf("enter the file name\n");
    exit(EXIT_FAILURE);
  }

  int fd = open(argv[1], O_RDWR);
  if(fd == -1) {
    printf("error opening the file\n");
    exit(EXIT_FAILURE);
  }

  struct flock mylock;  //defining the file lock 
  mylock.l_type = F_WRLCK; // write lock 
  mylock.l_whence = SEEK_SET; //  The lock's starting point is relative to the start of the file.
  mylock.l_start = 0; // beginning of the file lock starts 
  mylock.l_len = 0; // means the lock applies to the entire file 
  mylock.l_pid = getpid(); // storing the process id for reference 

  printf("Before the critical section\n");
  fcntl(fd, F_SETLKW, &mylock); // fcntl is used to apply the lock described by the mylock 
  // F_SETLKW: This command waits until the lock can be acquired if it's currently held by another process. Once acquired, the process enters the critical section.
    
  printf("Inside the CS\n");
  printf("Press enter to exit the CS\n");
  getchar();
  
  //releasing the write lock 
  mylock.l_type = F_UNLCK;
  fcntl(fd, F_SETLK, &mylock);
  printf("Done with the critical section\n");
  printf("Exiting\n");

  return 0;
}

// command line : ./a.out file.txt
// output : 
/* 
Before the critical section
Inside the CS
Press enter to exit the CS
*/

//another terminal : 
//command line : ./a.out file.txt
//output : Before the critical section
