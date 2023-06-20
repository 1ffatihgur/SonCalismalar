#include <stdio.h>

struct Ogrenci
{
    int ogr_no;
    char isim[20];
    char soyisim[20];
    char bolum[20];
};  

int main()
{
    struct Ogrenci bosOgr = { 0, "", "", "" };
    int i;

    FILE *dosya;

    if ((dosya = fopen("Lab13_1.txt", "w")) != NULL)
    {

        for (i = 0; i < 3; i++)
        {
            fwrite( &bosOgr, sizeof(struct Ogrenci), 1, dosya);
        }
        fclose(dosya);
    }

    printf("3 kisilik yer ayrildi...\n\n");

    if ((dosya = fopen("Lab13_1.txt", "r+")) != NULL)
    {

        printf("3 ogrenci icin ogrenci icin giris yapin: \n");

        for (i = 0; i < 3; i++)
        {
            printf("%d. ogrenci icin ogrenci no: isim-soyisim: bolum: ", i + 1);
            scanf("%d %s %s %s", &bosOgr.ogr_no, bosOgr.isim, bosOgr.soyisim, bosOgr.bolum);

            fseek(dosya, (bosOgr.ogr_no - 1) * sizeof(struct Ogrenci), SEEK_SET);

            fwrite(&bosOgr, sizeof(struct Ogrenci), 1, dosya);
        }
        fclose(dosya);
    }

    printf("3 ogrenci icin kayit tamamlandi...\n\n");

    if ((dosya = fopen("Lab13_1.text", "r")) != NULL)
    {

        printf("%s\t%s\t%s\t%s\n", "Numara", "isim", "soyisim", "Bolum");

        while (!feof(dosya))
        {

            fread(&bosOgr, sizeof(struct Ogrenci), 1, dosya);
            printf("%d\t%s\t%s\t%s\n", bosOgr.ogr_no, bosOgr.isim, bosOgr.soyisim, bosOgr.bolum);
        }
        fclose(dosya);
    }

    printf("\nMusteri okuma islemi tamamlandi...\n");

    return 0;
}
