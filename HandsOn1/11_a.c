/*
Write a program to open a file, duplicate the file descriptor and append the file with both the
descriptors and check whether the file is updated properly or not.
a. use dup
*/

//Name : Mohit Sharma
//Roll no : MT2024091

#include <stdio.h> //import printf 
#include <fcntl.h> //import open system call 
#include <unistd.h> //import dup system call 

int main(int argc, char *argv[]) {
  
  if(argc != 2) {
    printf("enter the file name as argument\n");
    return 0;
  }

  int fd = open(argv[1], O_WRONLY | O_APPEND);
  int fd_duplicate = dup(fd);

  write(fd, "writing to original fd\n", 23);
  write(fd_duplicate, "writing to the duplicate fd\n", 28);

  return 0;
}

//command line : ./a.out file.txt
// cat file.txt
/* output :
* Hello world // this text already exits inside the file
* writing to original fd 
* writing to the duplicate fd
*/
