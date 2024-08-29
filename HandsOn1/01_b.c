// Create a hard link file using 'link' system call
// Name: Mohit Sharma
// Roll No: MT2024091

#include <unistd.h> // to import 'link' system call
#include <stdio.h> // to import perror and printf

int main(int argc, char *argv[]) {
  if(argc != 3) {
    printf("error: Pass the source file and hardlink file name\n");
    return 0;
  }

  if(link(argv[1], argv[2]) == 0) {
    printf("Hardlink successfully created\n");
  }
  else {
    perror("error occurred\n");
  }

  return 0;
}

// Command line : ./a.out file.txt hardlink
// Output : Hardlink successfully created
