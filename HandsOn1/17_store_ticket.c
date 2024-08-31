/*
Write a program to simulate online ticket reservation. Implement write lock
Write a program to open a file, store a ticket number and exit. Write a separate program, to
open the file, implement write lock, read the ticket number, increment the number and print
the new ticket number then close the file.
*/

// Name : Mohit Sharma
// Roll no : MT2024091

#include <stdio.h> // immport perror and printf 
#include <fcntl.h> // import open system call 
#include <stdlib.h> // import exit 
#include <unistd.h> // import write and close system call 

int main(int argc, char *argv[]) {
  if(argc != 2) {
    printf("enter the file name in the argument to store the ticket number\n");
    return 0;
  }
  
  int fd = open(argv[1], O_RDWR | O_CREAT, S_IRWXU | S_IRWXG);

  if(fd == -1) {
    perror("error occurred\n");
    exit(EXIT_FAILURE);
  }

  int count;
  printf("Enter ticket number: ");
  scanf("%d", &count);

  write(fd, &count, sizeof(count));

  close(fd);
  
  return 0;
}
