#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int flags = 0, opt;
    int nsecs = 0, tfnd = 0;

    while((opt = getopt(argc, argv, "nt:")) != -1) {
            switch (opt) {
                case 'n':
                    flags = 1;
                    break;
                case 't':
                    nsecs = atoi(optarg);
                    tfnd = 1;
                    break;
                default:
					printf("optind = %d\n", optind);
                    printf("optopt = %c\n", (char)optopt);
                    printf("opterr = %d\n", opterr);
                    fprintf(stderr, "usage: %s [-t nsecs] [-n] name\n", argv[0]);
                   exit(EXIT_FAILURE);
            } 
    }
    printf("flags = %d; tfnd = %d; nsecs = %d; optind = %d\n", flags, tfnd, nsecs, optind);

    printf("optind = %d\n", optind);
    printf("argc = %d\n", argc);
#if 1 
    if(optind >= argc) {
        fprintf(stderr, "Expected argument after options\n"); 
        exit(1);
    }
#endif
    printf("name argument = %s\n", argv[optind]);
    /* Other code omitted */
    return 0;
}