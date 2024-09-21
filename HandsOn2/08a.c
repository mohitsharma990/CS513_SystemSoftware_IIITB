/*
============================================================================
Name : 08a.c
Author : Mohit Sharma
Description : Write a separate program using signal system call to catch the following signals.
              a. SIGSEGV
Date: 19 Sept 2024
============================================================================
*/

#include <signal.h> // Import for `signal`, `raise`
#include <stdio.h>  // Import for `printf`, `scanf` & `perror`
#include <unistd.h> // Import for `_exit`

void callback()
{
    printf("Signal SIGSEGV has been caught!\n");
    _exit(0);
}

void main()
{
    __sighandler_t signalStatus; // Determines the success of the `signal` call

    signalStatus = signal(SIGSEGV, (void *)callback);
    if (signalStatus == SIG_ERR)
        perror("Error while assigning signal handler!");
    else
        raise(SIGSEGV); // Send segmentation fault signal
        
}

/*
============================================================================
Command line: cc 08a.c && ./a.out
Output: Signal SIGSEGV has been caught!
============================================================================
*/
