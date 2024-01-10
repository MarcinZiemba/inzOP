#include <iostream>
#include <fstream>
#include "lodowka.cpp"
using namespace std;

int wybor;
Lodowka lodowka_uzytkownika(111);
int id_uzytkownika = 1;
int id_produktu = 1;
string nazwa_produktu, data_waznosci;
int ilosc;
Produkt produkt_bufor(id_uzytkownika,0,"",0,"");


int main(){
    cout<<"------------------- \n";
    cout<<"Wczytywanie produktow... \n";
    vector<Produkt> wczytaneProdukty = wczytajProduktyZPliku("produkty.txt");
    vector<Produkt> doZapisu = wczytaneProdukty;
    
    for (const auto& produkt : wczytaneProdukty) {
            if(produkt.id_uzytkownika == id_uzytkownika){
                lodowka_uzytkownika.dodajProdukt(produkt);
            }
    }
    id_produktu = wczytaneProdukty[wczytaneProdukty.size()-1].id_produktu +1;        
    cout<<"Witaj w twojej lodowce!\n";

    while(true){

    cout<<"\nWybierz opcje: ";
    cout<<"\n1.Dodaj produkt do lodowki";
    cout<<"\n2.Wyswietl zawartosc lodowki";
    cout<<"\n3.Wyjscie z programu.";
    cin>>wybor;
    switch(wybor){

        case 1: 
            cout<<"Podaj dane produktu: \n";
            cout<<"Podaj nazwe produktu: ";
            cin>>nazwa_produktu;
            cout<<"Podaj ilosc produktu: ";
            cin>>ilosc;
            cout<<"Podaj date_waznosci produktu: ";
            cin>>data_waznosci;
            produkt_bufor.nazwa = nazwa_produktu;
            produkt_bufor.id_produktu = id_produktu;
            produkt_bufor.ilosc = ilosc;
            produkt_bufor.data_waznosci = data_waznosci;
            lodowka_uzytkownika.dodajProdukt(produkt_bufor);
            doZapisu.push_back(produkt_bufor);
            cout<<"\nUdalo sie dodac produkt!";
            id_produktu++;
        break;

        case 2: 
            lodowka_uzytkownika.wyswietlZawartoscLodowki();
            break;

        case 3: 
            zapiszProduktyDoPliku(doZapisu, "produkty.txt");
            exit(0); 
            break;

        default:
            cout<<"Nie ma takiej opcji ;)";
            break;
    }
}


    return 0;
}