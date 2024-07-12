#include <stdio.h>
#include <unistd.h>  // For read and write system calls

int main() {
    char c;
    int a = 1;

    while (a != 0) {
        read(0, &c, 1); // Reading one character from standard input
        write(1, &c, 1); // Writing the character to standard output
        write(1, "\n", 1); // Writing a newline to standard output
        a = (c != '0'); // Setting a to 0 if the character is '0', else setting it to 1
    }

    return 0;
}
