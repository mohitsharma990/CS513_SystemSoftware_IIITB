/*
============================================================================
Name : 18.c
Author : Mohit Sharma
Description : Write a program to find out total number of directories on the pwd.
              execute ls -l | grep ^d | wc ? Use only dup2.
Date: 19 Sept 2024
============================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<fcntl.h>

int main() {
	int fd1[2], fd2[2];
	int stat1 = pipe(fd1);
	int stat2 = pipe(fd2);
	if(stat1 == -1 || stat2 == -1) {
		perror("Couldn't create the pipe\n");
		exit(1);
	}
	if(!fork()) {
		close(1);
		close(fd1[0]);
		close(fd2[0]);
		close(fd2[1]);
		dup2(fd1[1], 1);
		execlp("ls", "ls", "-l", (char *)NULL);
	} else if(!fork()) {
		close(1);
		close(fd1[1]);
		close(0);
		dup2(fd1[0], 0);
		close(fd2[0]);
		dup2(fd2[1], 1);
		execlp("grep", "grep", "^d", (char *) NULL);
	} else {
		close(0);
		close(fd1[1]);
		close(fd1[0]);
                close(fd2[1]);
                dup2(fd2[0], 0);
                execlp("wc", "wc", (char *)NULL);
	}
	wait(0);
	return 0;
}

/*
============================================================================
Command line: ./a.out 
Output: 
      9      81     468
============================================================================
*/
