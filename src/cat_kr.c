/**
 * The C programming language 2nd ed Section 7.6 p.163
 */ 
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *fp;
    void file_copy(FILE *, FILE *);
    char *prog = argv[0];

    if (argc == 1)
        file_copy(stdin, stdout);
    else
        while (--argc > 0)
        {
            if ((fp = fopen(*++argv, "r")) == NULL)
                fprintf(stderr, "%s: can't open %s\n", prog, *argv);
            else
            {
                file_copy(fp, stdout);
                fclose(fp);
            }
        }

    if (ferror(stdout))
    {
        fprintf(stderr, "%s: error writing stdout\n", prog);
        exit(2);
    }

    exit(0);
}

void file_copy(FILE *ifp, FILE *ofp)
{
    int c;
    while ((c = getc(ifp)) != EOF)
        putc(c, ofp);
}