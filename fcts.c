#include "biblio.h"



//Question 1 :
//La matrice Ghds est bien systématique puisque G= (I|A), tels que I est la matrice d'identité, A quelconque 
// Autrement dit ( message encodé == message d'origine suivie de l'info redondante)




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
   
return resultat%2;
}

//2.3
unsigned short chg_nth_bit(int n, unsigned short m){
    int decalage = 15-n;
    unsigned short tmp = 1<<decalage;
    unsigned short l = m^tmp;//XOR

return l;
}

//2.4
void print_word( int k, unsigned short m){

    m=m>>k;
    printf("%s\n",bin(m));

    return;
}
unsigned short Ghds[16];//Matrice Ghds

//3
unsigned short encode_had_sys(unsigned short m){
    unsigned short mRes=0b0000000000000000;
    //pour les premiers 4 bits, on ne touche pas car les 4 premieres colones de la matrice Ghd est la matrice d'identité de 4*4
    //à partir du 5ième bit:
    int decalage = 15-4;
    mRes = m>>decalage;
    mRes = mRes<<decalage;
    //Préparation des colonnes de la matrice en tant que mot
    
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




//4.2&&4.3
/*
La distance d'un code est le minimum distance de Hamming entre deux mots de code distincts, 
c'est-à-dire le nombre minimum de positions auxquelles deux mots de code distincts diffèrent. 
Comme le code de Hadamard est un code linéaire,
la distance est égale au minimum poids de Hamming entre tous ses mots-codes non nuls. 
Le poids de Hamming d'un élément a correspond à la distance entre le mot zéro et a.
Wikipedia
*/


/*
Il y a deux manières pour ce faire:
1) En calculant tous les poids de hamming de tous les mot du code et en en trouvant le minimum
2) En calculant la distance de cahque couple de mots du code et en en trouvant le minimum 

*/
//4.2 --Méthode 2 car plus détaillée
int dist_code_hds(){
    int resultat=16, dist_i =0;
    unsigned short tmp1 = 0b0;
    unsigned short tmp2 = 0b0;
    unsigned short tmp3 = 0b0;
    Ghds[12]=0b1000000000000000;
    Ghds[13]=0b0100000000000000;
    Ghds[14]=0b0010000000000000;
    Ghds[15]=0b0001000000000000;

    for(int i=0;i<16;i++){
        for(int j=i;j<16;j++){
            if(j==i)
                continue;
            tmp2=encode_had_sys(Ghds[i]);
            tmp3=encode_had_sys(Ghds[j]);
            tmp1=tmp2^tmp3; 
            dist_i=cnt_bits(tmp1);
            printf(" resultat=%d // dist_i = %d\n",resultat,dist_i);
            if(dist_i<resultat)
                resultat=dist_i;
        }
    }
    printf("%d\n",resultat);
    return resultat;
}
//la distance minimale = 8
//On peut detecter 7 erreur
//On peut corriger 3 erreur
//voir le formule suivant:
//detecter= distMin-1
//Corriger = (distMin-1)/2 


//En effet il aurait suffit de regarder un couple de mot valide (au hasard) pour determiner
//la distance minimale, puisqu'ils sont tous de la meme distance(propriete)
//Ou encore mieux, on aurait pu calculer seulement le minimum des poids de hamming des mots de ce code
//ce qui nous donnerait la distance minimum(puisque le code hamming est un code linéaire) 
//8 dans notre cas (en vérité 16/2)


//Question 5 :
//La colonne nulle .....



//Question 6

//3
unsigned short encode_had_sys_simplexe(unsigned short m){ //A verifier
    unsigned short mRes=0b000000000000000;
    //pour les premiers 4 bits, on ne touche pas car les 4 premieres colones de la matrice Ghd est la matrice d'identité de 4*4
    //à partir du 5ième bit:
    int decalage = 15-4;
    mRes = m>>decalage;
    mRes = mRes<<decalage;
    //Préparation des colonnes de la matrice en tant que mot
    
    Ghds[0]=0b0011000000000000;//colonne 5
    Ghds[1]=0b0101000000000000;//colonne 6
    Ghds[2]=0b0110000000000000;//colonne 7
    Ghds[3]=0b0111000000000000;//colonne 8
    Ghds[4]=0b1001000000000000;//colonne 9
    Ghds[5]=0b1010000000000000;//colonne 10
    Ghds[6]=0b1011000000000000;//colonne 11
    Ghds[7]=0b1100000000000000;//colonne 12
    Ghds[8]=0b1101000000000000;//colonne 13
    Ghds[9]=0b1110000000000000;//colonne 14
    Ghds[10]=0b1111000000000000;//colonne 15
    
    //phase de calcule : 
    unsigned short tmp1=0b0;
    unsigned short tmp2=0b0;
    short test=0b0;
    unsigned short controleB=0b0;
    int i=0,j = 0;
    for(i=0;i<11;i++){
        
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



//Question 8 : 
unsigned short H[11];//Matrice H 
unsigned short HCols[21];//Transposee de H 
/***
 *  Fct : Initialisation de la matrice de parieté H de G(prevu de sa colonnes nulle)
 * */
void init_H_lignes(){

    H[0]=0b0011100000000000;//ligne 1
    H[1]=0b0101010000000000;//ligne 2
    H[2]=0b0110001000000000;//ligne 3
    H[3]=0b0111000100000000;//ligne 4
    H[4]=0b1001000010000000;//ligne 5
    H[5]=0b1010000001000000;//ligne 6
    H[6]=0b1011000000100000;//ligne 7
    H[7]=0b1100000000010000;//ligne 8
    H[8]=0b1101000000001000;//ligne 9
    H[9]=0b1110000000000100;//ligne 10
    H[10]=0b1111000000000010;//ligne 11
}

void init_H_Cols(){

    HCols[0]=0b0000111111100000;//colonne 1
    HCols[1]=0b0111000111100000;//colonne 2
    HCols[2]=0b1011011001100000;//colonne 3
    HCols[3]=0b1101101010100000;//colonne 4
    HCols[4]=0b1000000000000000;//colonne 5
    HCols[5]=0b0100000000000000;//colonne 6
    HCols[6]=0b0010000000000000;//colonne 7
    HCols[7]=0b0001000000000000;//colonne 8
    HCols[8]=0b0000100000000000;//colonne 9
    HCols[9]=0b0000010000000000;//colonne 10
    HCols[10]=0b0000001000000000;//colonne 11
    HCols[11]=0b0000000100000000;//colonne 12
    HCols[12]=0b0000000010000000;//colonne 13
    HCols[13]=0b0000000001000000;//colonne 14
    HCols[14]=0b0000000000100000;//colonne 15
    HCols[15]=0b0000000000010000;//colonne 16
    HCols[16]=0b0000000000010000;//colonne 17
    HCols[17]=0b0000000000001000;//colonne 18
    HCols[18]=0b0000000000000100;//colonne 19
    HCols[19]=0b0000000000000010;//colonne 20
    HCols[20]=0b0000000000000001;//colonne 21

}

/**
 * Fct affichant un nb bin codé en short (16bits)
 * En prenant en compte les 0 à gauche
 * param(in) : un mot en short
 * param(out): -
 * */
void print_word2(const unsigned short m)
{  
  unsigned short bit = 0 ;
  unsigned short mask = 1 ;
  char* buffer = calloc( 16 + 1, sizeof( char ) );
  int i;
  for (i = 0 ; i < 16 ; ++i) {
    bit = (m & mask) >> i ;
    buffer[ 16 - 1 - i ] = (char)('0' + bit);
    mask <<= 1 ;
  }
  buffer[16] = '\0';
  printf("%s\n",buffer);
}



/**
 * Prends un mot encodé à 16 bits et mettre les derniers 5 bits a 0
 * */
unsigned short onze_bits(unsigned short m){
unsigned mRes = m>>5;
mRes = mRes<<5;
return mRes;
}


//Question 9: 

/***
 * Fct decode : Decodage d'un mot en fonction de la matrice de parité H.
 * param(in): mot à decoder
 * param(out): syndrome (les 11 premiers bits de gauche à droite)
 * Attention l'affichage de ce syndrome de retour doit etre effectuer avec la fct print_word2
 * */
unsigned short decode(unsigned short m){
unsigned short mRes=0b0;
//initialisation de la matrice de parité H
init_H_lignes();
//Decodage:
    unsigned short tmp1=0b0;
    unsigned short tmp2=0b0;
    short test=0b0;
    unsigned short controleB=0b0;
    int i=0,j = 0;
    for(i=0;i<11;i++){
        
        controleB=0b0;
        tmp1=0b0;
        tmp2=0b0;
        for (j=1;j<16;j++){
            tmp1=get_nth_bit(j,H[i]);
            tmp2=get_nth_bit(j,m);
            controleB^=(tmp1&tmp2);
        }
        if(controleB){
            mRes=set_nth_bit(i,mRes);
        }
    }
return mRes;
}


//Question 10.1 : Rapport 


//Question 10.2 : decodeV2

/***
 * Fct decodeV2 : Decodage d'un mot en fonction de la matrice de parité H.
 * param(in): mot à decoder
 * param(out): le mot apres coorection de 3 erreurs
 * Attention l'affichage de ce mot de retour doit etre effectuer avec la fct print_word2
 * */
unsigned short decodeV2(unsigned short m){
unsigned short mRes=0b0;
//initialisation de la matrice de parité H
//Decodage:
mRes=decode(m);//syndrome
init_H_Cols();
    print_word2(mRes);
    if(mRes!=0){
        
        for ( int i =0 ; i<11;i++){
            if(mRes==HCols[i]){
                m=chg_nth_bit(i,m);
                printf("Ce mot contenait une erreur au %dieme bit et ca ete corrigé\n ",i+1);
                return m;
            }
            for (int j = i+1 ; j<11;j++){
                if(mRes == (HCols[j] ^ HCols[i])){
                m=chg_nth_bit(i,m);
                m=chg_nth_bit(j,m);
                printf("Ce mot contenait 2 erreurs au %dieme bit et au %dieme bit ca ete corrigé\n ",i+1,j+1);
                return m;  
                }
                for ( int k= j+1;k<11;k++){
                    if(mRes == (HCols[i]^HCols[j]^HCols[k])){
                    m=chg_nth_bit(i,m);
                    m=chg_nth_bit(j,m);
                    m=chg_nth_bit(k,m);
                    printf("Ce mot contenait 3 erreurs au %dieme, %dieme et %dieme bit ca ete corrigé\n ",i+1,j+1,k+1);
                    return m;  
                    }
                    else {
                        printf(" Ce mot contient plus que 3 erreurs, ce qui dépasse la capacité du code de la correction d'erreurs\n");
                    }
                }
            }
        }
    }
    return m;
}
    //Question 10.3 : Rapport
    //Question 11 : Simplexe polynomial : 
    //Registre de décalage dessiné dans le rapport 

/**
 * Fonction qui sert à initialiser le polynome
 * 
 * */
unsigned short p = 0b0;
void init_p(){
    p= 0b1111010110010000; 
}
    //Question 12 

    /**
     * Fct mod_poly_simplex
     * cette fonction fait la division de message par le poly en utilisant le registre de decalage 
     * elle renvoit le reste de la division
     * param(in) : message
     * param(out) : reste de la division par le poly
     * */
    unsigned short mod_poly_simplex(unsigned short m)
    {
    unsigned short mRes=m;
    unsigned short tmp=0b0000000000000000;
    init_p();
    unsigned short controleB = 0b0;
    for (int i = 0 ; i <4 ; i++){
        controleB = get_nth_bit(i+1,mRes);
        if(controleB){
            tmp = p>>i;
            mRes = mRes ^ tmp;
        }
    }
    mRes = mRes; 
    return mRes;
}



//Question 13 :
unsigned short decode_poly(unsigned short m,unsigned short mPrincipale, int countDecalage){
    unsigned short tmp = 0b0;
    int condition = 1;
    while(condition){
        unsigned short  reste= mod_poly_simplex(m);
        if(cnt_bits(reste)<=3){//le reste est le vecteur d'erreur 
            //il suffit d'ajouter le reste au message
            m= m^reste ;
            condition = 0;
        }
        else {
            countDecalage++;
            m=mPrincipale<<countDecalage;
        }
    }
    tmp = mPrincipale >> (16-countDecalage);
    
    m=m<<countDecalage;

    m = tmp | m;

    return m;
}
