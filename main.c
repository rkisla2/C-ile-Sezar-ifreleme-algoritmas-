#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<locale.h>
#include <math.h>

typedef struct
{
    char AdSoyad[30];
    int OgrenciNo;
    char sifre[30];
    int enBuyukAsalCarpan;
    char Cozum[30];
    char OkunanDeger[30];

}Bilgiler ;
Bilgiler kisi;
FILE *fpointer;
char sifre[30];

void sifrele(char ifade[],int okulNo)
{
  int anahtar;
  anahtar=sonHaneBul(okulNo);
  char sifrelenmisifade[30];
 	char c;
 	for(int i=0;i<strlen(ifade);i++)
        {
          c=ifade[i];
          sifrelenmisifade[i]=(char)(((int)c)+anahtar);
          kisi.sifre[i]=(char)(((int)c)+anahtar);
        }
}
void sifreYazdir()
{

    fpointer=fopen("sifre.txt","w+");
    if(fpointer==NULL)
    {
        printf("sifre.txt dosyasi acilamadi.");
    }
    else
    {
        fprintf(fpointer ,"%s", kisi.sifre );
    }

}
char sifreOku()
{
    fpointer=fopen("sifre.txt","r");
    if(fpointer==NULL)
    {
        printf("sifre.txt dosyasi acilamadi.");
    }
    else
    {
          fgets(kisi.OkunanDeger,15,fpointer);
    }
    fclose(fpointer);
    return kisi.OkunanDeger;

}


int sonHaneBul(int No)
{   int sayi;
    sayi=No%10;
    if(sayi==0)
    {
        sayi=No%100;
        sayi=sayi/10;
    }
    return sayi;
}
char Coz()
{
    int anahtar;
    anahtar=sonHaneBul(kisi.OgrenciNo);
    char c;
    char cozum[30];
    printf("Cozum:");
    for(int i=0;i<strlen(kisi.sifre);i++)
        {
          c=kisi.sifre[i];
          cozum[i]=(char)(((int)c)-anahtar);
          printf("%c",cozum[i]);
        }
    return cozum;
}
int asalCarpanBul(int No)
{
    int i,j;

    for(i=2;No>1;i++)
    {
        while(No%i==0)
        {
            j=i;
            No=No/i;
        }
    }


 return j;
}
void AsalKontrol()
{
    int kontrol;
    printf("Okul numaranizin en buyuk asal carpani nedir?");
 	scanf("%d",&kontrol);

 	if(kontrol==asalCarpanBul(kisi.OgrenciNo))
    {
        printf("Sifre:%s\n",kisi.OkunanDeger);
        Coz();
    }
    else
    {
        printf("Tekrar Deneyiniz\n");
        return AsalKontrol();

    }

}

int main()
{
    char isim[30],sifre[30];
    char c;
    printf("Adinizi Giriniz:  ");
 	gets(kisi.AdSoyad);
 	printf("Okul numaranizi giriniz:  ");
 	scanf("%d",&kisi.OgrenciNo);
 	sifrele(kisi.AdSoyad,kisi.OgrenciNo);
 	sifreYazdir();
 	AsalKontrol();


    return 0;
}
