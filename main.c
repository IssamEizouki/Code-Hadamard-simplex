#include "biblio.h"




int main(int argc, char**argv){

short x = 0b101111111111111;

printf("\nFonction 1 / set_nth_bit\n");
    printf("x1= %s \n",bin(x));
    x= set_nth_bit(2,x);
    printf("nieme a 1 : resultat =%s\n",bin(x));



printf("\nFonction 2 / get_nth_bit\n");
    x = 0b110111111111111;
    printf("x2= %s \n",bin(x));
    x= get_nth_bit(3,x);
    printf("return 3ieme : resultat =%s\n",bin(x));



printf("\nFonction 3 / chg_nth_bit:\n");
    x = 0b101111111111111;
    printf("x3= %s \n",bin(x));
    x= chg_nth_bit(2,x);
    printf("Change %dieme : resultat =%s\n",2,bin(x));
    

printf("\nFonction 4 / print_word:\n");
    x = 0b101111111111111;
    printf("x4= %s \n",bin(x));
    print_word(5,x);
  

printf("\nFonction 5 / encode_had_sys:\n");
    x = 0b101111111111111;
    printf("x4= %s \n",bin(x));
    encode_had_sys(x);
    return 0;
}



