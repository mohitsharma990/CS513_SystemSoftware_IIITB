/*
============================================================================
Name : 04.c
Author : Mohit Sharma
Description : Write a program to open an existing file with read write mode. Try O_EXCL flag also.
Date: 24th Aug, 2024.
============================================================================
*/

#include <stdio.h> // import perror and printf
#include <fcntl.h> // import 'open' system call

int main(int argc, char *argv[]) {
  
  if(argc != 2) {
    printf("Enter the file name in the arguments to open it\n");
    return 0;
  }

  int fd = open(argv[1], O_RDWR | O_EXCL); // O_RDWR will open the file in read and write mode and using O_EXCL (exclusive) with it means if file already exits it this system call will return -1 as fd;
  
  if(fd == -1) {
    perror("error occured\n");
  }
  else {
    printf("Successfully opened\n");
  }

  return 0;
}

/*
============================================================================
command line : ./a.out 
Output : Successfully opened
============================================================================
*/
