/*
============================================================================
Name : 08.c
Author : Mohit Sharma
Description : Write a program to open a file in read only mode, read line by line and display each line as it is read.
              Close the file when end of file is reached.
Date: 24th Aug, 2024.
============================================================================
*/

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

/*
============================================================================
Command line : 
touch file.txt
ll > file.txt
./a.out file.txt

Output :
./a.out file.txt
total 1304
-rw-r--r--  1 mohitsharma  staff   668B 27 Aug 11:17 01_a.c
-rw-r--r--  1 mohitsharma  staff   574B 27 Aug 11:18 01_b.c
-rw-r--r--  1 mohitsharma  staff   1.3K 29 Aug 11:03 01_c.c
-rw-r--r--  1 mohitsharma  staff   131B 29 Aug 11:10 01_shell.sh
-rw-r--r--  1 mohitsharma  staff   387B 29 Aug 16:18 02.c
-rw-r--r--  1 mohitsharma  staff   835B 29 Aug 16:37 03.c
-rw-r--r--  1 mohitsharma  staff   754B 29 Aug 17:52 04.c
-rw-r--r--  1 mohitsharma  staff   675B 29 Aug 18:17 05.c
-rw-r--r--  1 mohitsharma  staff   553B 29 Aug 18:49 06.c
-rw-r--r--  1 mohitsharma  staff   1.0K 29 Aug 21:36 07.c
-rw-r--r--  1 mohitsharma  staff   797B 29 Aug 21:45 08.c
-rw-r--r--  1 mohitsharma  staff   2.2K  1 Sep 15:14 09.c
-rw-r--r--  1 mohitsharma  staff   2.6K  1 Sep 15:11 10.c
-rw-r--r--  1 mohitsharma  staff   1.2K  1 Sep 15:06 11_a.c
-rw-r--r--  1 mohitsharma  staff   1.3K  1 Sep 15:08 11_b.c
-rw-r--r--  1 mohitsharma  staff   1.3K  1 Sep 15:09 11_c.c
-rw-r--r--  1 mohitsharma  staff   1.1K  1 Sep 15:04 12.c
-rw-r--r--  1 mohitsharma  staff   1.7K  1 Sep 15:03 13.c
-rw-r--r--  1 mohitsharma  staff   2.0K  1 Sep 15:01 14.c
-rw-r--r--  1 mohitsharma  staff   2.9K  1 Sep 14:57 15.c
-rw-r--r--  1 mohitsharma  staff   2.9K  1 Sep 14:59 15_v2.c
-rw-r--r--  1 mohitsharma  staff   2.2K  1 Sep 14:52 16_a.c
-rw-r--r--  1 mohitsharma  staff   1.9K  1 Sep 14:55 16_b.c
-rw-r--r--  1 mohitsharma  staff   2.6K  1 Sep 14:48 17_book_ticket.c
-rw-r--r--  1 mohitsharma  staff   1.2K  1 Sep 14:50 17_store_ticket.c
-rw-r--r--  1 mohitsharma  staff   1.8K  1 Sep 14:36 18_create_records.c
-rw-r--r--  1 mohitsharma  staff   2.5K  1 Sep 14:46 18_read.c
-rw-r--r--  1 mohitsharma  staff   3.0K  1 Sep 14:46 18_write.c
-rw-r--r--  1 mohitsharma  staff   1.7K  1 Sep 14:43 19.c
-rw-r--r--  1 mohitsharma  staff   1.3K  1 Sep 14:29 20.c
-rw-r--r--  1 mohitsharma  staff   1.4K  1 Sep 14:30 21.c
-rw-r--r--  1 mohitsharma  staff   1.5K  1 Sep 14:30 22.c
-rw-r--r--  1 mohitsharma  staff   1.3K  1 Sep 14:22 23.c
-rw-r--r--  1 mohitsharma  staff   978B 31 Aug 21:21 24.c
-rw-r--r--  1 mohitsharma  staff   1.7K 31 Aug 21:26 25.c
-rw-r--r--  1 mohitsharma  staff   1.3K  1 Sep 14:17 26.c
-rw-r--r--  1 mohitsharma  staff   3.5K 31 Aug 22:21 27_a.c
-rw-r--r--  1 mohitsharma  staff   3.5K 31 Aug 22:27 27_b.c
-rw-r--r--  1 mohitsharma  staff   3.5K 31 Aug 22:29 27_c.c
-rw-r--r--  1 mohitsharma  staff   3.4K 31 Aug 22:31 27_d.c
-rw-r--r--  1 mohitsharma  staff   3.5K  1 Sep 14:17 27_e.c
-rw-r--r--  1 mohitsharma  staff   1.3K  1 Sep 14:14 28.c
-rw-r--r--  1 mohitsharma  staff   1.7K  1 Sep 14:12 29.c
-rw-r--r--  1 mohitsharma  staff   2.0K  1 Sep 12:47 30.c
-rw-r--r--@ 1 mohitsharma  staff   420K 27 Aug 10:07 Hands-on List 1.pdf
-rwxr-xr-x  1 mohitsharma  staff    49K  1 Sep 15:14 a.out
-rw-r--r--  1 mohitsharma  staff     0B  1 Sep 15:14 file.txt
-rwx------  1 mohitsharma  staff    32B  1 Sep 12:35 logfile_30.txt
============================================================================
*/
