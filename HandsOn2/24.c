/*
============================================================================
Name : 24.c 
Author : Mohit Sharma
Description : Write a program to create a message queue and print the key and message queue id.
Date: 20 Sept 2024
============================================================================
*/

#include<sys/ipc.h>
#include<stdio.h>
#include<sys/types.h>
#include<sys/msg.h>
#include<stdlib.h>

int main() {
	key_t key = ftok(".", 'a');
	if(key == -1) {
		perror("Failed to create unique key\n");
		exit(1);
	}

	int id = msgget(key, IPC_CREAT | IPC_EXCL | 0777);
	if(id == -1) {
		perror("Failed to create message queue\n");
		exit(1);
	}

	
	printf("Key is: %d\n", key);
	printf("Message queue Id: %d\n", id);
	return 0;
}

/*
============================================================================
Command line: ./a.out
Output:
Key is: 1628618965
Message queue Id: 65536
============================================================================
*/
