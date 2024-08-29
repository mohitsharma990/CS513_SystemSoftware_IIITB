// Write a program to create five new files with infinite loop. Execute the program in the background
// and check the file descriptor table at /proc/pid/fd.
// Name : Mohit Sharma
// Roll No : MT2024091

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

// Command line : ./a.out file1 file2 file3 file4 file5
// output : 
