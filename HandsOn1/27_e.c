/*
============================================================================
Name : 27_e.c
Author : Mohit Sharma
Description : Write a program to execute ls -Rl by the following system calls
                  a. execl
                  b. execlp
                  c. execle
                  d. execv
                  e. execvp
Date: 31st Aug, 2024.
============================================================================
*/

#include <unistd.h>    // For execvp()

int main(int argc, char* argv[]){
  char *args[] = {"/bin/ls","-Rl",NULL};
	execvp(args[0],args);
	return 0;
}

/*
============================================================================
Output :
./a.out
total 1656
-rw-r--r--  1 mohitsharma  staff     668 27 Aug 11:17 01_a.c
-rw-r--r--  1 mohitsharma  staff     574 27 Aug 11:18 01_b.c
-rw-r--r--  1 mohitsharma  staff    1364 29 Aug 11:03 01_c.c
-rw-r--r--  1 mohitsharma  staff     131 29 Aug 11:10 01_shell.sh
-rw-r--r--  1 mohitsharma  staff     387 29 Aug 16:18 02.c
-rw-r--r--  1 mohitsharma  staff     835 29 Aug 16:37 03.c
-rw-r--r--  1 mohitsharma  staff     754 29 Aug 17:52 04.c
-rw-r--r--  1 mohitsharma  staff     675 29 Aug 18:17 05.c
-rw-r--r--  1 mohitsharma  staff     553 29 Aug 18:49 06.c
-rw-r--r--  1 mohitsharma  staff    1063 29 Aug 21:36 07.c
-rw-r--r--  1 mohitsharma  staff     797 29 Aug 21:45 08.c
-rw-r--r--  1 mohitsharma  staff    1805 30 Aug 14:20 09.c
-rw-r--r--  1 mohitsharma  staff    2133 30 Aug 15:39 10.c
-rw-r--r--  1 mohitsharma  staff     856 31 Aug 00:22 11_a.c
-rw-r--r--  1 mohitsharma  staff     956 31 Aug 00:44 11_b.c
-rw-r--r--  1 mohitsharma  staff     985 31 Aug 00:51 11_c.c
-rw-r--r--  1 mohitsharma  staff     812 31 Aug 01:33 12.c
-rw-r--r--  1 mohitsharma  staff    1424 31 Aug 10:42 13.c
-rwxr-xr-x  1 mohitsharma  staff   50079 31 Aug 22:10 14
-rw-r--r--  1 mohitsharma  staff    1642 31 Aug 11:11 14.c
-rw-r--r--  1 mohitsharma  staff    2638 31 Aug 11:46 15.c
-rw-r--r--  1 mohitsharma  staff    2610 31 Aug 11:50 15_v2.c
-rw-r--r--  1 mohitsharma  staff    1789 31 Aug 12:29 16_a.c
-rw-r--r--  1 mohitsharma  staff    1455 31 Aug 12:54 16_b.c
-rw-r--r--  1 mohitsharma  staff    2106 31 Aug 16:18 17_book_ticket.c
-rw-r--r--  1 mohitsharma  staff     985 31 Aug 15:11 17_store_ticket.c
-rw-r--r--  1 mohitsharma  staff    1467 31 Aug 16:22 18_create_records.c
-rw-r--r--  1 mohitsharma  staff    2033 31 Aug 16:38 18_read.c
-rw-r--r--  1 mohitsharma  staff    2330 31 Aug 18:20 18_write.c
-rw-r--r--  1 mohitsharma  staff    1436 31 Aug 18:37 19.c
-rw-r--r--  1 mohitsharma  staff     966 31 Aug 18:47 20.c
-rw-r--r--  1 mohitsharma  staff    1065 31 Aug 19:18 21.c
-rw-r--r--  1 mohitsharma  staff    1226 31 Aug 19:21 22.c
-rw-r--r--  1 mohitsharma  staff    1035 31 Aug 21:11 23.c
-rw-r--r--  1 mohitsharma  staff     978 31 Aug 21:21 24.c
-rwxr-xr-x  1 mohitsharma  staff   50191 31 Aug 21:49 25
-rw-r--r--  1 mohitsharma  staff    1739 31 Aug 21:26 25.c
-rw-r--r--  1 mohitsharma  staff    1322 31 Aug 22:13 26.c
-rw-r--r--  1 mohitsharma  staff     810 31 Aug 22:21 27_a.c
-rw-r--r--@ 1 mohitsharma  staff  521331 31 Aug 19:21 Hands-on List 1.pdf
-rwxr-xr-x  1 mohitsharma  staff   49954 31 Aug 22:21 a.out
-rw-r--r--  1 mohitsharma  staff      75 31 Aug 22:11 file.txt
-rwxr-x---  1 mohitsharma  staff      24 31 Aug 18:16 records
-rw-r--r--  1 mohitsharma  staff       0 31 Aug 15:09 ticket
-rwxr-x---  1 mohitsharma  staff       4 31 Aug 16:01 tickets
============================================================================
*/ 
