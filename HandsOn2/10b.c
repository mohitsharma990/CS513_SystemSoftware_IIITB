/*
============================================================================
Name : 10b.c
Author : Mohit Sharma
Description : Write a separate program using sigaction system call to catch the following signals.
              b. SIGINT
Date: 19 Sept 2024
============================================================================
*/

#include <signal.h> // Import for `sigaction`, `raise`
#include <stdio.h>  // Import for `perror` & `printf`
#include <unistd.h> // Import for `_exit`, `sleep`

void signalHandler(int signalNumber)
{
    printf("\nCaught signal SIGINT (%d)\n", signalNumber);
    _exit(0);
}

int main()
{
    int status; // Determines success of `sigaction` call
    struct sigaction action;

    action.sa_handler = signalHandler;
    action.sa_flags = 0;

    status = sigaction(SIGINT, &action, NULL);
    if (status == -1)
        perror("Error while setting signal handler!");
    else
        sleep(5);

    return 0;
}

/*
============================================================================
Command line: cc 10b.c && ./a.out 
Output: 
^C
Caught signal SIGINT (2)
============================================================================
*/
