/*
============================================================================
Name : 26.c
Author : Mohit Sharma
Description :  Write a program to execute an executable program.
                a. use some executable program
                b. pass some input to an executable program. (for example execute an executable of $./a.out name)
                
Date: 31st Aug, 2024.
============================================================================
*/

#include <unistd.h>	// Import execl

int main(){
	char *exec_path = "./14"; //executing question 14 of the HandsOn1
	char *argv = "file.txt";
	execl(exec_path,exec_path,argv,NULL);  // the fourth argument NULL represents the end of the argument list for execl(), 
  // execl() function is used to replace the current process image with a new process image

  return 0; // if execl() != -1 this return 0 command will not run, but if it gets unsuccussfull then the current program ll continue its execution
}

/*
============================================================================
Output :
./a.out                                                                                                                                                 ─╯
Type of the file: 33188
Its a regular file
============================================================================
*/
