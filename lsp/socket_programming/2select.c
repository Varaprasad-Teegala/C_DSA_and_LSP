#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/select.h>
#include <sys/types.h>
#include <sys/stat.h>

#define BUFFER_SIZE 1024

int main() 
{
    int fd;
    fd_set readfds;
    struct timeval tv;
    int retval;
    char buffer[BUFFER_SIZE];

    fd = open("text1.txt", O_RDONLY);

    FD_ZERO(&readfds);
    FD_SET(fd, &readfds);

    tv.tv_sec = 5;
    tv.tv_usec = 0;

    retval = select(fd + 1, &readfds, NULL, NULL, &tv);

    if (retval) 
    {
        if (FD_ISSET(fd, &readfds)) 
	{
            ssize_t bytes_read = read(fd, buffer, BUFFER_SIZE - 1);
            
            buffer[bytes_read] = '\0'; // Null-terminate the buffer
            printf("Read data: %s\n", buffer);
            
        }
    } 
    else 
    {
        printf("No data within five seconds.\n");
    }

    // Close the file
    close(fd);
    return 0;
}

