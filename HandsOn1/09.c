/*
Write a program to print the following information about a given file.
a. inode
b. number of hard links
c. uid
d. gid
e. size
f. block size
g. number of blocks
h. time of last access
i. time of last modification
j. time of last change
*/

//Name : Mohit Sharma
//Roll no : MT2024091

#include <stdio.h> // import perror and printf 
#include <sys/stat.h> // import stat structure
#include <time.h> // import ctime function 

int main(int argc, char *argv[]) {
  
  if(argc != 2) {
    perror("enter the file name in the argument\n");
    return 1; // return 1 means indicating an error 
  }

  struct stat filestat; //filestat is variable of type struct stat, stat structure contains info about the file
  
  if(stat(argv[1], &filestat) == -1) { // stat func retrives the info about the file specified and stores it in the variable filestat 
    // stat function returns -1 on failure and 0 on success
    perror("error occurred\n");
    return 0;
  }
  
  printf("File name : %s\n", argv[1]);
  printf("Inode number : %llu\n", filestat.st_ino); //format specifier %lu in C is used to print an unsigned long integer
  printf("Number of hard links to the given file : %hu\n", filestat.st_nlink); // %hu for unsigned short integer 
  printf("uid : %u\n", filestat.st_uid); // %u for unsigned integer
  printf("gid : %u\n", filestat.st_gid);
  printf("size : %lld Bytes\n", filestat.st_size); // %ld for signed long long integer
  printf("number of blocks  : %lld\n", filestat.st_blocks);
  printf("block size : %d\n", filestat.st_blksize);
  printf("time of last access : %s", ctime(&filestat.st_atime));
  printf("time of last modification : %s", ctime(&filestat.st_mtime));
  printf("time of last change : %s", ctime(&filestat.st_ctime));

  return 0;
}

// command line : ./a.out file.txt
// output : 
