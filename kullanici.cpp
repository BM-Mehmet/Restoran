#include "kullanici.hpp"
kulanicilar musteri1;
urun Urun;
// ürünlerin isimlerinin değşkenlere atanması
string s1 = "Türk Kahvesi";
string s2 = "Çay";
string s3 = "Soğuk Çay";
string s4 = "Çikolatalı Kek ";
string s5 = "Meyveli Kek";
string s6 = "3 adet Şöbiyet ";
string s7 = "3 adet Fıstıklı Baklava";
string s8 = "3 adet Fıstık Sarma";
string s9 = "Karışık";
string customer = "Müşteri ";
fstream dosya;                  // fiyat bilgisini tutacak dosya adında bir akış nesnesi tanımlıyoruz
std::vector<double> veriDizisi; // Verileri tutmak için bir int vektörü kullanıyoruz
std::string satir;              // satır değerlerinin geçici olarak yazıldığı değişken
void urun::fiyat_belirle()
{

    dosya.open("datalar\\fiyat.txt");
    if (dosya.is_open())
    {
        while (std::getline(dosya, satir))
        {                                         // Dosyanın her satırını okur
            double veriDouble = std::stod(satir); // Satırı Double'e dönüştürür
            veriDizisi.push_back(veriDouble);     // Dizinin sonuna veriyi ekler
        }
        dosya.close(); // Dosyayı kapat

        int i = 0;
        for (double veri : veriDizisi)
        {
            Urun.fiyat[i] = veri; // veriDizisindeki  verilerin fiyat dizisine aktarılması
            i++;
        }
        std::cout << std::endl;
    }
    else
    {
        std::cout << "Dosya acilamadi." << std::endl;
    }
}

void urun::urunler()
{
    int numara; // ürün başındaki numarayı almak için oluşturulan değişken
    int i = 0;  // kaç adet ürünün fiyatını değiştirdiğini saymak için oluşturulan değişken
    int onay;   // kaç adet ürünün değiştirileceğinin girildiği değişken

    try
    {
        cout << "Kaç adet ürünün fiyatını değiştirmek istiyorsunuz: ";
        cin >> onay;
        if (onay >= 0 && onay < 10)
        {
            while (i < onay) // ürünlerin fiyatının değiştirildiği döngü
            {
                cout << "Fiyatını değiştirmek istediğiniz ürünün başındaki numarayı girin:";
                cin >> numara;
                switch (numara)
                {
                case 1:
                    cout << "Türk Kahvesinin yeni fiyatını girin: ";
                    cin >> veriDizisi[0];
                    Urun.fiyat[0] = veriDizisi[0];
                    break;
                case 2:
                    cout << "Çayın yeni fiyatını girin: ";
                    cin >> veriDizisi[1];
                    Urun.fiyat[1] = veriDizisi[1];
                    break;
                case 3:
                    cout << "Soğuk Çayın yeni fiyatını girin: ";
                    cin >> veriDizisi[2];
                    Urun.fiyat[2] = veriDizisi[2];
                    break;
                case 4:
                    cout << "Çikolatalı Kekin yeni fiyatını girin: ";
                    cin >> veriDizisi[3];
                    Urun.fiyat[3] = veriDizisi[3];
                    break;
                case 5:
                    cout << "Meyveli Kekin yeni fiyatını girin: ";
                    cin >> veriDizisi[4];
                    Urun.fiyat[4] = veriDizisi[4];
                    break;
                case 6:
                    cout << "3 adet Şöbiyetin yeni fiyatını girin: ";
                    cin >> veriDizisi[5];
                    Urun.fiyat[5] = veriDizisi[5];
                    break;
                case 7:
                    cout << "3 adet Fıstık Sarmanın yeni fiyatını girin: ";
                    cin >> veriDizisi[6];
                    Urun.fiyat[6] = veriDizisi[6];
                    break;
                case 8:
                    cout << "3 adet Fıstıklı Baklavanın yeni fiyatını girin: ";
                    cin >> veriDizisi[7];
                    Urun.fiyat[7] = veriDizisi[7];
                    break;
                case 9:
                    cout << "Karışığın yeni fiyatını girin: ";
                    cin >> veriDizisi[8];
                    Urun.fiyat[8] = veriDizisi[8];
                    break;
                }
                i++;
            }
            throw onay;
        }
    }
    catch (int basari) // istenilen kadar ürünün fiyatı başarılı bir şekide değiştirildiğinde kullanıcıya geri bildirim yapan yapı
    {
        cout << basari << " Tane ürünün fiyatı değiştirildi... " << endl
             << endl;
        dosya.open("datalar\\fiyat.txt"); // varsayılan olarak ios::in modunda çalışır yani okuma modunda
        if (dosya.is_open())
        {
            for (int i = 0; i < 9; i++)
            {
                dosya << Urun.fiyat[i] << "\n"; // okuma modunda olsa bile yazma işlemi yapılabilir.
            }
        }
        dosya.close();
    }
}

void urun_list() // ürün bilgilerini ekrana basan kod
{

    cout << "                ***     MENÜ      ***     " << endl
         << endl;
    cout << "*                  ! İçecekler !            *" << endl;
    cout << "1: " << s1 << setw(14) << ":" << setw(17) << Urun.fiyat[0] << "TL" << endl;
    cout << "2: " << s2 << setw(23) << ":" << setw(17) << Urun.fiyat[1] << "TL" << endl;
    cout << "3: " << s3 << setw(17) << ":" << setw(17) << Urun.fiyat[2] << "TL" << endl
         << endl;
    cout << "*                 ! YİYECEKler !            *" << endl;

    cout << "4: " << s4 << setw(11) << ":" << setw(17) << Urun.fiyat[3] << "TL" << endl;
    cout << "5: " << s5 << setw(15) << ":" << setw(17) << Urun.fiyat[4] << "TL" << endl;
    cout << "6: " << s6 << setw(11) << ":" << setw(17) << Urun.fiyat[5] << "TL" << endl;
    cout << "7: " << s7 << setw(3) << ":" << setw(17) << Urun.fiyat[6] << "TL" << endl;
    cout << "8: " << s8 << setw(7) << ":" << setw(17) << Urun.fiyat[7] << "TL" << endl;
    cout << "9: " << s9 << setw(19) << ":" << setw(17) << Urun.fiyat[8] << "TL" << endl;
    cout << endl
         << endl;
}

void Musteriler() // masa bilgisini alan method
{
    cout << customer << "Masa no: ";
    cin >> musteri1.kullanici_table;
    cout << endl
         << endl;
}
void siparis()
{

    int siparis_no; // siparişlerin alındığı numara
    double fiyat = 0; // toplam fiyatın tutulduğu değişken

    while (1) // siparişin alındığı sonsuz döngü 
    {

        cout << "Sipariş vermek istediğiniz içecek veya yiyeceğin başındaki numarayı veya ödeme için 0' ı girin: ";
        cin >> siparis_no;
        cout << endl;
        try
        {
            if (siparis_no >= 0 && siparis_no < 10)
            {

                switch (siparis_no) // sipariş işlemlerinin yapıldığı yapı 
                {
                case 1:
                {
                    double kahve;
                    bool onay = 1;
                    int tane = 0;
                    while (onay != 0)
                    {
                        cout << "Kaç tane " << s1 << ":";
                        cin >> tane;
                        kahve = Urun.fiyat[0] * tane; // fiyatın hesaplandığı işlem
                        cout << tane << " tane " << s1 << ": " << kahve << "TL" << endl;
                        fiyat += kahve; // kahve ücreti en son ödenecek ücretin belirlendiği fiyat değişkenine ataması yapılıyor
                        cout << "Toplam ücret:" << fiyat << "TL" << endl
                             << endl;
                        cout << "Siparişte hata olduğunu düşünüyorsanız 1' e siparişe devam etmek veya ödeme için 0' a basın:";
                        cin >> onay;
                        cout << endl;
                        if (onay == 1) // hata olması durumunda kahvenin fiyatını toplam ücretten düşen kod
                        {
                            fiyat -= kahve;
                        }
                    }
                    break;
                }
                case 2:
                {
                    double cay;
                    bool onay = 1;
                    int tane = 0;
                    while (onay != 0)
                    {
                        cout << "Kaç tane " << s2 << ":";
                        cin >> tane;
                        cay = Urun.fiyat[1] * tane;
                        cout << tane << " tane " << s2 << ": " << cay << "TL" << endl;
                        fiyat += cay;
                        cout << "Toplam ücret:" << fiyat << "TL" << endl;
                        cout << endl
                             << endl;
                        cout << "Siparişte hata olduğunu düşünüyorsanız 1'e siparişe devam etmek için 0' a basın:";
                        cin >> onay;
                        cout << endl;
                        if (onay == 1)
                        {
                            fiyat -= cay;
                        }
                    }
                    break;
                }
                case 3:
                {
                    double s_cay;
                    bool onay = 1;
                    int tane = 0;
                    while (onay != 0)
                    {
                        cout << "Kaç tane " << s3 << ":";
                        cin >> tane;
                        s_cay = Urun.fiyat[2] * tane;
                        cout << tane << " tane " << s3 << ": " << s_cay << "TL" << endl;
                        fiyat += s_cay;
                        cout << "Toplam ücret:" << fiyat << "TL" << endl;
                        cout << endl
                             << endl;
                        cout << "Siparişte hata olduğunu düşünüyorsanız 1'e siparişe devam etmek için 0' a basın:";
                        cin >> onay;
                        cout << endl;
                        if (onay == 1)
                        {
                            fiyat -= s_cay;
                        }
                    }
                    break;
                }
                case 4:
                {
                    double c_kek;
                    bool onay = 1;
                    int tane = 0;
                    while (onay != 0)
                    {
                        cout << "Kaç tane " << s4 << ":";
                        cin >> tane;
                        c_kek = Urun.fiyat[3] * tane;
                        cout << tane << " tane " << s4 << ": " << c_kek << "TL" << endl;
                        fiyat += c_kek;
                        cout << "Toplam ücret:" << fiyat << "TL" << endl;
                        cout << endl
                             << endl;
                        cout << "Siparişte hata olduğunu düşünüyorsanız 1'e siparişe devam etmek için 0' a basın:";
                        cin >> onay;
                        cout << endl;
                        if (onay == 1)
                        {
                            fiyat -= c_kek;
                        }
                    }
                    break;
                }
                case 5:
                {
                    double m_kek;
                    bool onay = 1;
                    int tane = 0;
                    while (onay != 0)
                    {
                        cout << "Kaç tane " << s5 << ":";
                        cin >> tane;
                        m_kek = Urun.fiyat[4] * tane;
                        cout << tane << " tane " << s5 << ": " << m_kek << "TL" << endl;
                        fiyat += m_kek;
                        cout << "Toplam ücret:" << fiyat << "TL" << endl;
                        cout << endl
                             << endl;
                        cout << "Siparişte hata olduğunu düşünüyorsanız 1'e siparişe devam etmek için 0' a basın:";
                        cin >> onay;
                        cout << endl;
                        if (onay == 1)
                        {
                            fiyat -= m_kek;
                        }
                    }
                    break;
                }
                case 6:
                {
                    double sobiyet;
                    bool onay = 1;
                    int tane = 0;
                    while (onay != 0)
                    {
                        cout << "Kaç tane " << s6 << ":";
                        cin >> tane;
                        sobiyet = Urun.fiyat[5] * tane;
                        cout << tane << " tane " << s6 << ": " << sobiyet << "TL" << endl;
                        fiyat += sobiyet;
                        cout << "Toplam ücret:" << fiyat << "TL" << endl;
                        cout << endl
                             << endl;
                        cout << "Siparişte hata olduğunu düşünüyorsanız 1'e siparişe devam etmek için 0' a basın:";
                        cin >> onay;
                        cout << endl;
                        if (onay == 1)
                        {
                            fiyat -= sobiyet;
                        }
                    }
                    break;
                }

                case 7:
                {
                    double f_baklava;
                    bool onay = 1;
                    int tane = 0;
                    while (onay != 0)
                    {
                        cout << "Kaç tane " << s7 << ":";
                        cin >> tane;
                        f_baklava = Urun.fiyat[6] * tane;
                        cout << tane << " tane " << s7 << ": " << f_baklava << "TL" << endl;
                        fiyat += f_baklava;
                        cout << "Toplam ücret:" << fiyat << "TL" << endl;
                        cout << endl
                             << endl;
                        cout << "Siparişte hata olduğunu düşünüyorsanız 1'e siparişe devam etmek için 0' a basın:";
                        cin >> onay;
                        cout << endl;
                        if (onay == 1)
                        {
                            fiyat -= f_baklava;
                        }
                    }
                    break;
                }
                case 8:
                {
                    double f_sarma;
                    bool onay = 1;
                    int tane = 0;
                    while (onay != 0)
                    {
                        cout << "Kaç tane " << s8 << ":";
                        cin >> tane;
                        f_sarma = Urun.fiyat[7] * tane;
                        cout << tane << " tane " << s8 << ": " << f_sarma << "TL" << endl;
                        fiyat += f_sarma;
                        cout << "Toplam ücret:" << fiyat << "TL" << endl;
                        cout << endl
                             << endl;
                        cout << "Siparişte hata olduğunu düşünüyorsanız 1'e siparişe devam etmek için 0' a basın:";
                        cin >> onay;
                        cout << endl;
                        if (onay == 1)
                        {
                            fiyat -= f_sarma;
                        }
                    }
                    break;
                }
                case 9:
                {
                    double karisik;
                    bool onay = 1;
                    int tane = 0;
                    while (onay != 0)
                    {
                        cout << "Kaç tane " << s9 << ":";
                        cin >> tane;
                        karisik = Urun.fiyat[8] * tane;
                        cout << tane << " tane " << s9 << ": " << karisik << "TL" << endl;
                        fiyat += karisik;
                        cout << "Toplam ücret:" << fiyat << "TL" << endl;
                        cout << endl
                             << endl;
                        cout << "Siparişte hata olduğunu düşünüyorsanız 1' e siparişe devam etmek için 0' a basın:";
                        cin >> onay;
                        cout << endl;
                        if (onay == 1)
                        {
                            fiyat -= karisik;
                        }
                    }
                    break;
                }
                }
                musteri1.set_price(fiyat); // private değişkene atama yapan method. 
                cout << endl
                     << endl;
                if (siparis_no == 0) // sonsuz döngüyü kıran koşul
                {
                    break;
                }
            }
            else
            {
                throw siparis_no;
            }
        }
        catch (int hata) // ürün numaralarından başka (geçersiz)bir numara girildiğinde ekrana hata basılmasını sağlayan yapı
        {
            cout << hata << " Numarada tanımlı bir işlem bulunamadı... :( " << endl
                 << endl;
        }
    }
}
void Fatura()   // toplam ödenecek ücreti ekrana basan method
{
    cout << setw(10) << " *** Faturanız *** " << setw(10) << endl; 

    musteri1.borc();
}