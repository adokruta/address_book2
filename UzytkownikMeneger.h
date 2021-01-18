#ifndef UZYTKOWNIKMENEGER_H
#define UZYTKOWNIKMENEGER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>

#include "Uzytkownik.h"
#include "PlikZUzytkownikami.h"
#include "MetodyPomocnicze.h"
#include "AdresatMeneger.h"
#include "PlikZAdresatami.h"

using namespace std;

class UzytkownikMeneger
{
    friend class KsiazkaAdresowa;
    friend class AdresatMeneger;

    int idZalogowanegoUzytkownika;
    vector <Uzytkownik> uzytkownicy;
    vector <Adresat> adresaci;
    PlikZUzytkownikami plikZUzytkownikami;
    MetodyPomocnicze metodyPomocnicze;
    Uzytkownik zalogowanyUzytkownik;

    Uzytkownik podajDaneNowegoUzytkownika();
    int pobierzIdNowegoUzytkownika();
    bool czyIstniejeLogin(string login);
    void wyswietlDaneAdresata(Adresat adresat);
    void zmianaHaslaZalogowanegoUzytkownika();

public:

    UzytkownikMeneger(string nazwaPlikuZUzytkownikami) :  plikZUzytkownikami(nazwaPlikuZUzytkownikami){};

    void rejestracjaUzytkownika();
    void wypiszWszystkichUzytkownikow();
    void wczytajUzytkownikowZPliku();
    int logowanieUzytkownika ();
    void ustawIdZalogowanegoUzytkownika();
    int pobierzIdZalogowanegoUzytkownika();
    int wczytajAdresatowZalogowanegoUzytkownikaZPliku();
    void wyswietlAdresatowZalogowanegoUzytkownika();

};

#endif
