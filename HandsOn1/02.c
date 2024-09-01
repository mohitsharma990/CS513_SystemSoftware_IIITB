/*
============================================================================
Name : 02.c
Author : Mohit Sharma
Description : Write a simple program to execute in an infinite loop at the background. Go to /proc directory and
              identify all the process related information in the corresponding proc directory.
Date: 20th Aug, 2024.
============================================================================
*/

int main() {
  for( ; ; );

  return 0;
}

/*
============================================================================
Command line: ./a.out &
Output: 46254
command line : ps 46254 
// (/proc/46254 - does not work in mac)
============================================================================
*/
