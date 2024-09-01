/*
============================================================================
Name : 07.c
Author : Mohit Sharma
Description : Write a program to copy file1 into file2 ($cp file1 file2).
Date: 24th Aug, 2024.
============================================================================
*/

#include <stdio.h> // for printf and perror functions
#include <fcntl.h> // for open system call
#include <unistd.h> // for read, close system calls

int main(int argc, char *argv[]) {
  
  if(argc != 3) {
    printf("Enter the source and destination file names to copy the content");
    return 0;
  }

  int fd1 = open(argv[1], O_RDONLY);
  if(fd1 == -1) {
    perror("error occurred");
    return 0;
  }

  int fd2 = open(argv[2], O_WRONLY | O_CREAT | O_EXCL, S_IRWXU);
  if(fd2 == -1) {
    perror("error occurred");
    return 0;
  }

  char buffer[1024];
  int szRead;
/*
 This loop reads chunks of data from the file associated with fd1 and writes them to 
 the file associated with fd2. It continues doing this until all data from fd1 is read and written to fd2.
*/
  while((szRead = read(fd1, buffer, sizeof(buffer))) > 0) {
    write(fd2, buffer, szRead);
  }

  close(fd1);
  close(fd2);

  return 0;
}

/*
============================================================================
Command line : ./a.out file1 file2
============================================================================
*/
