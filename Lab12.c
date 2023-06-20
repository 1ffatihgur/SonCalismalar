#include<stdio.h>
#include<stdlib.h>

int ogr_no;
char isim[20];
char soyisim[20];
char bolum[20];

FILE *dosya;

void dosya_olustur()
{
	
	dosya=fopen("Lab12.txt","w");
	
	printf("DOSYA OLUSTURULDU!");
	
	fclose(dosya);
}

void kayit_ekle()
{
	
	dosya = fopen("Lab12.txt","a");
	
	printf("Ogrencinin adi:\n"); gets(isim);
	printf("Ogrencinin soyadi:\n"); gets(soyisim);
	printf("Ogrencinin numarasi:\n"); scanf("%d",&ogr_no);
	printf("Ogrencinin bolum:\n"); gets(bolum);
	
	fprintf(dosya,"Adi-Soyadi: %s\t%s\t%d\t%s\n",isim,soyisim,ogr_no,bolum);
	
	fclose(dosya);
	
}




int main()
{
	
	int secim;
	
	printf("1-Dosya Olustur\n");
	printf("2-Kayýt Ekle\n");
	printf("3-Isme Gore Ogrenci Ara ve Bilgilerini Ekrana Yazdir\n");
	printf("4-Ogrencileri Listele\n");
	printf("5- Cikis Yap\n\n");
	
	printf("Lutfen secim yapiniz: ");
	scanf("%d",&secim);
	
	switch(secim)
	{
		case 1:
			{
				dosya_olustur();
			}
		
		case 2:
			{
				kayit_ekle();
			}
	}
	
	
	
	
	
	
	
	return 0;
}
