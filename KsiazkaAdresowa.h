#ifndef KSIAZKAADRESOWA_H
#define KSIAZKAADRESOWA_H

#include <iostream>

#include "UzytkownikMeneger.h"
#include "MetodyPomocnicze.h"

using namespace std;

class KsiazkaAdresowa
{
    UzytkownikMeneger uzytkownikMeneger;
    MetodyPomocnicze metodyPomocnicze;

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
