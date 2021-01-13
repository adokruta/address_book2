#ifndef ADRESATMENEGER_H
#define ADRESATMENEGER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>

#include "Adresat.h"
#include "PlikZAdresatami.h"
#include "MetodyPomocnicze.h"

using namespace std;

class AdresatMeneger
{
    int idZalogowanegoUzytkownika;



    MetodyPomocnicze metodyPomocnicze;

    Adresat podajDaneNowegoAdresata();

    public:

    int dodajAdresata();
    vector <Adresat> adresaci;
    int idOstatniegoAdresata;




    //void rejestracjaUzytkownika();
   // void wypiszWszystkichUzytkownikow();
    //void wczytajUzytkownikowZPliku();
   /// int logowanieUzytkownika ();
   // void ustawIdZalogowanegoUzytkownika();
    //int pobierzIdZalogowanegoUzytkownika();

};

#endif

