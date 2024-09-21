/*
============================================================================
Name : 09.c
Author : Mohit Sharma
Description :  Write a program to ignore a SIGINT signal then reset the default action of the SIGINT
               signal - Use signal system call.
Date: 19 Sept 2024
============================================================================
*/

#include <signal.h> // Import for `signal`
#include <stdio.h>  // Import for `printf`, `scanf` & `perror`
#include <unistd.h> // Import for `_exit`, `sleep`

void sampleFunction()
{
    printf("\nSignal SIGINT has been caught!\n");
}

void main()
{
    char *a;
    __sighandler_t signalStatus; // Determines the success of the `signal` call

    // Ignore SIGINT
    printf("Your SIGINT will be ignored for 5 seconds\n");
    signalStatus = signal(SIGINT, SIG_IGN);
    if(signalStatus == SIG_ERR)
        perror("Error while trying to ignore signal!");
    else 
        sleep(5);

    printf("\nSIGINT will now be caught!\n");
    signalStatus = signal(SIGINT, (void *)sampleFunction);
    if (signalStatus == SIG_ERR)
        perror("Error while assigning signal handler!");
    else
        sleep(5);

    printf("SIGINT will now be caught using the default handler!\n");
    signalStatus = signal(SIGINT, SIG_DFL);
    if (signalStatus == SIG_ERR)
        perror("Error while assigning signal handler!");
    else
        sleep(5);
}


/*
============================================================================
Command line: cc 09.c && ./a.out 
Output: 
Your SIGINT will be ignored for 5 seconds
^C^C^C^C^C^C
SIGINT will now be caught!
^C
Signal SIGINT has been caught!
SIGINT will now be caught using the default handler!
^C
============================================================================
*/
