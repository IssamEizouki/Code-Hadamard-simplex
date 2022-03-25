#include "biblio.h"



//Question 1 :
//La matrice Ghds est bien systématique puisque G= (I|A), tels que I est la matrice d'identité, A quelconque 
// Autrement dit ( message encodé == message d'origine suivie de l'info redondante)
//ex: ...




char * bin (unsigned long int i)
{
    static char buffer [1+sizeof (unsigned long int)*8] = { 0 };
    char *p=buffer-1+sizeof (unsigned long int)*8;
    do { *--p = '0' + (i & 1); i >>= 1; } while (i);
    return p;
}


//fonction 1 : prend en argument un entier n, un mot (encodé sur un short) m, et mets le n-ieme bit du mot à 1. Le mot modifié est retourné.

unsigned short set_nth_bit(int n, unsigned short m){

    int decalage = 15-n;
    unsigned short tmp = 1<<decalage;
    printf("tmp=%s\n",bin(tmp));
    unsigned short l = m|tmp;//OR
    printf("nouveau m=%s\n",bin(l));

return l;
}


unsigned short get_nth_bit(int n, unsigned short m){
    int decalage = 15-n;
    unsigned short tmp = 1<<decalage;
    printf("tmp2=%s\n",bin(tmp));
    unsigned short l = m^tmp;//XOR
    printf("nouveau m2=%s\n",bin(l));

return l;
}