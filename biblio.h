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



char * bin (unsigned short i);

unsigned short set_nth_bit(int n, unsigned short m);

unsigned short get_nth_bit(int n, unsigned short m);

unsigned short chg_nth_bit(int n, unsigned short m);

void print_word( int k, unsigned short m);

unsigned short encode_had_sys(unsigned short m);

int cnt_bits(unsigned short n);

int dist_code_hds();

unsigned short encode_had_sys_simplexe(unsigned short m);
unsigned short decode(unsigned short m);
void print_word2(const unsigned short m );
