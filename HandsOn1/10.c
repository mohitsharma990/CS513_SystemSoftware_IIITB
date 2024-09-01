/*
============================================================================
Name : 10.c
Author : Mohit Sharma
Description : Write a program to open a file with read write mode, write 10 bytes, move the file pointer by 10
              bytes (use lseek) and write again 10 bytes.
                    a. check the return value of lseek
                    b. open the file with od and check the empty spaces in between the data.
Date: 29th Aug, 2024.
============================================================================
*/

#include <stdio.h> //import printf, perror, scanf 
#include <fcntl.h> //import open system call 
#include <unistd.h> //import write system call and lseek system call 

int main(int argc, char *argv[]) {

  if(argc != 2) {
    perror("pass the file name in the argument\n");
    return 0;
  }
  
  int fd = open(argv[1], O_RDWR | O_CREAT | O_TRUNC, 0644); //O_CREAT flag creates the file if it doesn't exits already and 
  //O_TRUNC flag Truncates the file to zero length if it already exists (i.e., clears its contents) and 0644 is file permissions if the system call creates a new file
  
  printf("Enter 10 characters : ");
  char str[11];
  scanf("%s", str);
  
  write(fd, str, 10); //write in fd from str and 10 bytes only
  int offsetLocation = lseek(fd, 10, SEEK_CUR); //lseek repositions read/write file offset, SEEK_CUR :the offset is set to its current location plus offset bytes. 
  printf("Return value of lseek : %d\n", offsetLocation);
  
  printf("Enter 10 characters again : ");
  scanf("%s", str);
  write(fd, str, 10);
  
  offsetLocation = lseek(fd, 0, SEEK_CUR);
  printf("Return value of lseek : %d\n", offsetLocation);

  return 0;
}


/*
============================================================================
command line : ./a.out file.txt                                                                                                                                        ─╯
output : Enter 10 characters : mohitsharm
Return value of lseek : 20
Enter 10 characters again : mohitsharm
Return value of lseek : 30 
============================================================================
*/

/*
============================================================================
b) checking the file contents with 'od' command ie octal dump
command line : od -x file.txt // to display the contents of the file including the empty spaces in hexadecimal format
o/p : 0000000      6f6d    6968    7374    6168    6d72    0000    0000    0000
0000020      0000    0000    6f6d    6968    7374    6168    6d72    000a
0000037
============================================================================
*/
