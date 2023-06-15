#ifndef KULLANICI_H
#define KULLANICI_H //kütüphanenin birden fazla kez include edilmesini önlemek amacıyla kullandık
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <bits/stdc++.h>
#include <conio.h>
#include <iostream>
#include <iomanip>
#include <vector>
#include <locale>

using namespace std;
const int  maximum = 20;
class kulanicilar

{
private:  // kullanıcıya verilmeyecek olan bilgiler burada yer alıyor
// tutar, kullanıcı adı ve şifre kullanıcıya verilmeyecek olan bilgilerdir
    double tutar = 0;
    string kullaniciadi = "admin";
    string sifre = "admin123.";

public: //genel üye değişkenlerinin olduğu bölüm
    string user = kullaniciadi;
    string password = sifre;
    char kullanici_name[maximum];
    char kullanici_username[maximum];
    int kullanici_table;
    char kullanici_phone[10];
    void set_price(double fiyat) //Ödeme tutarını ayarlamak için kullanılır.
    {
        tutar = fiyat;
    }
    void borc() //Ödenecek toplam ücreti ekrana yazdırır.
    {
        cout << "Ödenecek toplam ücret: " << tutar << "TL" << endl
             << endl;
    }
};
class urun // ürün sınıfı ürünlerin fiyatlarını tutmak için kullanılır
{
public:
    double fiyat[9];
    void urunler(); // ürünleri listelemede kullanılıyor
    void fiyat_belirle(); // ürün fiyatlarını belirler
};
void Musteriler(); // müşteri bilgilerini işler
void urun_list(); // ürün listesini işler
void siparis(); // siparişleri işler
void Fatura(); // faturaları işler
#endif // define'ı kapatır