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


public:
    KsiazkaAdresowa(string nazwaPlikuZUzytkownikami) : uzytkownikMeneger(nazwaPlikuZUzytkownikami){
    uzytkownikMeneger.wczytajUzytkownikowZPliku();
    };
    void rejestracjaUzytkownika();
    void wypiszWszystkichUzytkownikow();
    void logowanieUzytkownika();
    void wyswietlMenu();


};

#endif
