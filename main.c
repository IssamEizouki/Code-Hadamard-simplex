#include "biblio.h"




int main(int argc, char**argv){

unsigned short x = 0b101111111111111;

printf("\nFonction 1 / set_nth_bit\n");
    printf("x1= %s \n",bin(x));
    x= set_nth_bit(2,x);
    printf("nieme a 1 : resultat =%s\n",bin(x));



printf("\nFonction 2 / get_nth_bit\n");
    x = 0b0101111111111110;
    printf("x2= %s \n",bin(x));
    printf("return 1ier : resultat =%s\n",bin(get_nth_bit(1,x)));
    printf("return 2ieme : resultat =%s\n",bin(get_nth_bit(2,x)));
    printf("return 3ieme : resultat =%s\n",bin(get_nth_bit(3,x)));
    printf("return 4ieme : resultat =%s\n",bin(get_nth_bit(4,x)));



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
    x = 0b1011000000000000;
    printf("x4= %s \n",bin(x));
    printf("%s\n",bin(encode_had_sys(x)));
    
printf("\nFonction 6 / cnt_bits:\n");
    x = 0b101111111111111;
    printf("x4= %s \n",bin(x));
    printf("nb de bits a 1 = %d\n",cnt_bits(x));


printf("\nFonction 7 / dist_code_hds:\n");
   dist_code_hds();


printf("\nFonction 8 / encode_had_sys_simplexe:\n");
    x = 0b101100101000000;
    printf("x4= %s \n",bin(x));
    printf("%s\n",bin(encode_had_sys_simplexe(x)));


printf("\nFonction 9-q9 / decode:\n");
    x = 0b1010101010101010;
    printf("x5= %s \n",bin(x));
    x=decode(x);
    print_word2(x);


printf("\nFonction 10-q10.2 / decodeV2:\n");
    x = 0b0011101001001010;
    print_word2(x);
    x=decodeV2(x);
    printf("Resltat : ");
    print_word2(x);
    

printf("\nFonction 11 -q12 / mod_poly_simplex\n");
    x = 0b1110000000000000;
    print_word2(x);
    x=mod_poly_simplex(x);
    printf("Resltat : ");
    print_word2(x<<4);
  


printf("\nFonction 12 -q13 / decode_poly\n");
    x = 0b1010111100100010;
    

    print_word2(x);
    x=decode_poly(x,x,0);
    printf("Resltat : ");
    print_word2(x);


  
return 0;
}



