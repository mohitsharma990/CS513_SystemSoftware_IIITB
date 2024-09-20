/*
============================================================================
Name : 29.c
Author : Mohit Sharma
Description : Write a program to remove the message queue.
Date: 20 Sept 2024
============================================================================
*/

#include<sys/ipc.h>
#include<sys/types.h>
#include<sys/msg.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main() {
	key_t key = ftok(".", 'a');
	if(key == -1) {
		perror("Failed to create key\n");
		exit(1);
	}

	int id = msgget(key, IPC_CREAT|0600);
	if(id == -1) {
		perror("Failed to create the message queue\n");
		exit(1);
	}

	int status = msgctl(id, IPC_RMID, NULL);
	if(status  == -1) {
                perror("Failed to delete message queue\n");
                exit(1);
        } else printf("Message Queue Deleted!!\n");

	return 0;
}

/*
============================================================================
Command line: cc 29.c && ./a.out 
Output: 
Message Queue Deleted!!
============================================================================
*/
