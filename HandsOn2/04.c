/*
============================================================================
Name : 04.c
Author : Mohit Sharma
Description : Write a program to measure how much time is taken to execute 100 getppid ( )
              system call. Use time stamp counter.
Date: 12 Sept 2024
============================================================================
*/


#include <stdio.h>
#include <time.h>
#include <unistd.h>

// Function to calculate time difference in nanoseconds
unsigned long long timespec_diff_ns(struct timespec *start, struct timespec *end) {
    return (end->tv_sec - start->tv_sec) * 1000000000ULL + (end->tv_nsec - start->tv_nsec);
}

int main() {
    struct timespec start, end;

    // Measure time before 100 getppid() calls
    clock_gettime(CLOCK_MONOTONIC, &start);

    int iter = 1;
    while (iter <= 100) {
        getppid();  // Call getppid() 100 times
        iter += 1;
    }

    // Measure time after the loop
    clock_gettime(CLOCK_MONOTONIC, &end);

    // Calculate and print the time difference in nanoseconds
    unsigned long long time_ns = timespec_diff_ns(&start, &end);
    printf("Time required (nanoseconds): %llu\n", time_ns);

    return 0;
}


/*
============================================================================
Command line: cc 04.c && ./a.out
Output : 
Time required (nanoseconds): 49000
============================================================================
*/
