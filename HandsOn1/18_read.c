/*
============================================================================
Name : 18_read.c
Author : Mohit Sharma
Description : Write a program to perform Record locking.
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

struct Record{
	int num1;
	int num2;
};

struct Record typedef Record;


int main(int argc, char *argv[]) {
  if(argc != 2) {
    printf("enter file name in the arguments\n");
    return 0;
  }

  int fd = open(argv[1], O_RDWR);
  if(fd == -1) {
    perror("error occurred\n");
    exit(EXIT_FAILURE);
  }

  int n;
  printf("Enter record number to read (1, 2, 3) : ");
  scanf("%d", &n);

  Record r;

  struct flock mylock;
	mylock.l_type = F_RDLCK;
	mylock.l_whence = SEEK_SET;
	mylock.l_start = (n-1)*sizeof(r);
	mylock.l_len = sizeof(r);
	mylock.l_pid = getpid();

  lseek(fd, (n-1)*sizeof(r), SEEK_SET);

  printf("Before entering into the critical section\n");
	fcntl(fd, F_SETLKW, &mylock);
	
	printf("Inside the critical section\n");
	read(fd, &r, sizeof(r));
	printf("Current record: %d %d\n", r.num1, r.num2);
	
	printf("Press ENTER to exit critical section\n");
	getchar(); getchar();
	
	mylock.l_type=F_UNLCK;
	fcntl(fd, F_SETLK, &mylock);
	printf("Done with critical section. Exiting. \n");
	close(fd);

  return 0;
}


/*
============================================================================
./a.out records                                                                                                                                         ─╯
Enter record number to read (1, 2, 3) : 1
Before entering into the critical section
Inside the critical section
Current record: 12 13
Press ENTER to exit critical section
============================================================================
*/

/*
============================================================================
another terminal :

Enter record number to read (1, 2, 3) : 2
Before entering into the critical section
Inside the critical section
Current record: 14 15
Press ENTER to exit critical section
============================================================================
*/
