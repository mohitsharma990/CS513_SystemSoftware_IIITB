/*
============================================================================
Name : 14.c
Author : Mohit Sharma
Description :  Write a program to find the type of a file.
                a. Input should be taken from command line.
                b. program should be able to identify any type of a file.
Date: 29th Aug, 2024.
============================================================================
*/

#include <stdio.h> //import perror and printf 
#include <sys/stat.h> //import stat system call 
#include <stdlib.h> //import exit function


int main(int argc, char *argv[]) {
  if(argc != 2) {
    printf("enter file name in the argument\n");
    return 0;
  }
  
  struct stat fileDetails;
  if(stat(argv[1], &fileDetails) == -1){ // stat func retrives info about the given file and stores it in the fileDetails struct variable
		perror("Error occurred\n");
    exit(EXIT_FAILURE); // error handling
	}
  
  printf("Type of the file: %d\n", fileDetails.st_mode); //st_mode field contains info about the file's type and permissions
  
  if(S_ISREG(fileDetails.st_mode)) {
    printf("Its a regular file\n");
  }
  else if(S_ISDIR(fileDetails.st_mode)) {
    printf("Its a directory\n");
  }
  else if(S_ISBLK(fileDetails.st_mode)) {
    printf("Its a block device file\n");
  }
  else if(S_ISCHR(fileDetails.st_mode)) {
    printf("Its a character device file\n");
  }
  else if(S_ISFIFO(fileDetails.st_mode)) {
    printf("Its a named pipe\n");
  }
  else if(S_ISLNK(fileDetails.st_mode)) {
    printf("Its a symbolic link file\n");
  }
  else if(S_ISSOCK(fileDetails.st_mode)) {
    printf("Its a socket file\n");
  }
  else {
    printf("Unknown file type\n");
  }

  return 0;
}

/*
============================================================================
command line : ./a.out file.txt
output : Type of the file: 33188 //combination of file type and file permission in decimal format
Its a regular file 
============================================================================
*/
