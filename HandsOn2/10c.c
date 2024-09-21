/*
============================================================================
Name : 10_c.c
Author : Mohit Sharma
Description : Write a separate program using sigaction system call to catch the following signals.
              c. SIGFPE
Date: 19 Sept 2024
============================================================================
*/


#include <signal.h> // Import for `sigaction`, `raise`
#include <stdio.h>  // Import for `perror` & `printf`
#include <unistd.h> // Import for `_exit`, `sleep`

void signalHandler(int signalNumber)
{
    printf("Caught signal SIGFPE (%d)\n", signalNumber);
    _exit(0);
}

int main()
{
    int status; // Determines success of `sigaction` call
    struct sigaction action;
    int a;

    action.sa_handler = signalHandler;
    action.sa_flags = 0;

    status = sigaction(SIGFPE, &action, NULL);
    if (status == -1)
        perror("Error while setting signal handler!");
    else
        raise(SIGFPE);
    return 0;
}

/*
============================================================================
Command line: ./a.out 
Output: Caught signal SIGFPE (8)
============================================================================
*/
