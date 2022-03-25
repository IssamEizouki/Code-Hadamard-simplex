#include "biblio.h"




int main(int argc, char**argv){

short x = 0b101111111111111;

printf("\nFonction 1 / set_nth_bit\n");
    printf("x= %s \n",bin(x));
    x= set_nth_bit(2,x);
    printf("nieme a 1 : resultat =%s\n",bin(x));

printf("\nFonction 2 / get_nth_bit:\n");

    printf("x= %s \n",bin(x));
    x= get_nth_bit(2,x);
    printf("Change nieme : resultat =%s\n",bin(x));
  
    return 0;
}
