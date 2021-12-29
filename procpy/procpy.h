#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <sys/wait.h>

int block(const char * sfile, int pronum);
int check_arg(const char *sfile, int argnum, int pronum);
int procreate(const char *sfile, const char * dfile, int pronum, int block);
