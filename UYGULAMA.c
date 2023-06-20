#include<stdio.h>

struct hasta
{
	int hastano;
	char isim[20];
	char soyisim[20];
	int yas;
	char hastalik[20];
};

struct hasta boshasta = { 0, "", "", 0, ""	};

FILE *dosya;

	
void hastagiris()
{
	
	int i;
	

	
	if((dosya =fopen("hastagiris.txt","a")) == NULL)
	{
		printf("Dosya Yok!");
	}
	else
	{
		
		for(i=0; i<100;  i++)
		{
			fwrite(&boshasta, sizeof(struct hasta), i, dosya);
		}
		fclose(dosya);
		
	}
	printf("100 kisilik hasta icin yer ayrildi.\n");
	
	
	if((dosya=fopen("hastagiris.txt","r+")) == NULL)
	{
		printf("HATA0");
	}
	else 
	{
		printf("3 HASTA ICIN KAYIT ISLEMI\n");
		for(i=0; i<3; i++)
		{
			printf("%d. hasta icin hasta numarasi: ad: soyad: yas: hastalik: ",i+1);
			scanf("%d %s %s %d %s",&boshasta.hastano, boshasta.isim, boshasta.soyisim, &boshasta.yas, boshasta.hastalik);
			
			fseek(dosya, (boshasta.hastano-1) * sizeof(struct hasta), SEEK_SET);
			
			fwrite(&boshasta, sizeof(struct hasta), 1, dosya);
		}
		fclose(dosya);
	}
	printf("3 kisilik hasta icin kayit yapildi.\n");
	
}

void listele()
{
	
	if((dosya = fopen("hastagiris.txt","r")) == NULL )
	{
		printf("HATA0");
	}
	else
	{
		
		printf("\n3 hasta listelenecek...\n");
		
		printf("%s %s %s %s %s ","Hasta No","Isim","Soyisim","Yas","Hastalik");	
		
		while(!feof(dosya))
		{
			fread( &boshasta, sizeof(struct hasta), 1, dosya);
			if(boshasta.hastano>0 && boshasta.hastano<100)
			{
				
				printf("\n%d\t%s\t%s\t%d\t%s",boshasta.hastano,boshasta.isim,boshasta.soyisim,boshasta.yas,boshasta.hastalik);
			}
			
		}
		fclose(dosya);
		
	}
	
	printf("\nMusteri okuma islemi tamam");
	
}

void arama_yap()
{
	
	if((dosya = fopen("hastagiris.txt","r")) == NULL )
		{
			printf("HATA0");
		}
	
	struct hasta aranan = { 0, "", "", 0, ""};
	int aranan_no;
	
	printf("aradiginiz hasta numarasini giriniz: ");
	scanf("%d",&aranan_no);
	

	while (fread(&boshasta, sizeof(struct hasta),1,dosya) == 1){
    	
    	if (aranan_no == boshasta.hastano)
		{
		
		printf("\n%d\t%s\t%s\t%d\t%s",boshasta.hastano,boshasta.isim,boshasta.soyisim,boshasta.yas,boshasta.hastalik);
		fclose(dosya);
		return; 
	
   	    }
   	    
	}
	fclose(dosya);
	printf("Hasta bulunamadý.");	
	

}





int main()
{
	
	printf("1 - Hasta Giris\n");
	printf("2 - Hasta Listele\n");
	printf("3 - Hasta Arama\n");
	printf("5 - ...\n\n");
	
	int secim;
	
	printf("secim yapiniz: ");
	scanf("%d",&secim);
	
	switch(secim)
	{
		case 1 :
			{
				hastagiris(); break;
			}
			
		case 2:
			{
				listele();	break;
			}	
			
		case 3:
			{
				arama_yap();	break;
			}	
	}
	
	
	
	
	
	
	
	
	
	return 0;
}

