/*
============================================================================
Name : 30_check.c
Author : Mohit Sharma
Description :  Write a program to run a script at a specific time using a Daemon process.


Date: 31st Aug, 2024.
============================================================================
*/

#include <stdio.h>      // For printf()
#include <unistd.h>     // For read(), write()
#include <fcntl.h>      // For open()

int main(){
	int in_fd = 0, out_fd = 1;
	
	char ch;
	int ix = 0;
	in_fd = open("/logfile.txt", O_RDONLY);
	if(in_fd<0){
		printf("\n Error opening infile\n");
	}

	while(read(in_fd, &ch, sizeof(ch)) > 0){
		write(out_fd, &ch, sizeof(ch));
	}
	
	return 0;
}

/*
============================================================================
Output :
./a.out

============================================================================
*/




