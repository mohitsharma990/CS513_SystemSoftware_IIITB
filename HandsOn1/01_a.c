/*
============================================================================
Name : 01_a.c
Author : Mohit Sharma
Description : Create a soft link file using the 'symlink' system call.
Date: 20 Aug, 2024.
============================================================================
*/

#include<unistd.h> // to import symlink system call
#include<stdio.h> // to import perror & printf

int main(int argc, char *argv[]) {
  if(argc != 3) {
    printf("error : Pass the source file & it's softlink file name in the argument\n");
    return 0;
  }

  if(symlink(argv[1], argv[2]) == 0) {
    printf("Softlink for the given file created sucessfully\n");
  }
  else {
    perror("Error occured\n");
  }

  return 0;
}

/*
============================================================================
Command line: ./a.out file softlink
Output: Softlink for the given file created sucessfully
============================================================================
*/
