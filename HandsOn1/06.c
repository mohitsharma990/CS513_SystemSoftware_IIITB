/*
============================================================================
Name : 06.c
Author : Mohit Sharma
Description : Write a program to take input from STDIN and display on STDOUT. Use only read/write system calls
Date: 24th Aug, 2024.
============================================================================
*/

#include <stdio.h> // import printf and perror and fflush functions
#include <unistd.h> // import for 'read' & 'write' system calls

int main(int argc, char *argv[]) {

  char buffer[50];
  int szRead = read(0, buffer, 25);
  fflush(stdout); // flushes the output buffer
  write(1, buffer, szRead);

  return 0;
}

/*
============================================================================
Command line : ./a.out
My name is Mohit Sharma.
Output : My name is Mohit Sharma.
============================================================================
*/
