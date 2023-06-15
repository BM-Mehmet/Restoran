#include "kullanici.hpp"
kulanicilar musteri;
int main()
{
    // müşteri bilgilerini saklamak için bazı değişkenler tanımladık
    string customer = "Müşteri ";
    string customerName = musteri.kullanici_name;
    string customerSurname = musteri.kullanici_username;
    string customerphone = musteri.kullanici_phone; // buraya kadar
    fstream kayit;
    fstream gecici; // kayıt ve geçici adında iki akış nesnesi tanımladık
    urun Urun;
    char name[maximum];
    char u_name[maximum];
    //  urun_list();
    Urun.fiyat_belirle();
    urun_list();
    int i = 1;
    bool sec; // kullanıcıya admin mi yoksa kullanıcı mı seçeneği sunmak için değişken atanır
    cout << "Kullanıcı paneli için 1 admin paneli için 0 girin: ";
    cin >> sec; // panel seçimi
    do
    {
        if (sec == 1) // kullanıcı seçilmesi durumunda çalışacak olan if komutu
        {
            kayit.open("datalar\\musteri_list.txt", ios::app); // kullanıcı paneli seçilirse müşteri listesini açması komutu
            if (kayit.is_open())
            { // kullanıcı verilerini alacak komut dizileri aşağıda sıralandı

                cin.ignore(); // önceki girişten geriye kalan bir karakteri atlar

                // müşteri bilgilerinin girilmesi ve geçerlilik kontrolü
                bool n_kontrol = 1;
                while (n_kontrol)
                {
                    cout << customer << "adı: ";
                    cin.getline(name, maximum);
                    customerName = name;
                    if (customerName.size() > 2)
                    {
                        break;
                    }
                    else
                    {
                        cout << "Lütfen geçerli bir isim girin!" << endl;
                    }
                }

                bool s_kontrol = 1;
                while (s_kontrol)
                {
                    cout << customer << "soyadı: ";
                    cin.getline(u_name, maximum);
                    customerSurname = u_name;

                    if (customerSurname.size() > 1)
                    {
                        break;
                    }
                    else
                    {
                        cout << "Lütfen geçerli bir soyad girin!" << endl;
                    }
                }

                bool p_kontrol = 1;
                while (p_kontrol)
                {
                    cout << customer << "Telefonu: +90";
                    cin >> customerphone;
                    if (customerphone.size() == 10)
                    {
                        if (customerphone[0] == '5')
                        {
                            break;
                        }
                    }
                    else
                    {
                        cout << "Lütfen geçerli bir telefon girin!" << endl;
                    }
                }
                cout << endl
                     << endl;
                kayit << endl
                      << customerName << setw(30) << customerSurname << setw(30) << customerphone; // kayıt akış nesnesinin içerisine girilen bilgilerin ,
                      //30 ar karakter boyutunda boşlık bırakılarak yazdırılması
                cout << "*** Kullanıcı panelindesiniz ***" << endl // Panel düzeni için başlık ataması yapıldı
                     << endl;
                urun_list(); // ürün listesini, müşterileri, siparişleri ve faturaları görüntüleme seçeneklerini sunar.
                Musteriler();
                siparis();
                Fatura();
                cout << "Müşteri adi: " << customerName << endl;
                cout << "Müşteri soyadi: " << customerSurname << endl; // müşteri adını soyadını ekrana yazdırır
                kayit.close();                                         // kayıt kapanır
            }
        }
        if (sec == 0) // admin sayfası
        {
            string k_ad, k_sifre; // kullanıcı adı ve şifre tanımlar
            cout << "Kullanıcı adını girin: ";
            cin >> k_ad;
            cout << "Şifreyi girin: ";
            char ch;

            while (true)
            {
                ch = getch();
                if (ch == '\r') // Enter tuşuna basıldığında döngüyü sonlandır
                    break;
                else if (ch == '\b')
                { // Backspace tuşuna basıldığında
                    if (!k_sifre.empty())
                    {                         // Şifre boş değilse
                        k_sifre.pop_back();   // Son karakteri kaldır
                        std::cout << "\b \b"; // Konsolda son karakteri sil
                    }
                }
                else
                {
                    k_sifre += ch;
                    std::cout << "*";
                }
            }

            if (musteri.user == k_ad && musteri.password == k_sifre)
            { // eğer kullanıcı adı ve şifre doğru girilmişse if döngüsünün içerisine girilir

                cout << "\n*** Admin panelindesiniz *** " << endl
                     << endl;
                int control = 1; // Admin olarak yapılacak işlemlerin alındığı değişken.
                while (control > 0)
                {
                    cout << "Müşteri işlemleri için 1 ürün işlemleri için 2 çıkmak için 0 girin:";
                    cin >> control; // Yapılacak işlem seçiliyor
                    if (control == 1)
                    {
                        string phone_control; // Adminden alınacak telefon
                        cout << "Üzerinde işlem yapmak istediğiniz müşteri Telefonunu girin: ";
                        cin >> phone_control;                             // Adminden telefon alınıyor
                        kayit.open("datalar\\musteri_list.txt", ios::in); // kayit akış nesnesini okuma modunda açıyoruz

                        while (!(kayit.eof())) // akış nesnesinin sonuna gelen kadar çalışan döngü

                        {
                            kayit >> customerName >> customerSurname >> customerphone; // kayıt akış nesnesi içerisindeki bir satırı okur

                            if (phone_control == customerphone) // girilen telefon numarasının kayıtlı olup olmadığı kontrol edilir
                            {
                                kayit.close();
                                cout << " Kullanıcı bilgilerini güncellemek için 1 kullanıcıyı silmek için 0 girin: ";
                                int SECİM;
                                cin >> SECİM;
                                if (SECİM == 1)
                                {
                                    kayit.open("datalar\\musteri_list.txt", ios::in);
                                    gecici.open("datalar\\gecici.txt", ios::app); // gecici akış nesnesini ekleme modunda açıyoruz
                                    while (!(kayit.eof()))
                                    {
                                        kayit >> customerName >> customerSurname >> customerphone;
                                        if (phone_control == customerphone)
                                        { // kullanıcının tekrar bilgileri alınıyor.
                                            cin.ignore();
                                            cout << customer << "adı: ";
                                            cin.getline(name, maximum);
                                            cout << customer << "soyadı: ";
                                            cin.getline(u_name, maximum);
                                            customerName = name;
                                            customerSurname = u_name;
                                            cout << customer << "Telefonu: ";
                                            cin >> customerphone;
                                            gecici << endl // yeni müşteri gecici dosyasına ekleniyor
                                                   << customerName << setw(30) << customerSurname << setw(30) << customerphone;
                                        }
                                        else // diğer kullanıcılar silinmesin diye gecici dosyasına ekleniyor.
                                        {
                                            gecici << endl
                                                   << customerName << setw(30) << customerSurname << setw(30) << customerphone;
                                        }
                                    }
                                    kayit.close();
                                    gecici.close();
                                    remove("datalar\\musteri_list.txt");
                                    rename("datalar\\gecici.txt", "datalar\\musteri_list.txt");
                                }
                                if (SECİM == 0) // kullanıcı sime işemi yapılıyor
                                {
                                    kayit.open("datalar\\musteri_list.txt", ios::in);
                                    gecici.open("datalar\\gecici.txt", ios::app);
                                    while (!(kayit.eof()))
                                    {
                                        kayit >> customerName >> musteri.kullanici_username >> customerphone;
                                        if (phone_control == customerphone)
                                        { // telefon numarası eşleştşğinde else bloğuna girip gecici sosyasına yazılmadığı için silinmiş olacak
                                            cout << "Kullanıcı silindi\n";
                                        }
                                        else
                                        {
                                            gecici << endl
                                                   << customerName << setw(30) << musteri.kullanici_username << setw(30) << customerphone;
                                        }
                                    }
                                    kayit.close();
                                    gecici.close();
                                    remove("datalar\\musteri_list.txt");
                                    rename("datalar\\gecici.txt", "datalar\\musteri_list.txt");
                                }
                            }
                        }
                    }
                    if (control == 2)
                    { // ürün fiyat değiştirme işlemleri yapılıyor
                        Urun.urunler();
                        urun_list();
                    }
                }
            }
            else
            {
                cout << "\nKullanıcı adı veya şifre hatalı." << endl;
            }
        }
        i++;
        cout << "Çıkmak için 0 devam etmek için 1 girin: ";
        cin >> i;
    } while (i > 0);

    return 0;
}