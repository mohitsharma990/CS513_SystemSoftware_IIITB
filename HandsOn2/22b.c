/*
============================================================================
Name : 22b.c
Author : Mohit Sharma
Description : Write a program to wait for data to be written into FIFO within 10 seconds, use select
              system call with FIFO.
Date: 20 Sept 2024
============================================================================
*/


#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

void main()
{
    int f;
    char *s = "myFifo";
    mkfifo(s, S_IRWXU);
    f = open(s, O_NONBLOCK | O_WRONLY);

    if (f == -1)
    {
        perror("Error while opening FIFO file!");
        _exit(0);
    }
    char *st;
    long int size=100;
    printf("enter message\n");
    int l=getline(&st,&size,stdin);
    write(f, st, l);
    close(f);
}

/*
============================================================================
Command line: ./22b 
Output: 
enter message
Hello, how are you?
============================================================================
*/
