/*
============================================================================
Name : 07.c
Author : Mohit Sharma
Description : Write a simple program to print the created thread ids.
Date: 19 Sept 2024
============================================================================
*/

#include <pthread.h> // Import for `pthread_create`
#include <stdio.h>   // Import for `perror` & `printf`

void sampleFunction()
{
    printf("Running in thread with thread ID: %lu\n", pthread_self());
}

int main()
{
    pthread_t threadID;

    // Create thread
    if(pthread_create(&threadID, NULL, (void *)sampleFunction, NULL))
        perror("Error while creating thread");

    pthread_exit(NULL);
    return 0;
}

/*
============================================================================
Command line: ./a.out
Output: Running in thread with thread ID: 265860690276640
============================================================================
*/
