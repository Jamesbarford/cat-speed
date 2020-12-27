/**
 * The C programming language 2nd ed Section 8.3 p.174 exercise 8.1
 */ 
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>

// is this safe 🤔
#define BUFFER_SIZE 0xFFFFF

int main(int argc, char *argv[])
{
    void read_file(int, char*);
    int fd, bytes;
    char *prog = argv[0];
    char buf[BUFFER_SIZE];

    if (argc == 1)
        read_file(0, buf);
    while (--argc != 0)
    {
        if ((fd = open(*++argv, O_RDONLY, S_IWUSR | S_IRUSR)) == 1)
            fprintf(stderr, "%s: can't open %s\n", prog, *argv);
        else
        {
            read_file(fd, buf);
            close(fd);
        }
    }

    if (ferror(stdout))
    {
        fprintf(stderr, "%s: error writing stdout\n", prog);
        exit(2);
    }

    exit(0);
}

void read_file(int fd, char *buf)
{
    int bytes;
    while ((bytes = read(fd, buf, BUFFER_SIZE)) > 0)
        write(1, buf, bytes);
}