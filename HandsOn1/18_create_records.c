/*
============================================================================
Name : 18_create_records.c
Author : Mohit Sharma
Description :  Write a program to perform Record locking.
                  a. Implement write lock
                  b. Implement read lock
              Create three records in a file. Whenever you access a particular record, first lock it then modify/access
              to avoid race condition.
Date: 30st Aug, 2024.
============================================================================
*/ 

#include <stdio.h> // import perror, printf 
#include <stdlib.h> // import exit 
#include <fcntl.h> // import open system call 
#include <unistd.h> // import write and close system call 

struct Record {
  int num1;
  int num2;
};

struct Record typedef Record;

int main(int argc, char *argv[]) {
  
  if(argc != 2) {
    printf("enter the file name to store the records\n");
    return 0;
  }

  int fd = open(argv[1], O_RDWR | O_CREAT, S_IRWXU | S_IRWXG);
  if(fd == -1) {
    perror("error occurred\n");
    exit(EXIT_FAILURE);
  }

  Record r1;
  for(int i=0; i<=2; i++) {
    printf("Record number %d\n", i+1);
    printf("Enter number 1 for this record : ");
    scanf("%d", &r1.num1);
    printf("Enter number 2 for this record : ");
    scanf("%d", &r1.num2);
    write(fd, &r1, sizeof(r1));
  }

  close(fd);

  return 0;
}

/*
============================================================================
./a.out records
Record number 1
Enter number 1 for this record : 12
Enter number 2 for this record : 13
Record number 2
Enter number 1 for this record : 14
Enter number 2 for this record : 15
Record number 3
Enter number 1 for this record : 16
Enter number 2 for this record : 17
============================================================================
*/
