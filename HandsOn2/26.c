/*
============================================================================
Name : 26.c
Author : Mohit Sharma
Description : Write a program to send messages to the message queue. Check $ipcs -q
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

	int id = msgget(key, IPC_CREAT|0777);
	if(id == -1) {
		perror("Failed to create the message queue\n");
		exit(1);
	}

	struct msgbuf {
		long mtype;
		int num;
	};

	struct msgbuf msg;
	msg.mtype = 1;
	msg.num = 108;
	int status = msgsnd(id, &msg, sizeof(msg), 0);
	if(status  == -1) {
		perror("Failed to send the message\n");
		exit(1);
	} else {
		printf("Message Sent!!");
	}

	return 0;
}

/*
============================================================================
Command line: ./a.out 
Output: 
Message Sent!!


Command line : ipcs -q
IPC status from <running system> as of Fri Sep 20 18:56:18 IST 2024
T     ID     KEY        MODE       OWNER    GROUP
Message Queues:
q  65536 0x6112c0d5 --rw-rw-rw- mohitsharma    staff
============================================================================
*/
