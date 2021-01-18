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
    AdresatMeneger adresatMeneger;
    PlikZAdresatami plikZAdresatami;
    int idZalogowanegoUzytkownika;


public:
    KsiazkaAdresowa(string nazwaPlikuZUzytkownikami) : uzytkownikMeneger(nazwaPlikuZUzytkownikami){
    uzytkownikMeneger.wczytajUzytkownikowZPliku();
    idZalogowanegoUzytkownika = 0;
    };
    void rejestracjaUzytkownika();
    void wypiszWszystkichUzytkownikow();
    void logowanieUzytkownika();
    void wyswietlMenu();


};

#endif
