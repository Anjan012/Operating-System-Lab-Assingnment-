// Write a C program using read() and write() system call that reads 10 bytes of input from the standard input device and stores them in a buffer.

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    char buffer[10];  // Buffer to store 10 bytes of input
    ssize_t bytesRead;

    // Prompt the user to enter some input
    write(STDOUT_FILENO, "Enter 10 characters: ", 21);

    // Read 10 bytes from the standard input (keyboard)
    bytesRead = read(STDIN_FILENO, buffer, 10);

    // Check if read was successful
    if (bytesRead == -1) {
        write(STDOUT_FILENO, "Error reading input.\n", 21);
        return 1; // Return error if reading fails
    }

    // Output the data read from standard input
    write(STDOUT_FILENO, "You entered: ", 13);
    write(STDOUT_FILENO, buffer, bytesRead);

    return 0;
}
