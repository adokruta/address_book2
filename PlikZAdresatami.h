#ifndef PLIZZADRESATAMI_H
#define PLIZZADRESATAMI_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <windows.h>

#include "Adresat.h"
#include "MetodyPomocnicze.h"

using namespace std;

class PlikZAdresatami
{
     const string NAZWA_PLIKU_Z_ADRESATAMI;
     int idOstatniegoAdresata;

     Adresat pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami);
     bool czyPlikJestPusty(fstream &plikTekstowy);
     string zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat);

     MetodyPomocnicze metodyPomocnicze;
     int pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
     int pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);

 public:

     PlikZAdresatami(string nazwaPlikuZAdresatami) : NAZWA_PLIKU_Z_ADRESATAMI (nazwaPlikuZAdresatami){
     idOstatniegoAdresata = 0;
     };

     bool dopiszAdresataDoPliku(Adresat adresat);
     vector <Adresat>  wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika);
     int pobierzIdOstateniegoAdresata();

};

#endif
