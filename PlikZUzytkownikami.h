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
     string nazwaPlikuZUzytkownikami;

     string zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(Uzytkownik uzytkownik);
     bool czyPlikJestPusty();
     Uzytkownik pobierzDaneUzytkownika(string daneJednegoUzytkownikaOddzielonePionowymiKreskami);

 public:
     PlikZUzytkownikami(string NAZWAPLIKUZUZYTKOWNIKAMI): nazwaPlikuZUzytkownikami(NAZWAPLIKUZUZYTKOWNIKAMI){};
     vector<Uzytkownik>  wczytajUzytkownikowZPliku();
     void dopiszUzytkownikaDoPliku(Uzytkownik uzytkownik);
};

#endif
