#ifndef PLIZZUZYTKOWNIKAMI_H
#define PLIZZUZYTKOWNIKAMI_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

#include "Uzytkownik.h"
#include "MetodyPomocnicze.h"

using namespace std;

class PlikZUzytkownikami
{
     const string NAZWA_PLIKU_Z_UZYTKOWNIKAMI;
     string zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(Uzytkownik uzytkownik);
     bool czyPlikJestPusty(fstream &plikTekstowy);
     Uzytkownik pobierzDaneUzytkownika(string daneJednegoUzytkownikaOddzielonePionowymiKreskami);


 public:

     PlikZUzytkownikami(string NAZWAPLIKUZUZYTKOWNIKAMI): NAZWA_PLIKU_Z_UZYTKOWNIKAMI(NAZWAPLIKUZUZYTKOWNIKAMI){};
     vector<Uzytkownik>  wczytajUzytkownikowZPliku();
     void dopiszUzytkownikaDoPliku(Uzytkownik uzytkownik);
     void zapiszWszystkichUzytkownikowDoPliku(vector <Uzytkownik> &uzytkownicy);
};

#endif
