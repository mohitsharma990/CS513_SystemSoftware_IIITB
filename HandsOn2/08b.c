/*
============================================================================
Name : 08b.c
Author : Mohit Sharma
Description : Write a separate program using signal system call to catch the following signals.
              b. SIGINT
Date: 19 Sept 2024
============================================================================
*/

#include <signal.h> // Import for `signal`
#include <stdio.h>  // Import for `printf`, `scanf` & `perror`
#include <unistd.h> // Import for `_exit`

void callback()
{
    printf("\nSignal SIGINT has been caught!\n");
    _exit(0);
}

void main()
{
    __sighandler_t signalStatus; // Determines the success of the `signal` call

    signalStatus = signal(SIGINT, (void *)callback);
    if (signalStatus == SIG_ERR)
        perror("Error while assigning signal handler!");
    else
        while(1);
}

/*
============================================================================
Command line: cc 08b.c && ./a.out
Output: 
^C
Signal SIGINT has been caught!
============================================================================
*/
