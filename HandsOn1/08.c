// Write a program to open a file in read only mode, read line by line and display each line as it is read.
// Close the file when end of file is reached.
// Name : Mohit Sharma
// Roll No : MT2024091

#include <stdio.h> // for printf
#include <fcntl.h> // for open system call
#include <unistd.h> // for close and read system call

int main(int argc, char *argv[]) {
  
  if(argc != 2) {
    printf("Enter the file name in the argument which you want to read line by line\n");
    return 0;
  }
  
  int fd = open(argv[1], O_RDONLY);
  char buffer[1024];
  char ch;
  int i = 0;

  while ((read(fd, &ch, 1)) > 0) {
    buffer[i++] = ch;
    if (ch == '\n') {
      buffer[i] = '\0';
      printf("%s", buffer);
      i = 0;
    }
  }

  close(fd);

}

// Command line : ./a.out file
// Output : 
