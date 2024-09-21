/*
============================================================================
Name : 13a.c
Author : Mohit Sharma
Description : Write two programs: first program is waiting to catch SIGSTOP signal, the second program
              will send the signal (using kill system call). Find out whether the first program is able to catch
              the signal or not.
Date: 19 Sept 2024
============================================================================
*/
// This program catches the `SIGSTOP` signal

#include <signal.h> // Import for `signal`
#include <unistd.h> // Import for `sleep`, `_exit`, `getpid`
#include <stdio.h>  // Import for `perror` & `printf`
#include <stdlib.h> // Import for `atoi`

void customHandler()
{
    printf("Received SIGSTOP signal!\n");
    _exit(0);
}

void main()
{
    __sighandler_t signalStatus; // Determines success of `signal`
    pid_t pid = getpid();

    printf("Process ID: %d\n", pid);

    signalStatus = signal(SIGSTOP, customHandler);
    if (signalStatus == SIG_ERR)
        perror("Error while catching signal!");

    printf("Putting the process to sleep for 15s\n");
    sleep(15);
}

/*
    A program cannot catch a SIGSTOP signal. We can conclude this by observing that the customHandler function is never executed and instead the program is terminated!
*/

/*
============================================================================
Command line: cc 13a.c && ./a.out
Output: 
Process ID: 2231
Error while catching signal!: Invalid argument
Putting the process to sleep for 15s


============================================================================
*/
