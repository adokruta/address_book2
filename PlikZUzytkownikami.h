#ifndef PLIZZUZYTKOWNIKAMI_H
#define PLIZZUZYTKOWNIKAMI_H

#include <iostream>
#include <vector>
#include <fstream>

#include "Uzytkownik.h"
#include "MetodyPomocnicze.h"

using namespace std;

class PlikZUzytkownikami
{
     string nazwaPlikuZUzytkownikami;
     string zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(Uzytkownik uzytkownik);
     fstream plikTekstowy;
     bool czyPlikJestPusty();

 public:
     PlikZUzytkownikami();
     void dopiszUzytkownikaDoPliku(Uzytkownik uzytkownik);
};

#endif
