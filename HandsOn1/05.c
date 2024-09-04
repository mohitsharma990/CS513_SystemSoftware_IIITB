/*
============================================================================
Name : 05.c
Author : Mohit Sharma
Description :  Write a program to create five new files with infinite loop. Execute the program in the background
               and check the file descriptor table at /proc/pid/fd.
Date: 24th Aug, 2024.
============================================================================
*/

#include <stdio.h> // to import printf and perror
#include <fcntl.h> // to import 'creat' system call

int main(int argc, char *argv[]) {
    
  if(argc != 6) {
    printf("Enter 5 filenames as argument to create them\n");
    return 0;
  }

  for(int i=1; i<=5; i++) {
    int fd = creat(argv[i], S_IRWXU);
    if(fd == -1) {
      perror("Error occured\n");
    }
  }

  for( ; ; );

  return 0;
}

/*
============================================================================
Command line : ./a.out file1 file2 file3 file4 file5 &
output : [1] 14044 

lsof -p 14044

COMMAND   PID        USER   FD   TYPE DEVICE SIZE/OFF      NODE NAME
a.out   14044 mohitsharma  cwd    DIR   1,18      416    235269 /Users/mohitsharma/Desktop
a.out   14044 mohitsharma  txt    REG   1,18    50050 450335845 /Users/mohitsharma/Desktop/a.out
a.out   14044 mohitsharma    0u   CHR  16,28   0t4027     11875 /dev/ttys028
a.out   14044 mohitsharma    1u   CHR  16,28   0t4027     11875 /dev/ttys028
a.out   14044 mohitsharma    2u   CHR  16,28   0t4027     11875 /dev/ttys028
a.out   14044 mohitsharma    3w   REG   1,18        0 450335858 /Users/mohitsharma/Desktop/f1
a.out   14044 mohitsharma    4w   REG   1,18        0 450335859 /Users/mohitsharma/Desktop/f2
a.out   14044 mohitsharma    5w   REG   1,18        0 450335860 /Users/mohitsharma/Desktop/f3
a.out   14044 mohitsharma    6w   REG   1,18        0 450335861 /Users/mohitsharma/Desktop/f4
a.out   14044 mohitsharma    7w   REG   1,18        0 450335862 /Users/mohitsharma/Desktop/f5
============================================================================
*/
