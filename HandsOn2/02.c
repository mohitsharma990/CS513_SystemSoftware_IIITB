/*
============================================================================
Name : 02.c
Author : Mohit Sharma
Description : Write a program to print the system resource limits. Use getrlimit system call.
Date: 17 Sept 2024
============================================================================
*/


#include <stdio.h>
#include <sys/resource.h> // for getrlimit
#include <stdlib.h>       // for exit()

// Function to print the resource limits
void print_limit(int resource, const char *name) {
    struct rlimit limit;

    if (getrlimit(resource, &limit) == -1) {
        perror("Error getting resource limit");
        exit(EXIT_FAILURE);
    }

    printf("%-25s ", name);

    if (limit.rlim_cur == RLIM_INFINITY) {
        printf("Current: unlimited   ");
    } else {
        printf("Current: %ld   ", limit.rlim_cur);
    }

    if (limit.rlim_max == RLIM_INFINITY) {
        printf("Max: unlimited\n");
    } else {
        printf("Max: %ld\n", limit.rlim_max);
    }
}

int main() {
    printf("System Resource Limits:\n");

    // Print limits for different resources
    print_limit(RLIMIT_CPU, "CPU time (seconds)");
    print_limit(RLIMIT_FSIZE, "Maximum file size (bytes)");
    print_limit(RLIMIT_DATA, "Data segment size (bytes)");
    print_limit(RLIMIT_STACK, "Stack size (bytes)");
    print_limit(RLIMIT_CORE, "Core file size (bytes)");
    print_limit(RLIMIT_RSS, "Resident set size (bytes)");
    print_limit(RLIMIT_NPROC, "Max number of processes");
    print_limit(RLIMIT_NOFILE, "Max number of open files");
    print_limit(RLIMIT_MEMLOCK, "Locked memory (bytes)");
    print_limit(RLIMIT_AS, "Address space (bytes)");
    print_limit(RLIMIT_LOCKS, "File locks");
    print_limit(RLIMIT_SIGPENDING, "Max pending signals");
    print_limit(RLIMIT_MSGQUEUE, "Max message queue size (bytes)");
    print_limit(RLIMIT_NICE, "Max nice priority");
    print_limit(RLIMIT_RTPRIO, "Max real-time priority");

    return 0;
}

/*
============================================================================
Command line:
Output: 

System Resource Limits:
CPU time (seconds)        Current: unlimited   Max: unlimited
Maximum file size (bytes) Current: unlimited   Max: unlimited
Data segment size (bytes) Current: unlimited   Max: unlimited
Stack size (bytes)        Current: 8388608   Max: unlimited
Core file size (bytes)    Current: 0   Max: unlimited
Resident set size (bytes) Current: unlimited   Max: unlimited
Max number of processes   Current: 15168   Max: 15168
Max number of open files  Current: 1024   Max: 1048576
Locked memory (bytes)     Current: 511528960   Max: 511528960
Address space (bytes)     Current: unlimited   Max: unlimited
File locks                Current: unlimited   Max: unlimited
Max pending signals       Current: 15168   Max: 15168
Max message queue size (bytes) Current: 819200   Max: 819200
Max nice priority         Current: 0   Max: 0
Max real-time priority    Current: 0   Max: 0

============================================================================
*/
