/*
============================================================================
Name : 11.c
Author : Mohit Sharma
Description : Write a program to ignore a SIGINT signal then reset the default action of the SIGINT signal -
use sigaction system call.
Date: 19 Sept 2024
============================================================================
*/

#include <signal.h> // Import for `sigaction`
#include <stdio.h>  // Import for `perror` & `printf`
#include <unistd.h> // Import for `_exit`, `sleep`

void signalHandler(int signalNumber)
{
    printf("\nCaught signal SIGINT (%d)\n", signalNumber);
}

int main()
{
    int status; // Determines success of `sigaction` call
    struct sigaction action;

    // Ignore SIGINT
    printf("\nIgnoring SIGINT for 5 seconds!\n");
    action.sa_handler = SIG_IGN;
    action.sa_flags = 0;
    status = sigaction(SIGINT, &action, NULL);
    if (status == -1)
        perror("Error while setting signal handler!");
    else
        sleep(5);


    // Provide custom handler
    printf("\nHandling SIGINT for 5 seconds!\n");
    action.sa_handler = signalHandler;
    action.sa_flags = 0;
    status = sigaction(SIGINT, &action, NULL);
    if (status == -1)
        perror("Error while setting signal handler!");
    else
        sleep(5);

    // Setting default handler
    printf("Default action for SIGINT for 5 seconds!\n");
    action.sa_handler = SIG_DFL;
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
Command line:
Output:
Ignoring SIGINT for 5 seconds!
^C^C^C^C^C
Handling SIGINT for 5 seconds!
^C
Caught signal SIGINT (2)
Default action for SIGINT for 5 seconds!
^C
============================================================================
*/
