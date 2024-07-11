#include <stdio.h> // for printf()
#include <stdlib.h> // for exit()
#include <unistd.h> // for open(), write(), read(), lseek(), close()
#include <fcntl.h> // for O_RDWR, O_CREAT

int main() {
    int fd; // file descriptor
    char buf[100]; // buffer for reading data from file
    ssize_t nread, nwritten; // number of bytes read or written

    // Open the file for reading and writing
    fd = open("osfile.txt", O_RDWR | O_CREAT, 0644);
    if (fd == -1) {
        perror("open failed");
        exit(1);
    }

    // Write some data to the file
    nwritten = write(fd, "Hello", 5);
    if (nwritten == -1) {
        perror("write failed");
        close(fd);
        exit(1);
    }

    // Move the file position to the beginning of the file
    lseek(fd, 0, SEEK_SET);

    // Read the data from the file
    nread = read(fd, buf, sizeof(buf) - 1);
    if (nread == -1) {
        perror("read failed");
        close(fd);
        exit(1);
    }
    buf[nread] = '\0'; // null-terminate the string

    // Print the data to standard output
    printf("The file contains: %s\n", buf);

    // Close the file
    close(fd);

    return 0;
}

