/*
============================================================================
Name : 12.c
Author : Mohit Sharma
Description : Write a program to create an orphan process. Use kill system call to send SIGKILL signal to
              the parent process from the child process.
Date: 19 Sept 2024
============================================================================
*/

#include <sys/types.h> // Import for `kill`, `fork`
#include <signal.h>    // Import for `kill`
#include <unistd.h>    // Import for `fork`, `sleep`
#include <stdio.h>     // Import for `perror` & `printf`

int main()
{
    pid_t childPid, parentPid;
    int killStatus; // Determines success of `kill`

    childPid = fork();

    if (childPid == -1)
        perror("Error while creating child!");
    else if (!childPid)
    {
        // Child will enter this branch
        printf("Child PID: %d\n", getpid());
        printf("Parent PID: %d\n", getppid());

        sleep(10);

        killStatus = kill(getppid(), SIGKILL);

        if (!killStatus)
        {
            printf("Successfully killed parent!\n");
            sleep(10);
            printf("Child now exiting!\n");
        }
        else
            perror("Error while killing parent!");
    }
    else
    {
        // Parent will enter this branch
        while (1);
    }

    return 0;

}

/*
============================================================================
Command line: cc 12.c && ./a.out 
Output:
Child PID: 12411
Parent PID: 12407
Successfully killed parent!
[1]    12407 killed     ./a.out

╭─    ~/III/CS513_SystemSoftware_IIITB/HandsOn2    main !2 ?19 
╰─ Child now exiting!
============================================================================
*/
