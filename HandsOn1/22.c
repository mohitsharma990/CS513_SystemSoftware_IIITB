// Write a program, open a file, call fork, and then write to the file by both the child as well as the
// parent processes. Check output of the file.

// Name : Mohit Sharma
// Roll no : MT2024091

#include <stdio.h> //for printf and perror
#include <stdlib.h> //for exit
#include <unistd.h> //for fork(), write(), close()
#include <fcntl.h> //for open(), O_RDWR

int main(int argc, char *argv[]) {

  if(argc != 2) {
    printf("Enter the file name in the argument to write\n");
    return 0;
  }
  
  int fd = open(argv[1], O_RDWR);
	if(fd == -1){
		perror("Error occurred\n");
		exit(EXIT_FAILURE);
	}

	int cpid = fork();
	if(cpid == 0){ // ie we are currently in child process 
		write(fd, "Content written in the child process", sizeof("Content written in the child process"));
		return 0;//returning to the parent process 
	}
	write(fd, "Content written in the parent process", sizeof("Content written in the parent process"));
    
  close(fd);

  return 0;
}

/* output :
 ./a.out file.txt 

cat file.txt                                                                      ─╯
Content written in the parent processContent written in the child process //here in this scenario : Parent writes first, then child
*/
