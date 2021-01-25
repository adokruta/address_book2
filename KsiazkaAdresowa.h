#ifndef KSIAZKAADRESOWA_H
#define KSIAZKAADRESOWA_H

#include <iostream>

#include "UzytkownikMeneger.h"
#include "MetodyPomocnicze.h"
#include "AdresatMeneger.h"

using namespace std;

class KsiazkaAdresowa
{
    UzytkownikMeneger uzytkownikMeneger;
    MetodyPomocnicze metodyPomocnicze;
    AdresatMeneger *adresatMeneger;
    const string NAZWA_PLIKU_Z_ADRESATAMI;

public:
    KsiazkaAdresowa(string nazwaPlikuZUzytkownikami, string nazwaPlikuZAdresatami)
        : uzytkownikMeneger(nazwaPlikuZUzytkownikami), NAZWA_PLIKU_Z_ADRESATAMI(nazwaPlikuZAdresatami)
    {
        adresatMeneger = NULL;
    };
    ~ KsiazkaAdresowa()
    {
        delete adresatMeneger;
        adresatMeneger = NULL;
    }
    void rejestracjaUzytkownika();
    void logowanieUzytkownika();
    void wylogujUzytkownika();
    void dodajAdresata();
    bool czyUzytkownikJestZalogowany();
    void wyswietlAdresatowZalogowanegoUzytkownika();
    void zmianaHaslaZalogowanegoUzytkownika();
    void usunAdresata();

};

#endif
