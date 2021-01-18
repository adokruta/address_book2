#ifndef PLIZZADRESATAMI_H
#define PLIZZADRESATAMI_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <windows.h>

#include "Adresat.h"
#include "MetodyPomocnicze.h"
#include "UzytkownikMeneger.h"
#include "AdresatMeneger.h"

using namespace std;

class PlikZAdresatami
{
     friend class UzytkownikMeneger;
     string nazwaPlikuZAdresatami;
     Adresat pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami);
     bool czyPlikJestPusty(fstream &plikTekstowy);
     string zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat);
     Adresat adresat;
     MetodyPomocnicze metodyPomocnicze;


     int pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
     int pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);

 public:

     PlikZAdresatami();
     //int wczytajAdresatowZalogowanegoUzytkownikaZPliku();
     void dopiszAdresataDoPliku(Adresat adresat);

};

#endif
