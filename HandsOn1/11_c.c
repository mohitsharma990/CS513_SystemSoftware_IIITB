/*
============================================================================
Name : 11_c.c
Author : Mohit Sharma
Description : Write a program to open a file, duplicate the file descriptor and append the file with both the
              descriptors and check whether the file is updated properly or not.
                  c. use fcntl 
Date: 29th Aug, 2024.
============================================================================
*/

#include <stdio.h> //import printf 
#include <fcntl.h> //import open system call 
#include <unistd.h> //import fcntl system call 

int main(int argc, char *argv[]) {
  
  if(argc != 2) {
    printf("enter the file name as argument\n");
    return 0;
  }

  int fd = open(argv[1], O_WRONLY | O_APPEND);
  int fd_duplicate = fcntl(fd, F_DUPFD, 0);  // fcntl function will search for the lowest available file descriptor greater than or equal to this number.

  write(fd, "writing to original fd\n", 23);
  write(fd_duplicate, "writing to the duplicate fd\n", 28);

  return 0;
}

/*
============================================================================
command line : ./a.out file.txt
cat file.txt
output :
Hello world // this text already exits inside the file
writing to original fd 
writing to the duplicate fd
============================================================================
*/
