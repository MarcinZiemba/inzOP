#include <iostream>
#include <string>
#include <vector>
#include <fstream> 

class Produkt {
public:
    int id_produktu;
    int id_uzytkownika;
    std::string nazwa;
    int ilosc;                // Nowe pole
    std::string data_waznosci; // Nowe pole

    // Konstruktor klasy
    Produkt(){}
    
    Produkt(int _id_u, int _id_p, const std::string& _nazwa,  int _ilosc, const std::string& _data_waznosci)
        : id_produktu(_id_p), id_uzytkownika(_id_u), nazwa(_nazwa),  ilosc(_ilosc), data_waznosci(_data_waznosci) {
        // Dodatkowe inicjalizacje, jeśli są potrzebne
    }

    // Metoda do wyświetlania informacji o produkcie
    void wyswietlInformacje() const {
        std::cout << "ID_uzytkownika: " << id_uzytkownika << "\n";
        std::cout << "ID_produktu: " << id_produktu << "\n";
        std::cout << "Nazwa: " << nazwa << "\n";
        std::cout << "Ilosc: " << ilosc << "\n";
        std::cout << "Data waznosci: " << data_waznosci << "\n";
    }

    void zapiszDoStrumienia(std::ostream& strumien) const {
        strumien << id_uzytkownika << " " << id_produktu << " " << nazwa << " " << ilosc << " " << data_waznosci << "\n";
    }
};

void zapiszProduktyDoPliku(const std::vector<Produkt>& produkty, const std::string& nazwaPliku) {
    std::ofstream plik(nazwaPliku);

    if (plik.is_open()) {
        for (const Produkt& produkt : produkty) {
            produkt.zapiszDoStrumienia(plik);
        }

        plik.close();
        std::cout << "Produkty zapisane do pliku: " << nazwaPliku << std::endl;
    } else {
        std::cerr << "Nie można otworzyć pliku do zapisu." << std::endl;
    }
}

std::vector<Produkt> wczytajProduktyZPliku(const std::string& nazwaPliku) {
    std::vector<Produkt> produkty;
    std::ifstream plik(nazwaPliku);

    if (plik.is_open()) {
        int id_uzytkownika, id_produktu;
        std::string nazwa;
        int ilosc;
        std::string data_waznosci;

        while (plik >> id_uzytkownika >> id_produktu >> nazwa >> ilosc >> data_waznosci) {
            Produkt produkt(id_uzytkownika, id_produktu, nazwa, ilosc, data_waznosci);
            produkty.push_back(produkt);
        }

        plik.close();
        std::cout << "Produkty wczytane z pliku: " << nazwaPliku << std::endl;
    } else {
        std::cerr << "Nie można otworzyć pliku do odczytu." << std::endl;
    }

    return produkty;
}

class Lodowka  {
public:
    // Pola klasy Lodowka
    std::vector<Produkt> produkty;
    int id_lodowki;

    // Konstruktor klasy Lodowka
    Lodowka(int _id_lodowki) : id_lodowki(_id_lodowki) {}

    // Metoda do dodawania produktu do lodówki
    void dodajProdukt(const Produkt& produkt) {
        produkty.push_back(produkt);
    }

    // Metoda do wyświetlania informacji o lodówce
    void wyswietlZawartoscLodowki() const {
        std::cout << "------------------------\n";
        std::cout << "ID Lodowki: " << id_lodowki << "\n";
        std::cout << "Zawartosc lodowki:\n";
        for (const auto& produkt : produkty) {
            produkt.wyswietlInformacje();
            std::cout << "------------------------\n";
        }
    }
};

