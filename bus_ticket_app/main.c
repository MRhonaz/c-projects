#include <stdio.h>
#include <stdlib.h>
#include <string.h>



// Fonksiyon prototipleri
void yoneticigiris();
void kullanicigiris();
void alimislem(const char *varis, int toplam);
int ADMIN_ID=0;
int ADMIN_PASSWORD =0;


int main() {
    int giris;

    while (1) {
        // Menü
        printf("\n1 - Yonetici Girisi\n2 - Kullanici Girisi\n3 - Cikis\nSeciminiz: ");
        scanf("%d", &giris);

        if (giris == 3) {
            printf("Cikis yaptiniz.\n");
            break;
        }

        if (giris == 1) {
            yoneticigiris();
        } else if (giris == 2) {
            kullanicigiris();
        } else {
            printf("Gecersiz secim, lutfen tekrar deneyin.\n");
        }
    }

    return 0;
}

// Yönetici giriþi
void yoneticigiris() {
    int id, password;
    int yonetici_id,yonetici_password;
    printf("Yonetici numaranizi giriniz: ");
    scanf("%d", &id);
    printf("Sifrenizi giriniz: ");
    scanf("%d", &password);

    if (id == ADMIN_ID && password == ADMIN_PASSWORD) {
        printf("Yonetici girisi basarili.\n");
    } else {
        printf("Yonetici ID veya sifre yanlis.\n");
    }
    FILE *file;
    file =fopen ("admin_data.txt","r");
    if(file==NULL){
    	pritnf("Yönetici verileriniz bulunamadi\n");
		return;
			}
    	fscanf(file, "%d",yonetici_id);
		fscanf(file,"%d",yonetici_password);    	
		fclose(file);
		printf("Yonetici numaranizi giriniz\n");
		scanf("%d",id);
		printf("Yonetici sifrenizi giriniz\n");
		scanf("%d",password);
    	if(id==yonetici_id&&password==yonetici_password){
    		printf("yonetici girisi basarili\n");
		}
		else{
			printf("Yonetici id veya sifre yanlis ");
			
		}
    
    
    
    
}

// Kullanýcý giriþi
void kullanicigiris() {
    int id, password;
    printf("Kullanici numaranizi giriniz: ");
    scanf("%d", &id);
    printf("Sifrenizi giriniz: ");
    scanf("%d", &password);

    if (id == ADMIN_ID && password == ADMIN_PASSWORD) {
        printf("Kullanici girisi basarili.\n");

        // Þehir seçimi
        printf("Gitmek istediginiz yeri seciniz:\n");
        printf("1 - Istanbul (1000 TL)\n2 - Siirt (2000 TL)\n3 - Ankara (800 TL)\n4 - Izmir (400 TL)\n");
        int varisbilet;
        scanf("%d", &varisbilet);

        if (varisbilet == 1) {
            alimislem("Istanbul", 1000);
        } else if (varisbilet == 2) {
            alimislem("Siirt", 2000);
        } else if (varisbilet == 3) {
            alimislem("Ankara", 800);
        } else if (varisbilet == 4) {
            alimislem("Izmir", 400);
        } else {
            printf("Gecersiz secim.\n");
        }
    } else {
        printf("Kullanici ID veya sifre yanlis.\n");
    }
}

// Bilet iþlemi
void alimislem(const char *varis, int toplam) {
    char isim[20], soyisim[20], tc[12], telefon[12];
    int yas, extrahizmet, hizmetbedel = toplam;

    printf("Isminizi giriniz: ");
    scanf("%19s", isim);
    printf("Soyisminizi giriniz: ");
    scanf("%19s", soyisim);

    printf("TC numaranizi giriniz: ");
    scanf("%11s", tc);

    printf("Yasinizi giriniz: ");
    scanf("%d", &yas);

    if (yas < 18) {
        printf("18 yasindan kucuksunuz. Veli izni gerekiyor.\n");
        return;
    }

    printf("Telefon numaranizi giriniz (11 haneli): ");
    scanf("%11s", telefon);

    printf("Ekstra hizmet ister misiniz? (1 - Evet, 2 - Hayir): ");
    scanf("%d", &extrahizmet);

    if (extrahizmet == 1) {
        printf("Hangi hizmetimizden faydalanmak istersiniz?\n");
        printf("1 - Hizli Wifi (150 TL)\n2 - Cay/Kahve (200 TL)\n3 - Ozel Bagaj (250 TL)\n");
        scanf("%d", &extrahizmet);

        if (extrahizmet == 1) hizmetbedel += 150;
        else if (extrahizmet == 2) hizmetbedel += 200;
        else if (extrahizmet == 3) hizmetbedel += 250;
    }

    printf("Sayin %s %s, %s icin bilet aldiginiz icin tesekkur ederiz.\n", isim, soyisim, varis);
    printf("Telefon numaraniz: %s\n", telefon);
    printf("TC kimlik no'nuz: %s\n", tc);
    printf("Toplam tutar: %d TL\n", hizmetbedel);
}


