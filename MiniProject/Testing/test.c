#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <unistd.h>
#include<termios.h>

void hide_input(char *buffer, int size) {
    struct termios oldt, newt;
    
    // Get the current terminal settings
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;

    // Disable echoing of characters
    newt.c_lflag &= ~ECHO;
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    // Read input
    printf("Enter your input: ");
    fgets(buffer, size, stdin);

    // Restore original terminal settings
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
}



int main()
{
    char input[100];

    hide_input(input, sizeof(input));

    printf("\nYou entered: %s\n", input);

    return 0;
}