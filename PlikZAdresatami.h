#ifndef PLIKZADRESATAMI_H
#define PLIKZADRESATAMI_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <windows.h>

#include "Adresat.h"
#include "MetodyPomocnicze.h"
#include "PlikTekstowy.h"

using namespace std;

class PlikZAdresatami : public PlikTekstowy

{
     int idOstatniegoAdresata;

     Adresat pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami);
     string zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat);

     MetodyPomocnicze metodyPomocnicze;
     int pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
     int pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
     int pobierzIdOstatniegoAdresata();
     void edytujWybranaLinieWPliku(string liniaZDanymiAdresataOddzielonePionowymiKreskami);

 public:

     PlikZAdresatami(string nazwaPliku) : PlikTekstowy (nazwaPliku){
     idOstatniegoAdresata = pobierzIdOstatniegoAdresata();
     };

     bool dopiszAdresataDoPliku(Adresat adresat);
     vector <Adresat>  wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika);
     int zwrocIdOstatniegoAdresata ();
     void usunWybranaLinieWPliku(int idUsuwanegoAdresata);
     void zaktualizujDaneWybranegoAdresata(Adresat adresat);

};

#endif
