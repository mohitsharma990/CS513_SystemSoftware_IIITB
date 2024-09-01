/*
============================================================================
Name : 11_b.c
Author : Mohit Sharma
Description : Write a program to open a file, duplicate the file descriptor and append the file with both the
              descriptors and check whether the file is updated properly or not.
              b. use dup2
Date: 29th Aug, 2024.
============================================================================
*/

#include <stdio.h> //import printf 
#include <unistd.h> //import write and dup2 system calls
#include <fcntl.h> //import open system call 

int main(int argc, char *argv[]) {
  
  if(argc != 2) {
    printf("enter file name as an argument\n");
    return 0;
  }

  int fd = open(argv[1], O_WRONLY | O_APPEND);
  int fd_duplicate = dup2(fd, 111); // parameters passed : old fd , new fd and here the dup2 will return 111 only 
 
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
