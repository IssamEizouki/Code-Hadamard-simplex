#include "biblio.h"



//Question 1 :
//La matrice Ghds est bien systématique puisque G= (I|A), tels que I est la matrice d'identité, A quelconque 
// Autrement dit ( message encodé == message d'origine suivie de l'info redondante)
//ex: ...




char * bin (unsigned short i)
{
    static char buffer [1+sizeof (unsigned long int)*8] = { 0 };
    char *p=buffer-1+sizeof (unsigned long int)*8;
    do { *--p = '0' + (i & 1); i >>= 1; } while (i);
    return p;
}


//2.1
unsigned short set_nth_bit(int n, unsigned short m){

    int decalage = 15-n;
    unsigned short tmp = 1<<decalage;
   // printf("tmp=%s\n",bin(tmp));
    unsigned short l = m|tmp;//OR
    //printf("nouveau m=%s\n",bin(l));

return l;
}

//2.2
unsigned short get_nth_bit(int n, unsigned short m){

    int decalage = 16-n;
  
    unsigned short resultat = (m>>decalage);
 

   /*
    printf("tmp2=%s\n",bin(tmp));
    tmp = m&tmp;//AND
    tmp = 1>>decalage;
    printf("nouveau m2=%s\n",bin(tmp));
    */
   
return resultat%2;
}

//2.3
unsigned short chg_nth_bit(int n, unsigned short m){
    int decalage = 15-n;
    unsigned short tmp = 1<<decalage;
    printf("tmp3=%s\n",bin(tmp));
    unsigned short l = m^tmp;//XOR
    printf("nouveau m3=%s\n",bin(l));

return l;
}

//2.4
void print_word( int k, unsigned short m){

    m=m>>k;
    printf("%s\n",bin(m));

    return;
}

//3
unsigned short encode_had_sys(unsigned short m){
    unsigned short mRes=0b0000000000000000;
    //pour les premiers 4 bits, on ne touche pas car les 4 premieres colones de la matrice Ghd est la matrice d'identité de 4*4
    //à partir du 5ième bit:
    int decalage = 15-4;
    mRes = m>>decalage;
    mRes = mRes<<decalage;
    //Préparation des colonnes de la matrice en tant que mot
    unsigned short Ghds[12];
    Ghds[0]=0b0000000000000000;//colonne 5  000000000000
    Ghds[1]=0b0011000000000000;//colonne 6
    Ghds[2]=0b0101000000000000;//colonne 7
    Ghds[3]=0b0110000000000000;//colonne 8
    Ghds[4]=0b0111000000000000;//colonne 9
    Ghds[5]=0b1001000000000000;//colonne 10
    Ghds[6]=0b1010000000000000;//colonne 11
    Ghds[7]=0b1011000000000000;//colonne 12
    Ghds[8]=0b1100000000000000;//colonne 13
    Ghds[9]=0b1101000000000000;//colonne 14
    Ghds[10]=0b1110000000000000;//colonne 15
    Ghds[11]=0b1111000000000000;//colonne 16
    
    //phase de calcule : 
    unsigned short tmp1=0b0;
    unsigned short tmp2=0b0;
     short test=0b0;
    unsigned short controleB=0b0;
    int i=0,j = 0;
    for(i=0;i<12;i++){
        
        controleB=0b0;
        tmp1=0b0;
        tmp2=0b0;
        for (j=1;j<5;j++){
            
            tmp1=get_nth_bit(j,Ghds[i]);
            tmp2=get_nth_bit(j,mRes);
            controleB^=(tmp1&tmp2);

        }
        
            
        if(controleB)
            mRes=set_nth_bit(i+4,mRes);
    }
    
    return mRes;
}

//4.1
int cnt_bits(unsigned short n){
    int resultat=0;
    int i = 1;
    while (i<17)
    {
        if(get_nth_bit(i,n))
            resultat++;
        
        i++;
    }
    return resultat;
}


//4.2
int dist_code_hds(){
    int resultat=0;

    return resultat;
}


//Q4.3??