/*
============================================================================
Name : 31b.c
Author : Mohit Sharma
Description : Write a program to create a semaphore and initialize value to the semaphore.
                  a. create a binary semaphore
                  b. create a counting semaphore
Date: 20 Sept 2024
============================================================================
*/

#include<sys/ipc.h>
#include<sys/types.h>
#include<sys/sem.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main() {
	key_t key = ftok(".", 'b');
	if(key == -1) {
		perror("Failed to create the key\n");
		exit(1);
	}

	int id = semget(key, 1, IPC_CREAT | 0777);
	if(key == -1) {
                perror("Failed to create the semaphore\n");
                exit(1);
        }

	union semun {
		int val;
	} sem;

	sem.val = 10;

	printf("Press enter to initialize semaphore\n");
	getchar();

	int status = semctl(id, 0, SETVAL, sem);
	if(status == -1) {
                perror("Faied to initialize semaphore\n");
                exit(1);
        }

	return 0;
}

/*
============================================================================
Command line: cc 31b.c && ./a.out 
Output: 
Press enter to initialize semaphore


Command line : ipcs -s
output : 
IPC status from <running system> as of Fri Sep 20 19:48:11 IST 2024
T     ID     KEY        MODE       OWNER    GROUP
Semaphores:
s  65536 0x6112c0d5 --ra-ra-ra- mohitsharma    staff
s  65537 0x6212c0d5 --ra-ra-ra- mohitsharma    staff
============================================================================
*/
