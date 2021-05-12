#include<stdio.h>
#include<stdlib.h>

#define MAX_STR_LEN 2048
#define NUM_LINES 4

void caesar_cipher(unsigned char plaintext[MAX_STR_LEN], unsigned char password[MAX_STR_LEN]){
    //Variables for Password Value
    int count = 0;
    int displacement = 0;

    //Calculate Length of Password
    int len = 0;
    for(int i = 0; password[i]; i++){
        len++;
    }

    for(int j = 0; plaintext[j]; j++){
        //Calculate Displacement
        displacement = count % len;

        //Encode Character
        plaintext[j] = (plaintext[j] + password[displacement] + 256) % 256;

        //If Delimeter Encode Again
        if(plaintext[j] == 0){
            plaintext[j] = plaintext[j] + password[displacement];
        }

        //Next Letter
        count++;
    }
}

void caesar_decipher(unsigned char cryptotext[MAX_STR_LEN], unsigned char password[MAX_STR_LEN]){
    //Variables for Password Value
    int count = 0;
    int displacement = 0;

    //Calculate Length of Password
    int len = 0;
    for(int i = 0; password[i]; i++){
        len++;
    }

    for(int j = 0; cryptotext[j]; j++){
        //Calculate Displacement
        displacement = count % len;

        //Decode Character
        cryptotext[j] = (cryptotext[j] - password[displacement] + 256) % 256;

        //If Delimeter Decode Again
        if(cryptotext[j] == 0){
            cryptotext[j] = cryptotext[j] - password[displacement];
        }

        //Next Letter
        count++;
    } 
}

int main(){
    unsigned char passage[NUM_LINES][MAX_STR_LEN]={"Lebron James\n    Los Angeles Lakers\n",
                                    "Kyrie Irving\n    Brooklyn Nets\n",
                                    "Devin Booker\n    Phoenix Suns\n",
                                    "Jimmy Butler\n    Miami Heat\n"};

    unsigned char password[MAX_STR_LEN] = "Lakers in 4";
 
    printf("**** Original Input Text Lines:\n\n");
    for (int i=0; i<NUM_LINES; i++)
        printf("%s",passage[i]);

    // Encode the input test lines
    for (int i=0; i<NUM_LINES; i++)
    	caesar_cipher(&passage[i][0], &password[0]);

    printf("\n**** Encrypted Text Lines:\n\n");
    for (int i=0; i<NUM_LINES; i++)
        printf("%s",passage[i]);

    // Decode the encrypted strings
    for (int i=0; i<NUM_LINES; i++)
    	caesar_decipher(&passage[i][0], &password[0]);

    printf("\n\n**** Decoded Text Lines:\n\n");
    for (int i=0; i<NUM_LINES; i++)
        printf("%s",passage[i]);
    
    return 0;
}
