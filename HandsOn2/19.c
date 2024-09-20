/*
============================================================================
Name : 19.c
Author : Mohit Sharma
Description : Create a FIFO file by
              a. mknod command
              b. mkfifo command
              c. use strace command to find out, which command (mknod or mkfifo) is better.
              c. mknod system call
              d. mkfifo library function
Date: 19 Sept 2024
============================================================================
*/

#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>

int main() {
    int stat = mkfifo("myFifo", 0777);
    if(stat == -1) {
        perror("FIFO creation using mkfifo failed");
        exit(1);
    } else {
        printf("FIFO Success using mkfifo!!!\n");
    }

    // Create a FIFO using mknod with permissions
    stat = mknod("mknodFifo", S_IFIFO | 0666, 0);
    if(stat == -1) {
        perror("FIFO creation using mknod failed");
        exit(1);
    } else {
        printf("mknod FIFO Success!!!\n");
    }

    return 0;
}

/*
============================================================================
Command line:
Output: 
============================================================================
*/
