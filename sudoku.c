#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "lib/biblio.h"

int main(int argc, char **argv)
{
    int buffer[1024];
    int fd = open(argv[1], 'r');
    int size = read(fd, buffer, 1024);

    write(1, buffer, size);
    close(fd);

    return 0;
}
