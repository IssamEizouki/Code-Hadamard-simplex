#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <errno.h>
#include <string.h>



char * bin (unsigned long int i);

unsigned short set_nth_bit(int n, unsigned short m);

unsigned short get_nth_bit(int n, unsigned short m);