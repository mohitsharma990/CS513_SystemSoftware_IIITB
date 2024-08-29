// Create a FIFO file using 'mknod' system call or 'mkfifo' library function
// Name : Mohit Sharma
// Roll No : MT2024091

//FIFO file ~ named pipes
#include <sys/stat.h> // Defines the mknod system call and file mode constants (e.g., S_IFIFO, S_IRWXU)
#include <sys/types.h> // Defines data types used in system calls.
#include <stdio.h> // For importing perror and printf

int main(int argc, char *argv[]) {
  
  if(argc != 2) {
    printf("Enter a file name to create it as a FIFO file as an argument\n");
    return 0;
  }

  //using mkfifo lib function
  if(mkfifo(argv[1], S_IRWXU) == 0) { //Second argument means we are setting read write execute permissions for the user
    printf("FIFO file created succesfully\n");
  }
  //We can give the 'S_IRWXU' permissions to user using '0600' also
  else {
    perror("error occured\n");
  }

/* // using mknod system call : 
  if(mknod(argv[1], S_IFIFO | S_IRWXU, 0) == 0) {//Third argument is used for specifying a device number (dev_t) when creating special files like block or character devices, but it's not required for FIFOs.
      printf("FIFO file created succesfully\n");
  }
  else {
    perror("error occured\n");
  }
*/
  return 0;
}

// Command line : ./a.out myfifo
// Output : FIFO file created succesfully


/*
  To use this named pipe: on 
  terminal 1 : cat > myfifo
  terminal 2 : cat < myfifo
*/
