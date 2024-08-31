/*
============================================================================
Name : 28.c
Author : Mohit Sharma
Description : Write a program to get maximum and minimum real time priority.
Date: 31st Aug, 2024.
============================================================================
*/

#include <stdio.h>    // For printf()
#include <sched.h>    // For sched_get_priority_max(), sched_get_priority_min()

int main(int argc, char* argv[]){
	printf("\nSCHED_FIFO: ");
	printf("Max real time priority: %d\n", sched_get_priority_max(SCHED_FIFO));
	printf("Min real time priority: %d\n", sched_get_priority_min(SCHED_FIFO));
	
	printf("\n");
	
	printf("\nSCHED_RR: ");
	printf("Max real time priority: %d\n", sched_get_priority_max(SCHED_RR));
	printf("Min real time priority: %d\n", sched_get_priority_min(SCHED_RR));
	return 0;
}

/*
============================================================================
Output :
./a.out
./a.out                                                                                                                                                 ─╯

SCHED_FIFO: Max real time priority: 47
Min real time priority: 15


SCHED_RR: Max real time priority: 47
Min real time priority: 15
============================================================================
*/
