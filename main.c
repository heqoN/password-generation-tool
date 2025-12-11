#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void errorr(char *message){
    printf("%s error.Try again.\n\n",message);
}



int menu(void){

    int order;
    while (1){
        printf("\n\n1- Password generator\n2- Password encryptor\n3- Password decryptor\n4- Exit\n\n   >>> ");
        scanf("%d",&order);
        if  (order==1 || order==2 || order==3 || order==4)
            break;
        errorr("Wrong input");
    }

    return order;
}



int ask(char *q,int obb){

    int num;
    while (1){
        printf("%s  >> ",q);
        scanf("%d",&num);

        if (obb==1){
            if (num==1 || num==0)
                return num;
        }
        else{
            if (num>0)
                return num;
        }

        errorr("wrong input");
    }
}



int generatePassword(void){
    int digit,num,character,number,special,write;
    char characters[]="abcdefghijklmnoprstuvyz",numbers[]="123456789",specials[]="!'^+&/()=?_-*.,",password[100];

    num=ask("How many password",0);
    digit=ask("How many digit",0);
    number=ask("Should your password contain numbers (Yes=1 , No=0)",1);
    character=ask("Should your password contain characters (Yes=1 , No=0)",1);
    special=ask("Should your password contain speacial characters (Yes=1 , No=0)",1);
    write=ask("Should your passwords be writed to the file (Yes=1 , No=0)",1);

    if (number==0 && character==0 && special==0){
        errorr("your password have must one of these");
        return 0;
    }

    
    FILE *file = fopen("passwords.txt","w");

    if (file==NULL){
        errorr("file failed");
        return 1;
    }

    int x,y,z,k;
    for (int j=1 ; j<=num ; j++){
            for (int i=0 ; i<digit ; i++){
                y=rand()%strlen(numbers);
                z=rand()%strlen(characters); 
                k=rand()%strlen(specials);
            
                if (number==1 && character==1 && special==1){
                    x=rand()%3;
                    if (x==0)
                        password[i]=numbers[y];
                    else if (x==1)
                        password[i]=characters[z];
                    else
                        password[i]=specials[k];
                }

                else if (number==1 && character==1){
                    x=rand()%2;
                    if (x==0)
                        password[i]=numbers[y];
                    else
                        password[i]=characters[z];
                }

                else if (number==1 && special==1){
                    x=rand()%2;
                    if (x==0)
                        password[i]=numbers[y];
                    else
                        password[i]=specials[k];
                }

                else if (character==1 && special==1){
                    x=rand()%2;
                    if (x==0)
                        password[i]=characters[z];
                    else
                        password[i]=specials[k];
                }
                
                else if (number==1)
                    password[i]=numbers[y];
                
                else if (character==1)
                    password[i]=characters[z];
                
                else
                    password[i]=specials[k];

        

            }

            password[digit] = '\0';
            printf("Generated password : %s\n\n",password);

            if (write==1){
                fprintf(file,"%s\n",password);
            }

    }

    fclose(file);

    printf("Press enter for continue ...");
    getchar();
    getchar();

    return 0;

}



int encryptPassword(void){
    char input[50], key[10];
    unsigned char encrypted[50];
    int len;

    printf("Enter your password  >> ");
    scanf("%49s", input);

    printf("Enter your key  >> ");
    scanf("%9s", key);

    len = strlen(input);

    
    for (int i = 0; i < len; i++) {
        encrypted[i] = input[i] ^ key[i % strlen(key)];
    }

    printf("Your encrypted password (hex) = ");
    for (int i = 0; i < len; i++) {
        printf("%02X ", encrypted[i]);
    }
    printf("\n");

    printf("Password length = %d\n", len);

    printf("Enter for continue ...");
    getchar();
    getchar();

    return 0;
}



int decryptPassword(void){
    char key[10];
    unsigned char decrypted[100];
    char hexInput[300];
    int len;

    printf("Enter password length >> ");
    scanf("%d", &len);

    printf("Enter encrypted password (hex) >> ");
    getchar(); 
    fgets(hexInput, sizeof(hexInput), stdin);

    
    for (int i = 0; i < len; i++) {
        unsigned int val;
        sscanf(&hexInput[i * 3], "%02X", &val);
        decrypted[i] = (unsigned char)val;
    }

    printf("Enter your key >> ");
    scanf("%9s", key);

    
    for (int i = 0; i < len; i++) {
        decrypted[i] ^= key[i % strlen(key)];
    }

    decrypted[len] = '\0'; 

    printf("Your password = %s\n\n", decrypted);

    return 0;
}





int main(void)
{
    srand(time(NULL));

    printf("Welcome to password generation and encryption program.\n\n");

    while (1){
        int order = menu();

        if (order==1)
            generatePassword();

        else if (order==2)
            encryptPassword();

        else if (order==3)
            decryptPassword();

        else if (order==4)
            break;
        
        else
            errorr("wrong input"); 
    }
}

