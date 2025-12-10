#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

int main(void)
{
    srand(time(NULL));
    FILE *dosya = fopen("passwords.txt","w");fprintf(dosya,"");fclose(dosya);
    
    printf("Sifre oluşturma aracina hoşgeldiniz \n\n");

    int basamak,secim1,secim2,yaz,adet;
    char harfler[]="abcdefghijklmnoprstuvyz",sayilar[]="123456789",sifre[100];
    int x,y,z;


    dosya = fopen("passwords.txt","a");

    while (1){

        while(1){
            printf("Kac tane sifre olusturulacak ?  >> ");scanf("%d",&adet);
            if (adet>0)
                break;
            printf("Adet sayisi 0 dan buyuk olmali.\n\n");
        }

        while (1){
            printf("Sifreler dosyaya yazdirilacakmi (txt) (Evet=1 , Hayir=0) ?   >> ");scanf("%d",&yaz);
            if (yaz==1 || yaz==0)
                break;
            printf("Hatali secim.Tekrar Deneyin.");
        }


        while(1){
            printf("Sifreniz kac basamakli olsun ?  >> ");scanf("%d",&basamak);
            if (basamak>0)
                break;
            printf("Basamak sayisini hatali girdiniz.Tekrar deneyin.\n\n");
        } 

        while (1){
            printf("Sifrenizde sayilar olsunmu ? (Evet=1 , Hayir=0)  >> ");scanf("%d",&secim1);
            if (secim1==1 || secim1==0)
                break;
            printf("Yanlis bir giris yaptiniz.Tekrar deneyin.");
        }

        while (1){
            printf("Sifrenizde harfler olsunmu ? (Evet=1 , Hayir=0)  >> ");scanf("%d",&secim2);
            if (secim2==1 || secim2==0)
                break;
            printf("Yanlis bir giris yaptiniz.Tekrar deneyin.");
        }

        if (secim1==0 && secim2==0){
            printf("Sayi veya harften en az 1 ini secmelisiniz!!\n\n");
            continue;
        }

        for (int g=1 ; g<=adet ; g++){
            for (int i=0 ; i< basamak ; i++){
                y=rand()%strlen(sayilar);
                z=rand()%strlen(harfler); 
            
                if (secim1==1 && secim2==1){
                    x=rand()%2;
                    if (x==0)
                        sifre[i]=sayilar[y];
                    else
                        sifre[i]=harfler[z];
                }

                else if (secim1==1)
                    sifre[i]=sayilar[y];
            

                else
                    sifre[i]=harfler[z];

            }

            sifre[basamak] = '\0';
            printf("Olusturulan sifre : %s\n\n",sifre);

            if (yaz==1)
                fprintf(dosya,"%s\n",sifre);


        }

        printf("Kapatmak icin enter a basin  ... ");
        getchar();getchar();
        break;

    }

    fclose(dosya);

    return 0;
}