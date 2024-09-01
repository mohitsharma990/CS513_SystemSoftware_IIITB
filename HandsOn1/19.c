/*
============================================================================
Name : 19.c
Author : Mohit Sharma
Description : Write a program to find out time taken to execute getpid system call. Use time stamp counter.
Date: 30st Aug, 2024.
============================================================================
*/

#include <stdio.h> // import printf
#include <sys/time.h> // import gettimeofday and struct timeval
#include <unistd.h> //import getpid() function

int main(int argc, char *argv[]) {
  
  struct timeval start, end; // structure variables that store time values, with two fields: tv_sec for seconds and tv_usec for microseconds.
	
	double elapsed = 0.0; // This variable will hold the elapsed time in microseconds.

	
	gettimeofday(&start, NULL); //captures the current time 
	int pid = getpid(); 
	gettimeofday(&end, NULL); // //captures the current time 
	
  //Now calculating elapsed time:
	printf("Process ID: %d\n", pid);
	elapsed += (end.tv_sec - start.tv_sec)*1000000; // end.tv_sec - start.tv_sec will give the difference in seconds, which is then converted to microseconds by multiplying by 1,000,000.
	elapsed += (end.tv_usec -start.tv_usec); // differnce in microseconds
	printf("Time taken for getpid system call: %lf us\n", elapsed); //printing the result in microseconds 

  return 0;
}

//info :
// getpid() system call, which retrieves the process ID of the calling process. Here’s a breakdown of the code:

/*
============================================================================
Output :
./a.out                                                                           ─╯
Process ID: 65053
Time taken for getpid system call: 0.000000 us
============================================================================
*/
