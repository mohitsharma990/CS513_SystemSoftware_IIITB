// Write a program to create a file and print the file descriptor value. Use creat ( ) system call
// Name : Mohit Sharma
// Roll no : MT2024091

#include <stdio.h> // imported for perror and printf 
#include <fcntl.h> // imported for 'creat' system call 


int main(int argc, char *argv[]) {

  if(argc != 2) {
    printf("Enter the file name as an argument that you want to create\n");
    return 0;
  }
    
  int fd = creat(argv[1], S_IRWXU); // first argument : file name, second argument : read write execute permission to user (same as 0700)


  if(fd != -1) {
    printf("Succesfully created\n");
    printf("File '%s' created with fd '%d'\n", argv[1], fd);
  }
  else {
    perror("error occurred\n");
  }

  return 0;
}

// command line : ./a.out newFile
// output : Succesfully created
// File 'newFile' created with fd '3'
