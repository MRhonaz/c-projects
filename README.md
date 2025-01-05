# Yönetici ve Kullanıcı Giriş Sistemi

Bu proje, yönetici ve kullanıcı giriş işlemlerini simüle eden bir C programıdır. Program, yönetici ve kullanıcı girişlerinin kontrolünü yapar, bilet alım işlemlerini gerçekleştirir ve log dosyası oluşturarak giriş denemelerini kaydeder.

---

## Özellikler

- **Yönetici Girişi**:
  - Yönetici ID ve şifre doğrulaması yapılır.
  - Giriş denemeleri bir log dosyasına (`log.txt`) tarih ve saat bilgisi ile kaydedilir.

- **Kullanıcı Girişi**:
  - Kullanıcılar, belirlenen ID ve şifreyi girerek sisteme erişebilir.
  - Şehir seçimi ve bilet işlemleri yapılabilir.

- **Bilet İşlemleri**:
  - Kullanıcılar, isim, soyisim, TC kimlik numarası, telefon numarası gibi bilgileri girdikten sonra bilet alabilir.
  - Ekstra hizmet seçenekleri sunulur:
    - Hızlı Wi-Fi
    - Çay/Kahve
    - Özel Bagaj

- **Dosya İşlemleri**:
  - Yönetici giriş logları `log.txt` dosyasına kaydedilir.
  - Loglar tarih ve saat bilgisi ile saklanır.

---

## Gereksinimler

- Bir C derleyicisi (Örneğin: GCC, Clang veya Dev-C++).
- `<stdio.h>`, `<stdlib.h>`, `<string.h>`, `<time.h>` gibi C kütüphanelerine erişim.

---

## Kullanım



```bash
gcc -o yonetici_kullanici yonetici_kullanici.c
./yonetici_kullanici
