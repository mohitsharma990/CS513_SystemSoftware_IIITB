/*
Write a program to simulate online ticket reservation. Implement write lock
Write a program to open a file, store a ticket number and exit. Write a separate program, to
open the file, implement write lock, read the ticket number, increment the number and print
the new ticket number then close the file.
*/

// Name : Mohit Sharma
// Roll no : MT2024091

#include <stdio.h> // import printf, perror
#include <fcntl.h> // import open  system call 
#include <stdlib.h> // import exit 
#include <unistd.h> // import write and close system call 

int main(int argc, char *argv[]) {
  if(argc != 2) {
    printf("enter the file name in the argument to store the ticket number\n");
    return 0;
  }

  int fd = open(argv[1], O_RDWR);
  if(fd == -1) {
    printf("Error occurred\n");
    exit(EXIT_FAILURE);
  }
  
  struct flock mylock;
  mylock.l_type = F_WRLCK;
  mylock.l_whence = SEEK_SET;
  mylock.l_start = 0;
  mylock.l_len = 0;
  mylock.l_pid = getpid();

  printf("Before entering into the critical section\n");
  fcntl(fd, F_SETLKW, &mylock);

  printf("Entered inside the critical section\n");
  int count;
  read(fd, &count, sizeof(count));
  count++;
  printf("Current ticket number is : %d\n", count);
  
  lseek(fd, 0L, SEEK_SET); // lseek is used to reposition the file offset : moves the file pointer (the file offset) to the beginning of the file (0 bytes from the start).
  write(fd, &count, sizeof(count));

  printf("Press enter to come out of the critical section\n");
  getchar();

  mylock.l_type = F_UNLCK;
  fcntl(fd, F_SETLK, &mylock);
  printf("Out of the CS. Exiting\n");
  close(fd);

  return 0;
}

/*
./a.out tickets                                                                   ─╯
Before entering into the critical section
Entered inside the critical section
Current ticket number is : 49
Press enter to come out of the critical section
*/

//another terminal
/*
./a.out tickets                                                                                                                                         ─╯
Before entering into the critical section
*/
