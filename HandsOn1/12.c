/*
============================================================================
Name : 12.c
Author : Mohit Sharma
Description : Write a program to find out the opening mode of a file. Use fcntl.
Date: 29th Aug, 2024.
============================================================================
*/

#include <stdio.h> //import printf 
#include <fcntl.h> //import open and fcntl system calls 

int main(int argc, char *argv[]) {
  
  if(argc != 2) {
    printf("enter file name as an argument\n");
    return 0;
  }

  int fd = open(argv[1], O_RDWR, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH); // third argument is the file permissions which ll be assigned to a new file if the file doesn't exist already
  
  int mode = fcntl(fd, F_GETFL); //F_GETFL is used to get the file status flag

  printf("opening mode of the file is : %d\n", mode);

  return 0;
}

/* 
   0    = O_RDONLY
   1    = O_WRONLY
   2    = O_RDWR
*/

/*
============================================================================
command line : ./a.out file.txt
output : 2 // means in read write mode 
============================================================================
*/
